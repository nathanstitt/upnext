#include "weather.h"
#include <fmt/format.h>

std::unordered_map<std::string, const lv_img_dsc_t*> WeatherImages = {
    { "01d", &asset_clear_sky_day },
    { "01n", &asset_clear_sky_night },
    { "02d", &asset_few_clouds_day },
    { "02n", &asset_few_clouds_night },
    { "03d", &asset_scattered_clouds },
    { "03n", &asset_scattered_clouds },
    { "04d", &asset_broken_clouds_day },
    { "04n", &asset_broken_clouds_night },
    { "09d", &asset_shower_rain_day },
    { "09n", &asset_shower_rain_night },
    { "10d", &asset_rain },
    { "09n", &asset_rain },
    { "11d", &asset_thunderstorm },
    { "10n", &asset_thunderstorm },
    { "13d", &asset_snow },
    { "13n", &asset_snow },
    { "50d", &asset_mist },
    { "50n", &asset_mist }
};


namespace OW {
    void to_json(json& j, const CurrentRain& cr) {
        j = json({"1h" , cr.hr});
    }

    void from_json(const json& j, CurrentRain& cr) {
        j.at("1h").get_to(cr.hr);
    }



    const lv_img_dsc_t* WeatherCondition::meteocon() const {
        auto it = WeatherImages.find(this->icon);
        if (it != WeatherImages.end()) {
            return it->second;
        }
        return nullptr;
    }
    const std::string Daily::highLow() const {
        return fmt::format("{:.0f}-{:.0f}°", temp.min, temp.max);
    }
            
    const std::string Daily::precip() const {
        bool isSnow = (snow > 0.0);
        return fmt::format("{}: {:.0f}%", isSnow ? "prcp" : "rain", (pop*100));
    };

    WeatherCondition Current::condition() const {
        if (!weather.size())
            return WeatherCondition {};

        return weather[0];
    };

    WeatherCondition Daily::condition() const {
        if (!weather.size())
            return WeatherCondition {};

        return weather[0];
    };
}
