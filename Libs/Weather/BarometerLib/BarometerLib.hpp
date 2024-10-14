/** Generic Barometric Sensor Data Library
 * ----------------------------------------------
 * @brief Controls data read from barometric sensor, like BMP 085/180/280. Using generic calls from stored address in a void pointer.
 * 
 * @author Matheus L. Silvati
 * 
 * @version 0.1.0
 * 
 * @note In Development
*/

#pragma once

#ifndef BAROMETER_SENSOR_LIB_HPP
#define BAROMETER_SENSOR_LIB_HPP

#include <Arduino.h>

#ifdef SET_SENSOR_BMP_085_180
    #include <Adafruit_BMP085.h>
#endif

#ifdef SET_SENSOR_BMP280
    #include <Adafruit_BMP280.h>
#endif

namespace BarometerLib
{
    enum
    {
        BMP085,
        BMP180,
        BMP280
    }
    typedef SENSOR_TYPE;

    enum
    {
        PA,
        hPA,
        kPA,
        BAR,
        ATM,
        mmHG,
        PSI
    }
    typedef PRESSURE_MEASURE;

    class BarometerLib
    {
        private:
            SENSOR_TYPE sensorType;
            void* sensorObj;

            // Altitude data: 0 - Lowest, 1 - Current, 2 - Highest
            float altitude[3];

            // Pressure data: 0 - Lowest, 1 - Current, 2 - Highest
            float pressure[3];

            // Temperature data: 0 - Lowest, 1 - Current, 2 - Highest
            float temperature[3];

            // Use Celsius measure
            bool useCelsius;

            // Use meters to measure
            bool useMeters;

            // Unit measure for pressure
            PRESSURE_MEASURE pressureUnit;
        public:

            BarometerLib(SENSOR_TYPE sensorType, void* sensorObj, bool useCelsius = true, bool useMeters = true);
            ~BarometerLib();

            /// @brief Get the sensor void pointer.
            /// @return An generic pointer to sensor.
            void* getSensor();

            /// @brief Initialize the sensor
            /// @return TRUE if the initialization was successful.
            bool init();

            /// @brief Update the stored data
            void updateReadings();

            /// @brief Reset the stored data.
            void resetData();

            /// @brief Get the lowest altitude value
            float getLowestAltitude();

            /// @brief Get the lowest pressure value
            float getLowestPressure();
            
            /// @brief Get the lowest temperature value
            float getLowestTemperature();
            
            /// @brief Get the current altitude value
            float getCurrentAltitude();
            
            /// @brief Get the current pressure value
            float getCurrentPressure();
            
            /// @brief Get the current temperature value
            float getCurrentTemperature();
            
            /// @brief Get the highest altitude value
            float getHighestAltitude();
            
            /// @brief Get the highest pressure value
            float getHighestPressure();
            
            /// @brief Get the highest temperature value
            float getHighestTemperature();
            
            /// @brief Get the string altitude measure
            char* getStrAltitudeMeasure();
            
            /// @brief Get the string pressure measure
            char* getStrPressureMeasure();
            
            /// @brief Check if is in Celsius (true) or Fahrenheit (false)
            bool isCelsius();

            /// @brief Check if is in Meters (true) or Feet (false) 
            bool isMeters();

            /**
             * @brief Change the altitude measure unit.
             * @param setMeters Define if is in Meters (true) or Feet (false)
             * @param preserveData If true, it will convert the stored data to preserve the lowest and highest values.
             * @note After change the measure unit, the data stored will be update to the new measure unit if preserveData is true. Otherwise the stored data will be reset.
            */
            void setAltitudeMeasure(bool setMeters, bool preserveData = true);

            /**
             * @brief Change the pressure measure unit.
             * @param setPressure Define the pressure unit.
             * @param preserveData If true, it will convert the stored data to preserve the lowest and highest values.
             * @note After change the measure unit, the data stored will be update to the new measure unit if preserveData is true. Otherwise the stored data will be reset.
            */
            void setPressureMeasure(PRESSURE_MEASURE setPressure, bool preserveData = true);

            /**
             * @brief Change the temperature measure unit.
             * @param setCelsius Define if is in Celsius (true) or Fahrenheit (false)
             * @param preserveData If true, it will convert the stored data to preserve the lowest and highest values.
             * @note After change the measure unit, the data stored will be update to the new measure unit if preserveData is true. Otherwise the stored data will be reset.
            */
            void setTemperatureMeasure(bool setCelsius, bool preserveData = true);

            /// @brief Define the Sea Level for altitude measure
            /// @param seaLevel Sea Level in meters
            void setSeaLevel(float seaLevel);
    };

} // namespace BarometerLib

#endif // !BAROMETER_SENSOR_LIB_HPP