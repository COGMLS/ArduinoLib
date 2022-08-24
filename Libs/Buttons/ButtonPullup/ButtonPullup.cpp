#include "ButtonPullup.hpp"

ButtonPullup::ButtonPullup(int buttonPin)
{
    this->buttonStatus = false;
    this->buttonPin = buttonPin;
    this->delay = 200;  // 200 ms of delay;
}

ButtonPullup::ButtonPullup(int buttonPin, int delay)
{
    this->buttonStatus = false;
    this->buttonPin = buttonPin;
    this->delay = delay;
}

ButtonPullup::~ButtonPullup()
{

}

bool ButtonPullup::isOn()
{
    return this->buttonStatus;
}

void ButtonPullup::setOff()
{
    this->buttonStatus = false;
    delay(this->delay);
    digitalWrite(this->buttonStatus, buttonStatus);
}

void ButtonPullup::setOn()
{
    this->buttonStatus = true;
    delay(this->delay);
    digitalWrite(this->buttonStatus, buttonStatus);
}

void ButtonPullup::switchStatus()
{
    if(this->buttonStatus)
    {
        this->setOff();
    }
    else
    {
        this->setOff();
    }
}