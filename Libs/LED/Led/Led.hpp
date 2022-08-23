#pragma once

#ifndef ARDUINO_LED_HPP
#define ARDUINO_LED_HPP

#include "../LedControl/LedControl.hpp"

class Led : public LedControl
{
    private:

    public:
        Led(int ledPin);
        ~Led();
};

#endif // ARDUINO_LED_HPP