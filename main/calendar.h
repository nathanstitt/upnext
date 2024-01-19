#pragma once

#include <string>
#include "json.hpp"

namespace Cal {

    std::string timeToStr(std::time_t tt, bool includeAMPM = true);

    std::time_t strToTimeT(std::string time);

    struct Event {
        bool allDay;
        std::string startAt;
        std::string endAt;
        std::string title;

        std::string duration() const;

        uint32_t minutesFromNow() const;

        std::string startHHMM() const;
        std::string endHHMM() const;

        std::time_t startTime() const;
        std::time_t endTime() const;

        bool occursToday() const;
        bool isActive() const;
        bool isInPast() const;
        bool isInFuture(std::time_t currentTime) const;

        bool isActive(std::time_t currentTime) const;
        bool isNearlyActive() const;

        mutable std::time_t _startTime = 0;
        mutable std::time_t _endTime = 0;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Event, allDay, startAt, endAt, title);
    };

    struct Calendar {

        const Event *currentEvent() const;

        const Event *upcomingEvent() const;

        std::vector<Event>::const_iterator currentEventIndex() const;

        std::vector<Event> events;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Calendar, events);
    };

}
