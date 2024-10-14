/**
 * @file LedControl.hpp
 * 
 * @short This library provides the base controls
 * to use LED's on Arduino boards.
 * 
 * @author Matheus L. Silvati
 * @version 1.0.0
*/

#pragma once

#ifndef LED_CONTROL_HPP
#define LED_CONTROL_HPP

///@namespace ard namespace for Arduino custom libraries
namespace ard
{
    /**
     * @class LedControl
     * 
     * @short Base class to control LED's on Arduino boards.
     * 
     * @details This class can provide basic functionality
     * or be used for inherence classes.
    */
    class LedControl
    {
        protected:
            /// @brief Define the pin number to control the LED.
            int ledPin;

            /// @brief Define the LED status as ON (true) or OFF (false).
            bool ledStatus;
        public:
            /**
             * @fn LedControl()
             * @short Empty constructor for LedControl class, used for inherence classes.
            */
            LedControl();

            /**
             * @fn LedControl(int ledPin)
             * @short Constructor for basic LED functionality, to turn ON/OFF.
             * @param[in] ledPin Define the LED's pin number.
            */
           LedControl(int ledPin);

            /**
             * @fn ~LedControl()
             * @short LedControl destructor
            */
            ~LedControl();

            /**
             * @fn void setState(bool state)
             * @short Set the LED to ON with true or OFF with false.
            */
           void setState(bool state);

           /**
            * @fn bool getState()
            * @short Get the LED status as true (ON) and false (OFF)
            * @note When getting the state information (ledStatus)
            * the variable will be checked with the real digital reading
            * from Arduino's board and change it in case the ledStatus is
            * not representing the real situation.
            * 
            * @return This function return a boolean value.
           */
          bool getState();
    };
} // namespace ard

#endif // LED_CONTROL_HPP