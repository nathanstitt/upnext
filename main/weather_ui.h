#pragma once

#include <chrono>
#include "network.h"
#include "json.hpp"
#include "weather.h"
#include "forecast.h"

class WeatherUI {

public:
    WeatherUI(Network* network);

    void tick();

    OW::Forecast forecast;

    std::string current_temp_degrees() const;

    OW::Daily forcastForDay(uint8_t day) const;

    const lv_img_dsc_t* current_meteocon() const;
    std::string current_conditions() const;

    void updateUI();

  private:
    bool is_fetching = false;
    Network* network;
    std::vector<Forecast*> forecasts;
    std::chrono::steady_clock::time_point last_poll;
    std::chrono::steady_clock::time_point last_update;
};
