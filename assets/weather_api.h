#pragma once

#include <chrono>
#include "network.h"
#include "json.hpp"
#include "weather_structs.h"


class WeatherAPI {

public:
    WeatherAPI(Network* network);

    bool tick();

    OW::Forecast forecast;

    std::string current_temp_decimal() const;

    std::string current_temp_degrees() const;

    OW::Daily forcastForDay(uint8_t day) const;

    const lv_img_dsc_t* current_meteocon() const;
    std::string current_conditions() const;

private:
    Network* network;

    std::chrono::system_clock::time_point last_poll;
};
