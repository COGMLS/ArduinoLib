#include "ButtonPullup.hpp"

ButtonPullup::ButtonPullup(int buttonPin)
{
    this->buttonStatus = false;
    this->buttonPin = buttonPin;
    this->delayPullup = 200;  // 200 ms of delayPullup;
}

ButtonPullup::ButtonPullup(int buttonPin, int delayPullup)
{
    this->buttonStatus = false;
    this->buttonPin = buttonPin;
    this->delayPullup = delayPullup;
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
    delayPullup(this->delayPullup);
    digitalWrite(this->buttonStatus, buttonStatus);
}

void ButtonPullup::setOn()
{
    this->buttonStatus = true;
    delayPullup(this->delayPullup);
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