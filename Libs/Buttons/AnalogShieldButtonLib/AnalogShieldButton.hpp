#pragma once

#ifndef ANALOG_SHIELD_BUTTON_HPP
#define ANALOG_SHIELD_BUTTON_HPP

#include <Arduino.h>
#include "AnalogResolutionCompatibility.h"

//#define REUSEARRAY
//#define USE_ANALOG_RESOLUTION

/**
 * @brief Shield button control to perform control and identify the button ID
*/
class AnalogShieldButton
{
    private:
        unsigned int analogPin;
        size_t activationSize;
        unsigned int* activationValue = nullptr;
        long rawRead;
        AnalogResolution bits_res;
    public:
        AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, AnalogResolution bits_res = BACKWARD_COMPATIBILITY);
        ~AnalogShieldButton();
        size_t getNumButtons();
        unsigned int* getActivationValues();
        int getButton();
        long getLastRawRead();
        void read();
};

#endif // !ANALOG_SHIELD_BUTTON_HPP