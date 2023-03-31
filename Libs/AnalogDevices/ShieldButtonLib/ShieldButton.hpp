#pragma once

#ifndef SHIELD_BUTTON_HPP
#define SHIELD_BUTTON_HPP

/**
 * @brief ButtonID to identify the button and the activation value (rawVal)
*/
struct ButtonID
{
    unsigned int rawVal;
    unsigned int buttonID;
}
typedef ButtonID;

/**
 * @brief Shield button control to perform control and identify the button ID
*/
class ShieldButton
{
    private:
        unsigned int analogPin;
        unsigned int activationSize;
        ButtonID* activationValue = nullptr;
    public:
        ShieldButton(unsigned int analogPin, ButtonID idArr[]);
        ~ShieldButton();
        int getButton();
};

#endif // !SHIELD_BUTTON_HPP