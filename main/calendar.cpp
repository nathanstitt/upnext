#include "calendar.h"

#include "fmt/format.h"
#include "esp_log.h"
#include <algorithm>
#include <sstream>
#include <ctime>
#include "time.h"
#include <chrono>
#include "upnext_config.h"
#include "esp_log.h"

const char *ISO_DATE_FORMAT = "%Y-%m-%dT%H:%M:%S.000Z";

static const char *TAG = "cal";

namespace Cal {

    std::string timeToStr(std::time_t tt, bool includeAMPM) {
        // Convert to tm struct for local time
        struct tm tm;

        localtime_r(&tt, &tm);

        return fmt::format("{:d}:{:02d}{}",
                           tm.tm_hour > 12 ? tm.tm_hour - 12 : tm.tm_hour,
                           tm.tm_min,
                           includeAMPM ? (tm.tm_hour > 12 ? "pm" : "am") : ""
                           );
    }


    std::time_t strToTimeT(std::string time) {
        std::tm utc = {};
        std::stringstream ss(time);

        ss >> std::get_time(&utc, ISO_DATE_FORMAT);
        if (ss.fail()) {
            return 0;
        }
//        ESP_LOGI(TAG, "parsed %s hour: %d", time.c_str(), utc.tm_hour);

        utc.tm_isdst = 0; // dates are in GMT, no dst

        return mktime(&utc) - _timezone;

        // auto f = statm - _timezone;

        // struct tm local;
        // localtime_r(&f, &local);

        // // auto local = localtime_r(&statm);
        // auto tz = getenv("TZ");

        // ESP_LOGI(TAG, "local %s (%s) hour: %d", time.c_str(), tz, local.tm_hour );

        // auto tt = std::mktime(&local);
    //    return tt;
    }


    std::string pluralize(uint16_t qty, std::string label) {
        std::string ret(label);
        if (qty > 1) ret += "s";
        return ret;
    }


    std::string durationStr(int32_t minutes) {

        std::ostringstream os;

        if (0 == minutes) {
            return "";
        }

        if (minutes < 30) {
            os << minutes << pluralize(minutes, " minute");
            return os.str();
        }

        auto dv = std::div(static_cast<int>(minutes), 60);

        std::string fraction("");

        if (dv.rem > 50) {
            dv.quot += 1;
        } else if (dv.rem > 35) {
            fraction = "¾";
        } else if (dv.rem > 25) {
            fraction = "½";
        } else if (dv.rem > 10) {
            fraction = "¼";
        }

        if (dv.quot > 0) {
            os << dv.quot << fraction << pluralize(dv.quot, " hour");
        } else {
            os << fraction << " hour";
        }

        return os.str();
    }




    std::string Event::duration() const {
        auto now = std::chrono::system_clock::now();

        std::time_t ltime = std::chrono::system_clock::to_time_t(now);

        auto startingMinutes = (startTime() - ltime) / 60;

        auto endingMinutes = (endTime() - ltime) / 60;

        // ESP_LOGI(TAG, "now: %lld st: %lld lt: %lld stm: %lld em %lld", ltime, startTime(), endTime(), startingMinutes, endingMinutes);

        std::ostringstream os;

        if (startingMinutes < 0) {
            os << "Until " << this->endHHMM() << "\n(" << durationStr(endingMinutes) << ")";
        }

        if (startingMinutes == 0) {
            os << "starting, ending in " << durationStr(endingMinutes);
        }

        if (startingMinutes > 0) {
            if (startingMinutes > UPCOMING_MINS) {
                os << "Free time for\n";
            } else {
                os << "In ";

            }
            os << durationStr(startingMinutes);
        }

        return os.str();
    }

    std::time_t Event::startTime() const {
        // if (_startTime) {
        //     return _startTime;
        // }
        return _startTime = strToTimeT(this->startAt);
    }

    std::string Event::startHHMM() const {
        return timeToStr(this->startTime());
    }

    std::string Event::endHHMM() const {
        return timeToStr(this->endTime());
    }


    std::time_t Event::endTime() const {
        // if (_endTime) {
        //     return _endTime;
        // }
        return _endTime = strToTimeT(this->endAt);
    }

    bool Event::occursToday() const {
        auto now = std::chrono::system_clock::now();

        std::time_t now_c = std::chrono::system_clock::to_time_t(now);

        std::tm* now_tm = std::localtime(&now_c);

        // std::time_t now = std::time(nullptr);
        // std::tm *ptm = std::localtime(&now);

        // Start of the current day
        now_tm->tm_hour = 0;
        now_tm->tm_min = 0;
        now_tm->tm_sec = 0;
        std::time_t startOfDay = std::mktime(now_tm);

        // End of the current day
        now_tm->tm_hour = 23;
        now_tm->tm_min = 59;
        now_tm->tm_sec = 59;
        std::time_t endOfDay = std::mktime(now_tm);

        std::time_t start = startTime();
        std::time_t end = endTime();
ESP_LOGI(TAG, "occurToday %s\n%lld %lld %lld %lld",title.c_str(),  startOfDay, endOfDay, start, end);
        return (start >= startOfDay && start <= endOfDay) ||
            (end >= startOfDay && end <= endOfDay);
    };

    bool Event::isInPast() const {
        std::time_t ct = std::time(nullptr);
        return ct > endTime();
    }

    bool Event::isActive() const {
        std::time_t ct = std::time(nullptr);
        return this->isActive(ct);
    }

    bool Event::isInFuture(std::time_t ct) const {
        return (ct < startTime());
    }

    bool Event::isActive(std::time_t ct) const {
        auto active = (ct >= startTime() && ct <= endTime());
        return active;
    }


    bool Event::isNearlyActive() const {
        return ((!isActive()) && (this->minutesFromNow() < UPCOMING_MINS));
    }

    uint32_t Event::minutesFromNow() const {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

        return (startTime() - currentTime) / 60;
    }

    std::vector<Event>::const_iterator Calendar::currentEventIndex() const {
        std::time_t ct = std::time(nullptr);
        auto it = std::find_if(events.begin(), events.end(),
                               [ct](const Event& ev) { return ev.isActive(ct); });

        return it;
    }


    // Calendar methods

    const Event *Calendar::currentEvent() const {
        auto it = this->currentEventIndex();

        if (it == this->events.end()) {
            return nullptr;
        }

        return &(*it);
    }

    const Event* Calendar::upcomingEvent() const {
        auto it = this->currentEventIndex();
        if (it == events.end()) { // no current event
            std::time_t ct = std::time(nullptr);

            it = std::find_if(
                events.begin(), events.end(),
                [ct](const Event &ev) { return ev.isInFuture(ct); });
        } else {
            ++it;
        }

        if (it == events.end()) {
            return nullptr;
        }
        return &(*it);
    }

}
