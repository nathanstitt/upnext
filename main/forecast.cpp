#include "forecast.h"

#include <ctime>
#include <time.h>
#include <iostream>
#include <fmt/format.h>
#include "esp_log.h"
static const char* daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

static const char *TAG = "fc";

void Forecast::update(const OW::Daily &forecast) {
    auto tm = std::tm {};

    localtime_r(&forecast.dt, &tm);

    auto wday = daysOfWeek[tm.tm_wday];

    lv_label_set_text(this->dow, wday);

    auto meteocon = forecast.condition().meteocon();

    if (meteocon) {
        lv_img_set_src(img, meteocon);
    }

    lv_label_set_text(hl, fmt::format("{}\n{}", forecast.highLow(), forecast.precip()).c_str());

  // char dt[10];

    // std::strftime(dt, sizeof(dt), "%e %b", std::localtime(&forecast.dt));
    // lv_label_set_text(this->date, dt);
    // auto weather = forecast.weather.begin();
    // if (weather != forecast.weather.end()) {
    //     auto img = weather->meteocon();
    //     if (img) {
    //         lv_img_set_src(this->img, img);
    //         lv_obj_clear_flag(this->img, LV_OBJ_FLAG_HIDDEN);
    //     } else {
    //         lv_obj_add_flag(this->img, LV_OBJ_FLAG_HIDDEN);
    //     }
    // }
    // auto temp = fmt::format("{:0.0f} {:0.0f}", forecast.temp.min, forecast.temp.max);
    // lv_label_set_text(this->hilo, temp.c_str());


    // auto pop = fmt::format("{:0.0f}%", forecast.pop * 100);
    // lv_label_set_text(this->precip, pop.c_str());
}

Forecast::Forecast(uint8_t indx, lv_obj_t *d, lv_obj_t *i, lv_obj_t *h)
    : index(indx), dow(d), img(i), hl(h) {
}
