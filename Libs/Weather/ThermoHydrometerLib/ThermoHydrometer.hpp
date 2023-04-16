/** ThermoHydrometerLib
 * ------------------------------------
 * @brief Provide the Thermo-Hydrometer functionalities.
 * 
 * @anchor Matheu L. Silvati
 * @version 0.8.6
 * 
 * @date 2023/03/23
*/

#pragma once

#ifndef THERMO_HYDROMETER_HPP
#define THERMO_HYDROMETER_HPP

#include <WeatherDhtLib.hpp>

class ThermoHydrometer : WeatherDhtLib
{
    private:
        /**
         * @brief Temperature data: 0 - lowest value, 1 - current value, 2 - highest value
        */
        float temperature[3];

        /**
         * @brief Humidity data: 0 - lowest value, 1 - current value, 2 - highest value
        */
        float humidity[3];
        
        // Define if is in Celcius or in Fahrenheit
        bool useCelcius;
        
    public:
        /**
         * @brief Create an object to manage the Thermo-Hydrometer data and sensor.
         * @param dhtPin Define the DHT sensor pin to setup.
         * @param useCelcius Determinate if is using the temperature is in Celcius or in Fahrenheit. The default parameter value is true for Celcius.
        */
        ThermoHydrometer(uint8_t dhtPin, uint8_t sensorType, bool useCelcius = true);
        ~ThermoHydrometer();

        /**
         * @brief Update the storaged data and set the new lowest and highest values.
        */
        void updateReadings();

        /**
         * @brief Initialyze the Thermo-Hydrometer object.
         * @note This is a mitigation for a bad initialyzation inside the constructor starting with a first reading.
        */
        void init();

        /**
         * @brief Reset the storaged data.
        */
        void resetData();

        /**
         * @brief Change the temperature measure unit.
         * @param setCelcius Define if is in Celcius (true) or Fahrenheit (false)
         * @param preserveData If true, it will convert the storaged data to preserve the lowest and highest values.
         * @note After change the measure unit, the data storaged will be update to the new measure unit if preserveData is true. Otherwise the storaged data will be reseted.
        */
        void setTemperatureMeasure(bool setCelcius, bool preserveData = true);

        /**
         * @brief Check the temperature measure unit.
        */
        bool isCelcius();

        /**
         * @brief Get the current humidity data from last update reading
        */
        float getCurrentHumidity();

        /**
         * @brief Get the current temperature data from last update reading
         * @note Check the measure unit before use this data
        */
        float getCurrentTemperature();

        /**
         * @brief Get the lowest temperature data from last update reading
         * @note Check the measure unit before use this data
        */
        float getLowestTemperature();

        /**
         * @brief Get the highest temperature data from last update reading
         * @note Check the measure unit before use this data
        */
        float getHighestTemperature();

        /**
         * @brief Get the lowest humidity data from last update reading
        */
        float getLowestHumidity();

        /**
         * @brief Get the highest humidity data from last update reading
        */
        float getHighestHumidity();
};

#endif // !THERMO_HYDROMETER_HPP