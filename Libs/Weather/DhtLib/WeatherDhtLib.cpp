/** DHT Weather Lib
 * ------------------------------------
 * @brief Extended the DHT sensors functionalities.
 * 
 * @anchor Matheus L. Silvati
 * @version 1.1.6
 * 
 * @date 2023/03/23
*/

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
    return this->dhtSensor->readTemperature(true);
}

float WeatherDhtLib::getHumidity()
{
    return this->dhtSensor->readHumidity();
}

DHT* WeatherDhtLib::getRawSensor()
{
    return this->dhtSensor;
}