/** DHT Weather Lib
 * ------------------------------------
 * @brief Extended the DHT sensors functionalities.
 * 
 * @anchor Matheus L. Silvati
 * @version 1.1.6
 * 
 * @date 2023/03/23
*/

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
        // DHT sensor object
        DHT* dhtSensor = nullptr;

    protected:
        /**
         * @brief Empty constructor class. ONLY for inheritance.
        */
        WeatherDhtLib();

        /**
         * @brief Configure and initialize the DHT sensor for inheritance classes.
         * @param dhtPin DHT data pin sensor
         * @param sensorType Define the DHT sensor type (DHT11, DHT12, DHT21, DHT22 or AM2301)
        */
        void setWeatherDhtLib(uint8_t &dhtPin, uint8_t &sensorType);

    public:

        /**
         * @brief Define and initialize the Weather DHT object
         * @param dhtPin DHT data pin sensor
         * @param sensorType Define the DHT sensor type (DHT11, DHT12, DHT21, DHT22 or AM2301)
        */
        WeatherDhtLib(uint8_t dhtPin, uint8_t sensorType);

        ~WeatherDhtLib();

        /**
         * @brief Get the sensor temperature in Celsius
        */
        float getTempC();

        /**
         * @brief Get the sensor temperature in Fahrenheit
         * @note This function call the internal DHT function conversion and uses double data type, which is not optimized to Arduino architecture.
        */
        float getTempF();

        /**
         * @brief Get the humidity from sensor
        */
        float getHumidity();

        /**
         * @brief Exposes the DHT object to use other functions from DHT class library.
        */
        DHT* getRawSensor();
};

#endif // !WEATHER_DHT_LIB_HPP