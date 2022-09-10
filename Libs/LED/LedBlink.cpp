/**
 * @file LedBlink.cpp
 * 
 * @short Contains the definitions of all functions in LedBlink.hpp
*/

#include "./LedBlink.hpp"

ard::LedBlink::LedBlink(int ledPin, int* blinkTimer, size_t blinkTimerSize)
{
    this->ledPin = ledPin;

    if(this->blinkTimer != NULL)
    {
        this->blinkTimer = blinkTimer;
        this->blinkTimerSize = sizeof(this->blinkTimer) / sizeof(this->blinkTimer[0]);
    }
    else
    {
        this->blinkTimerSize = 0;
    }

    this->getState();       // Reset LED state if is wrong.
}

ard::LedBlink::~LedBlink()
{
    delete[] this->blinkTimer;
    this->blinkTimer = NULL;
}

void ard::LedBlink::blink()
{
    this->getState();       // Reset LED state if is wrong.

    if(this->blinkTimerSize != 0 && this->blinkTimer != NULL)
    {
        for(int i = 0; i < this->blinkTimerSize; i++)
        {
            this->setState(true);
            delay(this->blinkTimer[i] / 2);
            this->setState(false);
            delay(this->blinkTimer[i] / 2);
        }
    }
    else
    {
        this->setState(true);
    }
}

void ard::LedBlink::blink(int delayTimer)
{
    this->getState();       // Reset LED state if is wrong.

    this->setState(true);
    delay(delayTimer / 2);
    this->setState(false);
    delay(delayTimer / 2);
}

void ard::LedBlink::setBlinkTimer(int* blinkTimer, size_t blinkTimerSize)
{
    this->getState();       // Reset LED state if is wrong.

    delete[] this->blinkTimer;
    this->blinkTimer = blinkTimer;

    if(this->blinkTimer != NULL)
    {
        this->blinkTimerSize = sizeof(this->blinkTimer) / sizeof(this->blinkTimer[0]);
    }
    else
    {
        this->blinkTimerSize = 0;
    }
}