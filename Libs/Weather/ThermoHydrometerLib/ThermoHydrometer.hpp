/** ThermoHydrometerLib
 * ------------------------------------
 * @brief Provide the Thermo-Hydrometer functionalities.
 * 
 * @author Matheu L. Silvati
 * @version 1.6.10
 * 
 * @date 2023/04/29
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

        /**
         * @brief Correction value: 0 - Temperature (based on current measure unit), 1 - Humidity (in percentage)
        */
        float correctionValue[2];
        
        // Define if is in Celcius or in Fahrenheit
        bool useCelcius;

        // Use correction values
        bool useCorrection;
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

        /**
         * @brief Set a correction value to Temperature.
         * @param correctionTemp Correction Temperature on current temperature measure unit
         * @note Use with caution this correction value.
        */
        void setCorrectionTemp(float correctionTemp);

        /**
         * @brief Set a correction value to Humidity
         * @param correctionHumidity Correction Humidity percentage
         * @note Use values between -100% to 100%.
         * @note Use with caution this correction value.
        */
        void setCorrectionHumidity(float correctionHumidity);

        /// @brief Set to disable the value correction.
        /// @note Any call to setCorrectionHumidity or setCorrectionTemp, will activate the correction again.
        void setNoCorrection();

        /**
         * @brief Get the correction value to Temperature
         * @note By default the correction value is 0.0f
        */
        float getCorrectionTemp();
        
        /**
         * @brief Get the correction value to Humidity (%)
         * @note By default the correction value is 0.0f
        */
        float getCorrectionHumidity();
};

#endif // !THERMO_HYDROMETER_HPP