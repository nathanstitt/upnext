#include "network.h"
#include <string>
#include <iostream>
#include "upnext_config.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_netif_sntp.h"
#include "http_client.h"

static EventGroupHandle_t s_wifi_event_group;


#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

static const char *TAG = "wifi";

static int s_retry_num = 0;


Network::Network() {}

const json ERROR = json::parse("{ \"error\": true }");

extern "C" {

    void init_time_sync();

}


void time_sync_notification_cb(struct timeval *tv) {
    ESP_LOGI("NTP", "Notification of a time synchronization event %lld", tv->tv_sec);
}

void init_time_sync() {
    ESP_LOGI(TAG, "Initializing SNTP");

    esp_sntp_config_t config = esp_sntp_config{};
    config.num_of_servers = 1;
    config.sync_cb = time_sync_notification_cb;
    config.start = true;                       // start SNTP service explicitly (after connecting)
    config.server_from_dhcp = true;             // accept NTP offers from DHCP server, if any (need to enable *before* connecting)
    config.renew_servers_after_new_IP = true;   // let esp-netif update configured SNTP server(s) after receiving DHCP lease
    config.index_of_first_server = 0;           // updates from server num 1, leaving server 0 (from DHCP) intact
    config.ip_event_to_renew = IP_EVENT_STA_GOT_IP;
    config.servers[0] = "pool.ntp.org";
    esp_netif_sntp_init(&config);

    ESP_LOGI(TAG, "SNTP poll started");
}


static void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        if (s_retry_num < CONFIG_WIFI_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }
        ESP_LOGI(TAG,"connect to the AP fail");
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);
    }
}

void Network::init() {

    std::cout << "start net init" << std::endl;

    s_wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_any_id));

    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &event_handler,
                                                        NULL,
                                                        &instance_got_ip));


    wifi_config_t wifi_config = {};
    strcpy((char*)wifi_config.sta.ssid, WIFI_SSID);
    strcpy((char*)wifi_config.sta.password, WIFI_PASS);
    wifi_config.sta.bssid_set = false;


    // wifi_config_t wifi_config = {
    //     .sta = {
    //         .ssid = WIFI_SSID,
    //         .password = WIFI_PASS,
    //         /* Authmode threshold resets to WPA2 as default if password matches WPA2 standards (pasword len => 8).
    //          * If you want to connect the device to deprecated WEP/WPA networks, Please set the threshold value
    //          * to WIFI_AUTH_WEP/WIFI_AUTH_WPA_PSK and set the password with length and format matching to
    //          * WIFI_AUTH_WEP/WIFI_AUTH_WPA_PSK standards.
    //          */
    //         .threshold.authmode = WIFI_AUTH_WPA_PSK, // ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD,
    //         .sae_pwe_h2e =  WPA3_SAE_PWE_BOTH,
    //         .sae_h2e_identifier = "", // EXAMPLE_H2E_IDENTIFIER,
    //     },
    // };
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
    ESP_ERROR_CHECK(esp_wifi_start() );

    ESP_LOGI(TAG, "wifi_init_sta finished.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
            WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
            pdFALSE,
            pdFALSE,
            portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s", WIFI_SSID,
                 WIFI_PASS);
        init_time_sync();
        vTaskDelay(200);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 WIFI_SSID, WIFI_PASS);
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }
}


HTTPClient::Callback onDoneCB(const char *call, const Network::Callback &onDone) {

    auto cb = [call, onDone](const HTTPClient *c) -> void {
        ESP_LOGI(TAG, "%s finished", call);
        if (c->had_error) {
            ESP_LOGE(TAG, "%s error %d", call, c->status_code);
            onDone(false, json());
        } else {
            ESP_LOGI(TAG, "%s\n%s", call, c->body.c_str());
//            ESP_LOGI(TAG, c->body.c_str());
            auto j = json::parse(c->body, nullptr, false);
            if (j.is_discarded()) {
                ESP_LOGE(TAG, "%s JSON parse error: %s", call, c->body.c_str());
                onDone(false, j);
            } else {
                onDone(true, j);
            }
        }
        delete c;
    };

    return cb;
}


void Network::fetchWeatherForecast(const Callback &onDone){

    auto client = new HTTPClient(onDoneCB("weather", onDone));

    std::string url("https://api.openweathermap.org/data/3.0/onecall?units=imperial&exclude=hourly,alerts&&lat=");
    url += LATITUDE;
    url += "&lon=";
    url += LONGITUDE;
    url += "&appid=";
    url += OPEN_WEATHER_API_KEY;

    client->get(url);
}



void Network::fetchCalendarEvents(const Callback &onDone) {
    auto client = new HTTPClient(onDoneCB("weather", onDone));

    std::string url("https://script.google.com/macros/s/");
    url += std::string(CALENDAR_DEPLOYMENT_ID) + "/exec";

    client->get(url);
}
