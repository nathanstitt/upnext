#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lvgl.h"
#include "ui/ui.h"
#include "upnext_config.h"
#include "display.hpp"
#include "esp_vfs_dev.h"
#include "driver/uart.h"
#include "network.h"
#include "calendar_ui.h"
#include "weather_ui.h"


esp_err_t configure_stdin_stdout(void) {
    static bool configured = false;
    if (configured) {
      return ESP_OK;
    }
    // Initialize VFS & UART so we can use std::cout/cin
    setvbuf(stdin, NULL, _IONBF, 0);
    /* Install UART driver for interrupt-driven reads and writes */
    ESP_ERROR_CHECK( uart_driver_install( (uart_port_t)CONFIG_ESP_CONSOLE_UART_NUM,
            256, 0, 0, NULL, 0) );
    /* Tell VFS to use UART driver */
    esp_vfs_dev_uart_use_driver(CONFIG_ESP_CONSOLE_UART_NUM);
    esp_vfs_dev_uart_port_set_rx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CR);
    /* Move the caret to the beginning of the next line on '\n' */
    esp_vfs_dev_uart_port_set_tx_line_endings(CONFIG_ESP_CONSOLE_UART_NUM, ESP_LINE_ENDINGS_CRLF);
    configured = true;
    return ESP_OK;
}

static const uint16_t screenWidth  = 320; // 480;
static const uint16_t screenHeight = 480; // 320;
static lv_disp_draw_buf_t draw_buf;
static const auto displayBuffSize = screenWidth * screenHeight / 5 ;
static lv_color_t buf[ displayBuffSize ];
static LGFX *lcd;

static Network *network;



// CalendarUI *calendar_ui;
// WeatherUI *weather_ui;

void disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );

  lcd->startWrite();
  lcd->setAddrWindow( area->x1, area->y1, w, h );
  lcd->writePixels((lgfx::rgb565_t *)&color_p->full, w * h);
  lcd->endWrite();

  lv_disp_flush_ready( disp );
}

/* Creates a semaphore to handle concurrent call to lvgl stuff
 * If you wish to call *any* lvgl function from other threads/tasks
 * you should lock on the very same semaphore! */
SemaphoreHandle_t xGuiSemaphore;

static void guiTask(void *pvParameter) {
    (void)pvParameter;
    xGuiSemaphore = xSemaphoreCreateMutex();


    lv_init();

    lv_disp_draw_buf_init( &draw_buf, &buf, NULL, displayBuffSize );

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init( &disp_drv );
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register( &disp_drv );

    ui_init();

    lv_obj_t* screen = lv_scr_act();

    // calendar_ui->setup(screen);
    // weather_ui->setup(screen);

    auto calendar = new CalendarUI(network);
    auto weather = new WeatherUI(network);

    // touchscreen
    // static lv_indev_drv_t indev_drv;
    // lv_indev_drv_init( &indev_drv );
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // lv_indev_drv_register( &indev_drv );


    while (1) {
        vTaskDelay(pdMS_TO_TICKS(10));

        if (pdTRUE == xSemaphoreTake(xGuiSemaphore, portMAX_DELAY)) {
            calendar->tick();
            weather->tick();
            lv_task_handler();
            xSemaphoreGive(xGuiSemaphore);
        }


        // calendar_ui->tick();
        // weather_ui->tick();
    }
}


extern "C" void app_main(void) {

    //buf = static_cast<lv_color_t*>(malloc(screenWidth * screenHeight / 5));

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    configure_stdin_stdout();

    setenv("TZ", TIMEZONE, 1);
    tzset();

    lcd = new LGFX();

    lcd->init();
    lcd->begin();

    network = new Network();
    network->init();

    xTaskCreatePinnedToCore(guiTask, "gui", 4096 * 2, NULL, 0, NULL, 1);

}
