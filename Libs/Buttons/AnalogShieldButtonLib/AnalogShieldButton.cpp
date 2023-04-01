#include "AnalogShieldButton.hpp"

AnalogShieldButton::AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, AnalogResolution bits_res)
{
    this->analogPin = analogPin;
    this->bits_res = bits_res;

    #ifdef USE_ANALOG_RESOLUTION
        analogReadResolution(AnalogResolutionToInt(this->bits_res));
    #endif // !Check for USE_ANALOG_RESOLUTION

    this->rawRead = -1;

    this->activationSize = arrSize;

    #ifdef REUSEARRAY
        this->activationValue = idArr;
    #else
        this->activationValue = new unsigned int[this->activationSize];

        for (int i = 0; i < this->activationSize; i++)
        {
            this->activationValue[i] = idArr[i];
        }
    #endif // !REUSEARRAY
}

AnalogShieldButton::~AnalogShieldButton()
{
    #ifndef REUSEARRAY
        delete[] this->activationValue;
        this->activationValue = nullptr;
    #endif // !REUSEARRAY
}

int AnalogShieldButton::getButton()
{
    this->read();

    for (size_t i = 0; i < this->activationSize; i++)
    {
        if (this->rawRead < this->activationValue[i])
        {
            return i;
        }
    }

    return -1;
}

long AnalogShieldButton::getLastRawRead()
{
    return this->rawRead;
}

void AnalogShieldButton::read()
{
    this->rawRead = analogRead(this->analogPin);
}

size_t AnalogShieldButton::getNumButtons()
{
    return this->activationSize;
}

unsigned int* AnalogShieldButton::getActivationValues()
{
    unsigned int arr[this->activationSize] = {};

    for (size_t i = 0; i < this->activationSize; i++)
    {
        arr[i] = this->activationValue[i];
    }

    return arr;
}