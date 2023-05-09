/** Analog Shield Button Library
 * ------------------------------------
 * @brief Provide simple way to determinate what button was pressed in an analog shield button, detecting the analog input with different resistances associated with each button.
 * 
 * @anchor Matheu L. Silvati
 * @version 2.1.0
 * 
 * @date 2023/05/09
*/

#include "AnalogShieldButton.hpp"

AnalogShieldButton::AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, AnalogResolution bits_res)
{
    this->analogPin = analogPin;
    this->bits_res = bits_res;
    this->threshold = 0u;
    this->useFastCheck = true;

    #ifdef USE_ANALOG_RESOLUTION
        analogReadResolution(AnalogResolutionToInt(this->bits_res));
    #endif // !Check for USE_ANALOG_RESOLUTION

    this->rawRead = -1;

    this->activationSize = arrSize;

    this->activationValue = new unsigned int[this->activationSize];

    for (int i = 0; i < this->activationSize; i++)
    {
        this->activationValue[i] = idArr[i];
    }
}

AnalogShieldButton::AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, bool useFastCheck, AnalogResolution bits_res)
{
    this->analogPin = analogPin;
    this->bits_res = bits_res;
    this->threshold = 0u;
    this->useFastCheck = useFastCheck;

    #ifdef USE_ANALOG_RESOLUTION
        analogReadResolution(AnalogResolutionToInt(this->bits_res));
    #endif // !Check for USE_ANALOG_RESOLUTION

    this->rawRead = -1;

    this->activationSize = arrSize;

    this->activationValue = new unsigned int[this->activationSize];

    for (int i = 0; i < this->activationSize; i++)
    {
        this->activationValue[i] = idArr[i];
    }
}

AnalogShieldButton::AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, unsigned int threshold, AnalogResolution bits_res)
{
    this->analogPin = analogPin;
    this->bits_res = bits_res;
    this->threshold = threshold;
    this->useFastCheck = true;

    #ifdef USE_ANALOG_RESOLUTION
        analogReadResolution(AnalogResolutionToInt(this->bits_res));
    #endif // !Check for USE_ANALOG_RESOLUTION

    this->rawRead = -1;

    this->activationSize = arrSize;

    this->activationValue = new unsigned int[this->activationSize];

    for (int i = 0; i < this->activationSize; i++)
    {
        this->activationValue[i] = idArr[i];
    }
}

AnalogShieldButton::AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, unsigned int threshold, bool useFastCheck, AnalogResolution bits_res)
{
    this->analogPin = analogPin;
    this->bits_res = bits_res;
    this->threshold = threshold;
    this->useFastCheck = useFastCheck;

    #ifdef USE_ANALOG_RESOLUTION
        analogReadResolution(AnalogResolutionToInt(this->bits_res));
    #endif // !Check for USE_ANALOG_RESOLUTION

    this->rawRead = -1;

    this->activationSize = arrSize;

    this->activationValue = new unsigned int[this->activationSize];

    for (int i = 0; i < this->activationSize; i++)
    {
        this->activationValue[i] = idArr[i];
    }
}

AnalogShieldButton::~AnalogShieldButton()
{
    delete[] this->activationValue;
    this->activationValue = nullptr;
}

int AnalogShieldButton::getButton()
{
    this->read();

    // Check if the reading is lower than threshold
    // If threshold is equal to 0, than consider threshold disabled for backward compatibility with ver. 1
    if (this->rawRead <= this->threshold && this->threshold > 0)
    {
        return -1;
    }

    if (this->useFastCheck)
    {
        return this->verifyButton_FastCheck();
    }
    else
    {
        return this->verifyButton_PrecisionCheck();
    }
}

unsigned int AnalogShieldButton::getLastRawRead()
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

int AnalogShieldButton::verifyButton_FastCheck()
{
    for (size_t i = 0; i < this->activationSize; i++)
    {
        // If the reading if higher than threshold, check for possible buttons
        if (this->rawRead < this->activationValue[i])
        {
            return i;
        }
    }

    return -1;
}

int AnalogShieldButton::verifyButton_PrecisionCheck()
{
    for (size_t i = 0; i < this->activationSize; i++)
    {
        // If the reading if higher than threshold, check for possible buttons
        if (i == 0)
        {
            if (this->rawRead > this->threshold && this->rawRead < this->activationValue[i])
            {
                return i;
            }
        }
        else if (i < this->activationSize && i > 0)
        {
            // Check if the raw read is between the values
            if (this->rawRead > this->activationValue[i - 1] && this->rawRead < this->activationValue[i])
            {
                return i;
            }
        }
        else
        {
            // On last value, check if is under button's threshold
            if (this->rawRead < this->activationValue[i])
            {
                return i;
            }
        }
    }

    return -1;
}