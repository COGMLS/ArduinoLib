#pragma once

#ifndef WEATHER_DHT_LIB_HPP
#define WEATHER_DHT_LIB_HPP

#include <Arduino.h>
#include <DHT.h>

/**
 * @brief Weather DHT Class library
 * @details Perform easy base controls for DHT sensors and allow the original DHT class to be accessed
*/
class WeatherDhtLib
{
    private:
        DHT* dhtSensor = nullptr;
    public:
        /**
         * @brief Empty constructor class. ONLY for inheritance.
        */
        WeatherDhtLib();

        /**
         * @brief Define and initialize the Weather DHT object
         * @param dhtPin DHT data pin sensor
         * @param sensorType Define the DHT sensor type (DHT11, DHT12, DHT21, DHT22 or AM2301)
        */
        WeatherDhtLib(uint8_t dhtPin, uint8_t sensorType);

        ~WeatherDhtLib();

        /**
         * @brief Get the sensor temperature in Celcius
        */
        float getTempC();

        /**
         * @brief Get the sensor temperature in Fahrenheit
         * @note This function call the internal DHT function convertion and uses double data type, which is not optimized to Arduino architecture.
        */
        float getTempF();

        /**
         * @brief Get the humidity from sensor
        */
        float getHumudity();

        /**
         * @brief Exposes the DHT object to use other functions from DHT class library.
        */
        DHT* getRawSensor();
};

#endif // !WEATHER_DHT_LIB_HPP