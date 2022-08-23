#include "LedControl.hpp"

int LedControl::getPin()
{
    return this->ledPin;
}

bool LedControl::isOn()
{
    return this->ledStatus;
}

void LedControl::setOff()
{
    this->ledStatus = false;
    digitalWrite(this->ledPin, this->ledStatus);
}

void LedControl::setOn()
{
    this->ledStatus = true;
    digitalWrite(this->ledPin, this->ledPin);
}