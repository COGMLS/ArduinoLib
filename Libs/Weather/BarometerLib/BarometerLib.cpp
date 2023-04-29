#include "BarometerLib.hpp"

BarometerLib::BarometerLib::BarometerLib(SENSOR_TYPE sensorType, void* sensorObj, bool useCelcius, bool useMeters)
{
    this->sensorType = sensorType;
    this->sensorObj = sensorObj;

    this->useCelcius = useCelcius;
    this->useMeters = useMeters;

    this->altitude[0] = this->altitude[1] = this->altitude[2] = 0.0f;
    this->pressure[0] = this->pressure[1] = this->pressure[2] = 0.0f;
    this->temperature[0] = this->temperature[1] = this->temperature[2] = 0.0f;

    this->pressureUnit = PRESSURE_MEASURE::PA;
}

BarometerLib::BarometerLib::~BarometerLib()
{

}

bool BarometerLib::BarometerLib::init()
{

}

void BarometerLib::BarometerLib::updateReadings()
{

}

void BarometerLib::BarometerLib::resetData()
{

}

float BarometerLib::BarometerLib::getLowestAltitude()
{

}

float BarometerLib::BarometerLib::getLowestPressure()
{

}

float BarometerLib::BarometerLib::getLowestTemperature()
{

}

float BarometerLib::BarometerLib::getCurrentAltitude()
{

}

float BarometerLib::BarometerLib::getCurrentPressure()
{

}

float BarometerLib::BarometerLib::getCurrentTemperature()
{

}

float BarometerLib::BarometerLib::getHighestAltitude()
{

}

float BarometerLib::BarometerLib::getHighestPressure()
{

}

float BarometerLib::BarometerLib::getHighestTemperature()
{

}

void BarometerLib::BarometerLib::setSeaLevel(float seaLevel)
{

}