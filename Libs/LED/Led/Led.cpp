#include "Led.hpp"

Led::Led(int ledPin)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    digitalWrite(this->ledPin, this->ledStatus);
}

Led::~Led()
{
    
}