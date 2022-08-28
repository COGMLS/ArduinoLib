#include "AnalogCommon.hpp"

AnalogCommon::AnalogCommon(int analogPin)
{
    this->analogPin = analogPin;
    this->lastReadedVal = -1;
}

AnalogCommon::~AnalogCommon()
{

}

int AnalogCommon::getLastRead()
{
    return this->lastReadedVal;
}

int AnalogCommon::getLastRead(int out_max, int out_min = 0)
{
    return 
}

int AnalogCommon::read()
{
    this->lastReadedVal = analogRead(this->analogPin);
    return this->lastReadedVal;
}

int AnalogCommon::read(int out_max, int out_min = 0)
{
    this->lastReadedVal = analogRead(this->analogPin);
    return (255 * this->lastReadedVal) / 1023;
}