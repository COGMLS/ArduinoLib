#pragma once

#ifndef ARDUINO_LED_BLINK_HPP
#define ARDUINO_LED_BLINK_HPP

#include "../LedControl/LedControl.hpp"

enum ledBlinkStyle
{
    NO_BLINK,               // No LED blink
    SIMPLE_BLINK,           // Make a simple LED blink
    DUAL_BLINK,             // Make a dual LED blink
    TRIPLE_BLINK,           // Make a triple LED blink
    SIMPLE_DUAL_BLINK,      // Make a simple LED blink and a next dual blink
    SIMPLE_TRIPLE_BLINK,    // Make a simple LED blink and a next triple blink
    DUAL_TRIPLE_BLINK       // Make a dual LED blink and a triple blink
};

class LedBlink : public LedControl
{
    private:
        bool ledBlinking;                   // Define if the LED is blinking or not
        int ledDelay;                       // Define the LED blink
        int ledMultiBlinkInterval;          // Define the LED multi blinking style interval
        enum ledBlinkStyle blinkStyle;      // Define the LED blink style

        // private functions:
        void changeLedStatus();             // Make the change ON or OFF
        void ledBlink();                    // Switch ON and OFF the LED with the delay
    public:
        // Constructors and destructor:
        LedBlink(int ledPin);
        LedBlink(int ledPin, int ledDelay);
        LedBlink(int ledPin, enum ledBlinkStyle blinkStyle);
        LedBlink(int ledPin, int ledDelay, enum ledBlinkStyle blinkStyle);
        LedBlink(int ledPin, enum ledBlinkStyle blinkStyle, int ledMultiBlinkInterval);
        LedBlink(int ledPin, int ledDelay, enum ledBlinkStyle blinkStyle, int ledMultiBlinkInterval);
        ~LedBlink();

        // Getters:
        bool isBlinking();                  // Verify if the LED is blinking
        int getDelayBlinking();
        int getMultiBlinkInterval();
        enum ledBlinkStyle getBlinkStyle();

        // Setters:
        void setDelayBlinking(int ledDelay);
        void setMultiBlinkInterval(int ledMultiBlinkInterval);
        void setBlinkStyle(enum ledBlinkStyle blinkStyle);
        void setBlinkStyle(enum ledBlinkStyle blinkStyle, int ledDelay);

        // Other controls:
        void blinkNow();        // Make the LED blink, if the blinkStyle was setted, otherwise will make the LED ON
        void stopBlink();       // Make the LED OFF, if blinking, but also will set to OFF is blinkStyle is NO_BLINK
};

#endif // ARDUINO_LED_BLINK_HPP