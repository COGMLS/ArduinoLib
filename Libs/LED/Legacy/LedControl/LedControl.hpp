#pragma once

#ifndef ARDUINO_LED_CONTROL_HPP
#define ARDUINO_LED_CONTROL_HPP

class LedControl
{
    protected:
        bool ledStatus;
        int ledPin;
    public:
        // Contructor and destructor:
        LedControl();
        ~LedControl();

        // Getters:
        bool isOn();
        int getPin();

        // Setters:
        void setOn();
        void setOff();
};

#endif // ARDUINO_LED_CONTROL_HPP