#pragma once

#include "json.hpp"
#include <string>

using json = nlohmann::json;

class Network {

public:
    Network();

    void init();

    json gcalEvents();

    json weatherForecast();

private:

};

