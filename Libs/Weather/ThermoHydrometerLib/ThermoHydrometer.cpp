#include "ThermoHydrometer.hpp"

ThermoHydrometer::ThermoHydrometer(uint8_t dhtPin, uint8_t sensorType, bool useCelcius)
{
    this->setWeatherDhtLib(dhtPin, sensorType);

    this->humidity[0] = this->humidity[1] = 0.0f;
    this->temperature[0] = this->temperature[1] = 0.0f;

    this->useCelcius = useCelcius;

    this->resetData();
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

    this->humidity[1] = this->getHumidity();

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

    this->humidity[0] = this->humidity[1] = this->humidity[2] = this->getHumidity();
}

float ThermoHydrometer::getTemperature()
{
    return this->temperature[1];
}
bool ThermoHydrometer::isCelcius()
{
    return this->useCelcius;
}

float ThermoHydrometer::getCurrentHumidity()
{
    return this->humidity[1];
}

float ThermoHydrometer::getLowestTemp()
{
    return this->temperature[0];
}

float ThermoHydrometer::getHighestTemp()
{
    return this->temperature[2];
}

float ThermoHydrometer::getLowestHumidity()
{
    return this->humidity[0];
}

float ThermoHydrometer::getHighestHumidity()
{
    return this->humidity[1];
}