#include "esp_http_client.h"
#include "sdkconfig.h"
#include "http_client.h"
#include <iostream>
#include <esp_log.h>

static const char *TAG = "HTTP";


static esp_err_t _http_event_handle(esp_http_client_event_t *evt) {

    HTTPClient *instance = static_cast<HTTPClient *>(evt->user_data);

    switch (evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGE(TAG, "HTTP_EVENT_ERROR");
            instance->had_error = true;
            instance->doneCB(instance);

            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:

           ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER: key=%s, value=%s", evt->header_key, evt->header_value);
           if (0 == strncmp("Location", evt->header_key, 8)) {
             instance->redirected_to = evt->header_value;
             instance->was_redirected = true;
           }
            break;
        case HTTP_EVENT_ON_DATA:
            instance->body.append((char*)evt->data, evt->data_len);
            ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH, redirected? %d", instance->was_redirected);

            if (instance->was_redirected) {
                instance->was_redirected = false;
                instance->body = "";
            } else {
                instance->doneCB(instance);
            }

            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGD(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
        default:
            ESP_LOGD(TAG, "UNKNOWN HTTP EVENT: %d", evt->event_id);
            break;
    }
    return ESP_OK;
}


HTTPClient::HTTPClient(const Callback &onDone) : doneCB(onDone) {
    ESP_LOGD(TAG, "HTTPClient(%p)", static_cast<void *>(this));
}


int HTTPClient::get(std::string &url) {

    exit_flag = 0;
    status_code = 0;
    esp_err_t err = ESP_OK;

    esp_http_client_config_t config = {};
    config.url = url.c_str();
    config.timeout_ms = this->timeout;
    config.user_data = this;
    config.max_redirection_count = 2;
    config.disable_auto_redirect = false;
    config.event_handler = _http_event_handle;
    if (this->ca_pem.size()) {
        config.cert_pem = this->ca_pem.c_str();
        config.cert_len = this->ca_pem.size();
    } else {
        config.skip_cert_common_name_check = true;
    }
    config.method = HTTP_METHOD_GET;
    config.transport_type = HTTP_TRANSPORT_OVER_SSL;

    esp_http_client_handle_t client = esp_http_client_init(&config);
    size_t s = sizeof(esp_http_client_handle_t);
    ESP_LOGD(TAG, "size of client is %d", s);

    err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        int length = -1;
        this->status_code = esp_http_client_get_status_code(client);
        length = esp_http_client_get_content_length(client);
        ESP_LOGI(TAG, "HTTP_FINISH status = %d, content_length = %d", this->status_code, length);
        esp_http_client_cleanup(client);
    } else {
        return 503; // Service Unavailable
    }

    return this->status_code;
}



HTTPClient::~HTTPClient() {
    ESP_LOGD(TAG, "~HTTPClient(%p)", static_cast<void *>(this));
}
