/** ThermoHydrometerLib
 * ------------------------------------
 * @brief Provide the Thermo-Hydrometer functionalities.
 * 
 * @author Matheu L. Silvati
 * @version 1.6.9
 * 
 * @date 2023/04/27
*/

#include "ThermoHydrometer.hpp"

ThermoHydrometer::ThermoHydrometer(uint8_t dhtPin, uint8_t sensorType, bool useCelcius)
{
    this->setWeatherDhtLib(dhtPin, sensorType);

    this->humidity[0] = this->humidity[1] = this->humidity[2] = 0.0f;
    this->temperature[0] = this->temperature[1] = this->temperature[2] = 0.0f;
    this->correctValue[0] = this->correctValue[1] = 0.0f;

    this->useCelcius = useCelcius;
    this->useCorrection = false;
}

ThermoHydrometer::~ThermoHydrometer()
{

}

void ThermoHydrometer::updateReadings()
{
    if (this->useCelcius)
    {
        this->temperature[1] = this->getTempC();
    }
    else
    {
        this->temperature[1] = this->getTempF();
    }

    // If correction temperature is applied
    if (this->correctValue[0] != 0.0f && useCorrection)
    {
        this->temperature[1] += this->correctValue[0];
    }

    this->humidity[1] = this->getHumidity();
    
    // If correction humidity is applied
    if (this->correctValue[1] != 0.0f && useCorrection)
    {
        this->humidity[1] += this->correctValue[1];
    }

    // Update the humidity data:

    if (this->humidity[1] < this->humidity[0])
    {
        this->humidity[0] = this->humidity[1];
    }

    if (this->humidity[1] > this->humidity[2])
    {
        this->humidity[2] = this->humidity[1];
    }

    // Update the temperature data:

    if (this->temperature[1] < this->temperature[0])
    {
        this->temperature[0] = this->temperature[1];
    }

    if (this->temperature[1] > this->temperature[2])
    {
        this->temperature[2] = this->temperature[1];
    }
}

void ThermoHydrometer::resetData()
{
    if (this->useCelcius)
    {
        this->temperature[0] = this->temperature[1] = this->temperature[2] = this->getTempC();
    }
    else
    {
        this->temperature[0] = this->temperature[1] = this->temperature[2] = this->getTempF();
    }

    if (this->correctValue[0] != 0.0f && useCorrection)
    {
        this->temperature[0] += this->correctValue[0];
        this->temperature[1] += this->correctValue[0];
        this->temperature[2] += this->correctValue[0];
    }

    this->humidity[0] = this->humidity[1] = this->humidity[2] = this->getHumidity();
    
    if (this->correctValue[1] != 0.0f && useCorrection)
    {
        this->humidity[0] += this->correctValue[1];
        this->humidity[1] += this->correctValue[1];
        this->humidity[2] += this->correctValue[1];
    }
}

void ThermoHydrometer::init()
{
    this->resetData();
}

void ThermoHydrometer::setTemperatureMeasure(bool setCelcius, bool preserveData)
{
    if (this->useCelcius != setCelcius)
    {
        // Convert the correction value
        if (this->correctValue[0] != 0.0f && useCorrection)
        {
            if (setCelcius)
            {
                this->correctValue[0] = ((this->correctValue[0] - 32.0f) / 9.0f) * 5.0f;    // C = ((F - 32) / 9) * 5
            }
            else    // Convert to Fahrenheit
            {
                this->correctValue[0] = (this->correctValue[0] * 1.8f) + 32.0f;   // F = (9/5 * C) + 32
            }
        }

        // Convert the storaged data
        if (preserveData)
        {
            for (int i = 0; i < 3; i++)
            {
                // Convert to Celcius
                if (setCelcius)
                {
                    this->temperature[i] = ((this->temperature[i] - 32.0f) / 9.0f) * 5.0f;    // C = ((F - 32) / 9) * 5
                }
                else    // Convert to Fahrenheit
                {
                    this->temperature[i] = (this->temperature[i] * 1.8f) + 32.0f;   // F = (9/5 * C) + 32
                }
            }

            this->useCelcius = setCelcius;
        }
        else
        {
            this->useCelcius = setCelcius;
            this->resetData();
        }
    }
}

bool ThermoHydrometer::isCelcius()
{
    return this->useCelcius;
}

float ThermoHydrometer::getCurrentTemperature()
{
    return this->temperature[1];
}

float ThermoHydrometer::getCurrentHumidity()
{
    return this->humidity[1];
}

float ThermoHydrometer::getLowestTemperature()
{
    return this->temperature[0];
}

float ThermoHydrometer::getHighestTemperature()
{
    return this->temperature[2];
}

float ThermoHydrometer::getLowestHumidity()
{
    return this->humidity[0];
}

float ThermoHydrometer::getHighestHumidity()
{
    return this->humidity[2];
}

void ThermoHydrometer::setCorrectTemp(float correctTemp)
{
    this->useCorrection = true;
    this->correctValue[0] = correctTemp;
}

void ThermoHydrometer::setCorrectHumidity(float correctHumidity)
{
    this->useCorrection = true;
    this->correctValue[1] = correctHumidity;
}

void ThermoHydrometer::setNoCorrection()
{
    this->useCorrection = false;
}

float ThermoHydrometer::getCorrectTemp()
{
    return this->correctValue[0];
}

float ThermoHydrometer::getCorrectHumidity()
{
    return this->correctValue[1];
}