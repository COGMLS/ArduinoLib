/**
 * @file ButtonPullup.hpp
 * 
 * @short Library to control the button pullup.
*/

#pragma once

#ifndef ARDUINO_BUTTON_PULLUP_HPP
#define ARDUINO_BUTTON_PULLUP_HPP

namespace ard
{
    /**
     * @class ButtonPullup
     * 
     * @short Class to control the button pullup.
    */
    class ButtonPullup
    {
        private:
            /// @brief Activation from pullup status to define is ON (true) or OFF (false)
            bool activatePullupStatus;

            /// @brief Button pin number
            int buttonPin;

            /// @brief Delay to read the pullup.
            int pullupDelay;
        public:
            /**
             * @fn ButtonPullup(int buttonPin)
             * 
             * @short Constructor using default pullup delay.
             * 
             * @param[in] buttonPin Define the button pullup pin.
            */
            ButtonPullup(int buttonPin);

            /**
             * @fn ButtonPullup(int buttonPin, int pullupDelay)
             * 
             * @short Constructor with pin number and delay pullup definitions.
             * 
             * @param[in] buttonPin Define the button pullup pin.
             * @param[in] pullupDelay Define the button pullup delay when read the button.
            */
            ButtonPullup(int buttonPin, int pullupDelay);

            /**
             * @fn ~ButtonPullup()
             * 
             * @short Destructor of button pullup object control.
            */
            ~ButtonPullup();
            
            /**
             * @fn bool read()
             * 
             * @short Read the button input on digital signal
             * 
             * @return This function return true as a HIGH (5v or 3.3v) value and false as a LOW value (0v)
            */
            bool read();

            /**
             * @fn bool isActive()
             * 
             * @short This function provides support for operations that are activate ou deactivate from button pullup operation.
             * 
             * @return 
            */
    };
}

#endif // ARDUINO_BUTTON_PULLUP_HPP