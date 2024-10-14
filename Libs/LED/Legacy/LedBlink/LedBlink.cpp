#include "LedBlink.hpp"

// private functions:

// Make the change ON or OFF
void LedBlink::changeLedStatus()
{
    if(this->ledStatus)
    {
        this->ledStatus = false;
    }
    else
    {
        this->ledStatus = true;
    }

    digitalWrite(this->ledPin, this->ledStatus);
}

void LedBlink::ledBlink()
{
    this->changeLedStatus();
    delay(this->ledDelay);
    this->changeLedStatus();
}

// Constructors and destructor:
LedBlink::LedBlink(int ledPin)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    this->ledDelay = 500;  // 500 ms
    this->blinkStyle = ledBlinkStyle::SIMPLE_BLINK;
    this->ledMultiBlinkInterval = 100;  // 100 ms
    digitalWrite(this->ledPin, this->ledStatus);
}
LedBlink::LedBlink(int ledPin, int ledDelay)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    this->ledDelay = ledDelay;
    this->blinkStyle = ledBlinkStyle::SIMPLE_BLINK;
    this->ledMultiBlinkInterval = 100;  // 100 ms
    digitalWrite(this->ledPin, this->ledStatus);
}
LedBlink::LedBlink(int ledPin, enum ledBlinkStyle blinkStyle)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    this->ledDelay = 500;  // 500 ms
    this->blinkStyle = blinkStyle;
    this->ledMultiBlinkInterval = 100;  // 100 ms
    digitalWrite(this->ledPin, this->ledStatus);
}
LedBlink::LedBlink(int ledPin, int ledDelay, enum ledBlinkStyle blinkStyle)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    this->ledDelay = ledDelay;
    this->blinkStyle = blinkStyle;
    this->ledMultiBlinkInterval = 100;  // 100 ms
    digitalWrite(this->ledPin, this->ledStatus);
}
LedBlink::LedBlink(int ledPin, enum ledBlinkStyle blinkStyle, int ledMultiBlinkInterval)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    this->ledDelay = 500;  // 500 ms
    this->blinkStyle = blinkStyle;
    this->ledMultiBlinkInterval = ledMultiBlinkInterval;
    digitalWrite(this->ledPin, this->ledStatus);
}
LedBlink::LedBlink(int ledPin, int ledDelay, enum ledBlinkStyle blinkStyle, int ledMultiBlinkInterval)
{
    this->ledPin = ledPin;
    this->ledStatus = false;
    this->ledDelay = ledDelay;
    this->blinkStyle = blinkStyle;
    this->ledMultiBlinkInterval = ledMultiBlinkInterval;
    digitalWrite(this->ledPin, this->ledStatus);
}
LedBlink::~LedBlink()
{

}

// Getters:

// Verify if the LED is blinking
bool LedBlink::isBlinking()
{
    if(this->ledBlinking && this->ledStatus)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int LedBlink::getDelayBlinking()
{
    return this->ledDelay;
}

int LedBlink::getMultiBlinkInterval()
{
    return this->ledMultiBlinkInterval;
}

enum ledBlinkStyle LedBlink::getBlinkStyle()
{
    return this->blinkStyle;
}

// Setters:

void LedBlink::setDelayBlinking(int ledDelay)
{
    this->ledDelay = ledDelay;
}
void LedBlink::setMultiBlinkInterval(int ledMultiBlinkInterval)
{
    this->ledMultiBlinkInterval = ledMultiBlinkInterval;
}
void LedBlink::setBlinkStyle(enum ledBlinkStyle blinkStyle)
{
    this->blinkStyle = blinkStyle;
}
void LedBlink::setBlinkStyle(enum ledBlinkStyle blinkStyle, int ledDelay)
{
    this->blinkStyle = blinkStyle;
    this->ledDelay = ledDelay;
}

// Other controls:

// Make the LED blink, if the blinkStyle was setted, otherwise will make the LED ON
void LedBlink::blinkNow()
{
    if(this->blinkStyle == ledBlinkStyle::NO_BLINK)
    {
        // Set LED ON
        this->setOn();
    }
    else if(this->blinkStyle == ledBlinkStyle::SIMPLE_BLINK)
    {
        this->ledBlinking = true;

        // Simple blink
        this->ledBlink();

        this->ledBlinking = false;
    }
    else if(this->blinkStyle == ledBlinkStyle::DUAL_BLINK)
    {
        this->ledBlinking = true;

        // Dual blink
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();

        this->ledBlinking = false;
    }
    else if(this->blinkStyle == ledBlinkStyle::TRIPLE_BLINK)
    {
        this->ledBlinking = true;

        // Triple blink
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();

        this->ledBlinking = false;
    }
    else if(this->blinkStyle == ledBlinkStyle::SIMPLE_DUAL_BLINK)
    {
        this->ledBlinking = true;

        // Simple blink
        this->ledBlink();

        delay(this->ledDelay);
        
        // Dual blink
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();

        this->ledBlinking = false;
    }
    else if(this->blinkStyle == ledBlinkStyle::SIMPLE_TRIPLE_BLINK)
    {
        this->ledBlinking = true;

        // Simple blink
        this->ledBlink();

        delay(this->ledDelay);
        
        // Triple blink
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();

        this->ledBlinking = false;
    }
    else if(this->blinkStyle == ledBlinkStyle::DUAL_TRIPLE_BLINK)
    {
        this->ledBlinking = true;

        // Dual blink
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();

        delay(this->ledDelay);
        
        // Triple blink
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();
        delay(this->ledMultiBlinkInterval);
        this->ledBlink();

        this->ledBlinking = false;
    }
}

// Make the LED OFF, if blinking, but also will set to OFF is blinkStyle is NO_BLINK
void LedBlink::stopBlink()
{
    this->setOff();
}