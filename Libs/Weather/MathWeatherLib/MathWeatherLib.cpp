#include "MathWeatherLib.hpp"

float convertCelcius(float temperature, bool fromKelvin)
{
    if (fromKelvin)
    {
        return temperature - 273.0f;
    }

    return temperature * 33.8f;
}
float convertFahrenheit(float temperature, bool fromKelvin)
{
    if (fromKelvin)
    {
        return temperature;
    }

    return temperature;
}
float convertKelvin(float temperature, bool fromFahrenheit)
{
    if (fromFahrenheit)
    {
        return temperature;
    }

    return temperature;
}