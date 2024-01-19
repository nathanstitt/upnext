#pragma once

#include "json.hpp"
#include "network.h"
#include <chrono>
#include <string>
#include <vector>

using json = nlohmann::json;

typedef std::chrono::time_point<std::chrono::system_clock> SysClock;

// struct Duration {
//     Duration(uint16_t minutes);
//     Duration(Duration &other);
//     const uint16_t minutes;

//     string str();
// };

class CalendarEvent {
public:
    CalendarEvent(json event);
    CalendarEvent(CalendarEvent &other);

    std::string units();
    std::string duration();

    int8_t minutes();

    std::string title() const;

    std::string startHHMM() const;
    std::string endHHMM() const;

    std::time_t startTime() const;
    std::time_t endTime() const;

    bool isActive(std::time_t currentTime) const;
    bool isNearlyActive() const;


private:
    json _event;
    mutable std::time_t _startTime = 0;
    mutable std::time_t _endTime = 0;
};

class CalendarEvents {
public:
    CalendarEvents(Network* network);

    bool tick();

    CalendarEvent *currentEvent() const;

    CalendarEvent *upcomingEvent();

    std::time_t now();
    std::string nowStr();

    // CalendarEvent current_event;
    // CalendarEvent next_event;

    // std::string duration_unit();

private:
    Network*                         network;
    std::chrono::steady_clock::time_point last_poll;
    std::vector<CalendarEvent*> events;
};
