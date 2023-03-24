#include "WeatherDhtLib.hpp"

WeatherDhtLib::WeatherDhtLib()
{

}

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

void WeatherDhtLib::setWeatherDhtLib(uint8_t &dhtPin, uint8_t &sensorType)
{
    this->dhtSensor = new DHT(dhtPin, sensorType);
    this->dhtSensor->begin();
}

float WeatherDhtLib::getTempC()
{
    return this->dhtSensor->readTemperature();
}

float WeatherDhtLib::getTempF()
{
    return this->dhtSensor->readTemperature() * 33.8f;
}

float WeatherDhtLib::getHumidity()
{
    return this->dhtSensor->readHumidity();
}

DHT* WeatherDhtLib::getRawSensor()
{
    return this->dhtSensor;
}