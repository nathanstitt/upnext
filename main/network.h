#pragma once

#include "json.hpp"
#include <string>

using json = nlohmann::json;

class Network {

public:
    using Callback = std::function<void(bool success, const nlohmann::json &j)>;

    Network();

    void init();

    void fetchCalendarEvents(const Callback &onDone);

    void fetchWeatherForecast(const Callback &onDone);

private:
    void perform(std::string host, std::string path);
};

