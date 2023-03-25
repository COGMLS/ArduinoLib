#pragma once

#ifndef THERMO_HYDROMETER_HPP
#define THERMO_HYDROMETER_HPP

#include <WeatherDhtLib.hpp>

class ThermoHydrometer : WeatherDhtLib
{
    private:
        float temperature[3];       // Index 0: lowest value, Index 1: current value, Index: 2: highest value
        float humidity[3];      // Index 0: lowest value, Index 1: current value, Index: 2: highest value
        bool useCelcius;
    public:
        ThermoHydrometer(uint8_t dhtPin, uint8_t sensorType, bool useCelcius);
        ~ThermoHydrometer();
        void updateReadings();
        void resetData();
        bool isCelcius();
        float getCurrentHumidity();
        float getCurrentTemperature();
        float getLowestTemp();
        float getHighestTemp();
        float getLowestHumidity();
        float getHighestHumidity();
};

#endif // !THERMO_HYDROMETER_HPP