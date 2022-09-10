/**
 * @file LedControl.cpp
 * @short This file contains the definitions of LedControl class.
 * 
 * @author Matheus L. Silvati
 * @version 1.0.0
*/

#include "./LedControl.hpp"

ard::LedControl::LedControl()
{

}

ard::LedControl::LedControl(int ledPin)
{
    this->ledPin = ledPin;
    this->ledStatus = false;

    // Make sure the LED will be starting as OFF.
    digitalWrite(this->ledPin, this->ledStatus);
}

ard::LedControl::~LedControl()
{

}

void ard::LedControl::setState(bool state)
{
    // Check if the new state is different of ledState
    if(this->ledStatus != state)
    {
        this->ledStatus = state;

        // In case the value was changed, set the new LED status
        digitalWrite(this->ledPin, this->ledStatus);
    }
}

bool ard::LedControl::getState()
{
    // Get the real situation on LED's pin and compare with the ledStatus.
    if(digitalRead(this->ledPin) != this->ledStatus)
    {
        // On divergences, change the value
        if(this->ledStatus)
        {
            this->ledStatus = false;
        }
        else
        {
            this->ledStatus = true;
        }
    }

    // Return the real LED's state.
    return this->ledStatus;
}