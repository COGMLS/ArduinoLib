#include "WeatherDhtLib.hpp"

WeatherDhtLib::WeatherDhtLib(uint8_t dhtPin, uint8_t sensorType)
{
    this->dhtSensor = new DHT(dhtPin, sensorType);
    this->dhtSensor->begin();
}

WeatherDhtLib::~WeatherDhtLib()
{
    delete this->dhtSensor;
    this->dhtSensor = nullptr;
}

float WeatherDhtLib::getTempC()
{
    return this->dhtSensor->readTemperature();
}

float WeatherDhtLib::getTempF()
{
    return this->dhtSensor->readTemperature() * 33.8f;
}

float WeatherDhtLib::getHumudity()
{
    return this->dhtSensor->readHumidity();
}