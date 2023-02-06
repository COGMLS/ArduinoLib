#include "ButtonPullup.hpp"

ard::ButtonPullup::ButtonPullup(int buttonPin)
{
    this->buttonStatus = false;
    this->buttonPin = buttonPin;
    this->pullupDelay = 200;  // 200 ms of pullupDelay;
}

ard::ButtonPullup::ButtonPullup(int buttonPin, int pullupDelay)
{
    this->buttonStatus = false;
    this->buttonPin = buttonPin;
    this->pullupDelay = pullupDelay;
}

ard::ButtonPullup::~ButtonPullup()
{

}

bool ard::ButtonPullup::read()
{
    if(digitalRead(this->buttonPin))
    {
        delay(this->pullupDelay);
        if(!digitalRead(this->buttonPin))
        {
            if(this->activatePullupStatus)
            {
                this->activatePullupStatus = false;
            }
            else
            {
                this->activatePullupStatus = true;
            }

            return true;
        }
        
        return false;
    }

    return false;
}