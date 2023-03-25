#pragma once

#ifndef MATH_WEATHER_LIB_H
#define MATH_WEATHER_LIB_H

/**
 * @brief Convert the temperature to Celcius
 * @param temperature temperature to be converted to.
 * @param fromKelvin Define the temperature parameter is in Kelvin or treat as Fahrenheit.
*/
float convertCelcius(float temperature, bool fromKelvin);

/**
 * @brief Convert the temperature to Fahrenheit
 * @param temperature temperature to be converted to.
 * @param fromKelvin Define the temperature parameter is in Kelvin or treat as Celcius.
*/
float convertFahrenheit(float temperature, bool fromKelvin);

/**
 * @brief Convert the temperature to Kelvin
 * @param temperature temperature to be converted to.
 * @param fromFahrenheit Define the temperature parameter is in Fahrenheit or treat as Celcius.
*/
float convertKelvin(float temperature, bool fromFahrenheit);

#endif // !MATH_WEATHER_LIB_H