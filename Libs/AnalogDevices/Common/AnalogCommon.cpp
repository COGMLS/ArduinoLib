#include "AnalogCommon.hpp"

ard::AnalogCommon::AnalogCommon::AnalogCommon(int analogPin)
{
    this->analogPin = analogPin;
    this->lastReadedVal = -1;
}

ard::AnalogCommon::AnalogCommon::~AnalogCommon()
{

}

int ard::AnalogCommon::AnalogCommon::getLastRead()
{
    return this->lastReadedVal;
}

int ard::AnalogCommon::AnalogCommon::getLastRead(int out_max, int out_min)
{
    this->lastReadedVal = analogRead(this->analogPin);
    return (this->lastReadedVal - 0) * (out_max - out_min) / (1023 - 0) + out_min;
}

int ard::AnalogCommon::AnalogCommon::read()
{
    this->lastReadedVal = analogRead(this->analogPin);
    return this->lastReadedVal;
}

int ard::AnalogCommon::AnalogCommon::read(int out_max, int out_min = 0)
{
    this->lastReadedVal = analogRead(this->analogPin);
    return (this->lastReadedVal - 0) * (out_max - out_min) / (1023 - 0) + out_min;
}

void ard::AnalogCommon::write(int val)
{
    if(val >= 0 && val <= 255)
    {
        analogWrite(this->analogPin, val);
    }
}

void ard::AnalogCommon::write(short percentage)
{
    if(percentage >= 0 && percentage <= 100)
    {
        int rawVal = (255 * (int)percentage) / 100;
        this->write(rawVal);
    }
}