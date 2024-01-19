#pragma once

#include "json.hpp"
#include "network.h"
#include <chrono>
#include <string>

#include "calendar.h"

using json = nlohmann::json;

typedef std::chrono::time_point<std::chrono::system_clock> SysClock;

class CalendarUI {
public:
    CalendarUI(Network* network);

    void tick();

    std::time_t now();
    std::string nowStr();

    void updateUI();
    void updateEvents(const json &jsonEvents);
private:
    Network *network;
    bool is_fetching = false;
    std::chrono::steady_clock::time_point last_poll;
    std::chrono::steady_clock::time_point last_update;

    Cal::Calendar calendar;
};
