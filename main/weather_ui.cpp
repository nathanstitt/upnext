#include "forecast.h"
#include "lvgl.h"
#include "weather.h"
#include <chrono>
#include <string>
#include <time.h>
#include "weather_ui.h"
#include <iostream>
#include <fmt/format.h>
#include "esp_log.h"
#include "calendar.h"
#include "ui/ui.h"


static lv_coord_t ui_hourlyForecastChart_data[60];
lv_chart_series_t *ui_hourlyForecastChart_series;


static const char *TAG = "wth";


std::string WeatherUI::current_temp_degrees() const {
    auto deg = static_cast<int>(forecast.current.temp);
    return fmt::format("{}°", deg);
}


//static const char tickLabels[5][10];

//= {"now", "15mins", "30mins", "45mins", "60mins" };

static void draw_event_cb(lv_event_t *e) {

    lv_obj_draw_part_dsc_t *dsc =
        static_cast<lv_obj_draw_part_dsc_t *>(lv_event_get_param(e));
    if (dsc->part == LV_PART_TICKS && dsc->id == LV_CHART_AXIS_PRIMARY_X) {

      if (dsc->value == 0) {
          dsc->text = const_cast<char*>("now");
      } else {
        auto now = std::chrono::system_clock::now();

        auto mins = (dsc->value * 15);

        auto time = Cal::timeToStr(std::chrono::system_clock::to_time_t(now + std::chrono::minutes(mins)), false);


        lv_snprintf( dsc->text, dsc->text_length, "%s", const_cast<char*>( time.c_str() )); //tickLabels[dsc->value]);
      }
      }
}


WeatherUI::WeatherUI(Network *n)
    : network(n),
      last_poll(std::chrono::steady_clock::now() - std::chrono::hours(1)),
      last_update(last_poll) {

    forecasts.push_back(new Forecast(1, ui_futureDOW1, ui_futureCond1, ui_futureHL1));
    forecasts.push_back(new Forecast(2, ui_futureDOW2, ui_futureCond2, ui_futureHL2));
    forecasts.push_back(new Forecast(3, ui_futureDOW3, ui_futureCond3, ui_futureHL3));
    forecasts.push_back(new Forecast(4, ui_futureDOW4, ui_futureCond4, ui_futureHL4));

     static lv_style_t style_chart;
     lv_style_init(&style_chart);
     lv_obj_set_style_pad_column(ui_hourlyForecastChart, -1, 0);
     lv_obj_add_style(ui_hourlyForecastChart, &style_chart, LV_PART_MAIN);
     lv_obj_add_event_cb(ui_hourlyForecastChart, draw_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);



     ui_hourlyForecastChart_series =
         lv_chart_add_series(ui_hourlyForecastChart, lv_color_hex(0x00B620),
                             LV_CHART_AXIS_PRIMARY_Y);


     lv_chart_set_ext_y_array(ui_hourlyForecastChart, ui_hourlyForecastChart_series, ui_hourlyForecastChart_data );

};


const lv_img_dsc_t* WeatherUI::current_meteocon() const {
    if (forecast.current.weather.empty()) {
        return nullptr;
    }
    return forecast.current.weather[0].meteocon();
}


std::string WeatherUI::current_conditions() const {
    if (forecast.current.weather.empty()) {
        return "";
    }
    return forecast.current.weather[0].description;
}


OW::Daily WeatherUI::forcastForDay(uint8_t day) const {
    if (forecast.current.weather.size() > day) {
        return forecast.daily[day];
    }
    return OW::Daily();
}

void WeatherUI::tick() {
    auto now = std::chrono::steady_clock::now();

    if (!forecast.daily.empty() && std::chrono::duration_cast<std::chrono::seconds>(now - last_update) .count() > 60) {
        updateUI();
        last_update = now;
    }

    if (!is_fetching && std::chrono::duration_cast<std::chrono::minutes>(now - last_poll).count() > 10) {

        ESP_LOGI(TAG, "Polling for weather");

        const Network::Callback onDone = [this](bool success, const json &weather) -> void {
            ESP_LOGI(TAG, "Fetched Weather: %s", success ? "success" : "failed");
            this->is_fetching = false;
            if (success) {
                this->forecast = weather.template get<OW::Forecast>();
                this->last_poll = std::chrono::steady_clock::now();
                this->updateUI();
            }
        };
        this->is_fetching = true;
        network->fetchWeatherForecast(onDone);
    }
}


void WeatherUI::updateUI() {
    auto current = this->forecast.current;
    auto today = this->forecast.daily[0];

    auto meteocon = this->current_meteocon();

    if (meteocon) {
        lv_img_set_src(ui_currentWeather, meteocon);
    }

    lv_label_set_text(ui_forecastConditionsDesc, fmt::format("{}, current: {}", today.summary, current.condition().description).c_str());

    lv_label_set_text(ui_currentTemp, this->current_temp_degrees().c_str());
    lv_label_set_text(ui_currentFeelsLike, fmt::format("feels {:.0f}°", forecast.current.feels_like).c_str());
    lv_label_set_text(ui_currentTempPrecip,
                      fmt::format("{} {}", today.highLow(), today.precip()).c_str());

    lv_label_set_text(ui_currentHumidity, fmt::format("{}% hum",current.humidity).c_str());
    lv_label_set_text(ui_currentWind, fmt::format("{:.0f} wind",current.wind_speed).c_str());
    lv_label_set_text(ui_currentGust, fmt::format("gust {:.0f}",current.wind_gust).c_str());

    for (auto forecast : forecasts) {
        forecast->update(this->forecast.daily[forecast->index]);
    }

    auto now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );

    auto it = std::find_if(forecast.minutely.begin(), forecast.minutely.end(),
                           [now](const OW::Minute& mn) { return mn.dt >= now; });

    int8_t i = 0;

    for (; it != forecast.minutely.end(); it++) {
        ++i;
        ui_hourlyForecastChart_data[i] = it->precipitation * 35;
    }

    lv_chart_set_point_count(ui_hourlyForecastChart, i);
    ESP_LOGI(TAG, "Looking for %lld %s, drawing %d points", now, it != forecast.minutely.end() ? "t" : "f", i);

    lv_obj_invalidate(ui_hourlyForecastChart);
    lv_refr_now(NULL);
}
