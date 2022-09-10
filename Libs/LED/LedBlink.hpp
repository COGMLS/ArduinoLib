/**
 * @file LedBlink.hpp
 * 
 * @short This library provides the capability to make LEDs blink with custom timers.
 * 
 * @author Matheus L. Silvati
 * @version 1.0.0
*/

#pragma once

#ifndef LED_BLINK_HPP
#define LED_BLINK_HPP

#include "./LedControl.hpp"

///@namespace ard namespace for Arduino custom libraries
namespace ard
{
    /**
     * @class LedBlink
     * 
     * @short This class provides the capability to make
     * the LED blink with custom timers.
     * 
     * @details The custom timers defined inside the class
     * is a vector of integers that represents the milliseconds
     * will be the delay on turn On and Off. The timer delay
     * use HALF of the time to set as on and other HALF as off.
    */
    class LedBlink : public LedControl
    {
        private:
            /// @brief Vector of integers that represents the milliseconds to delay.
            int* blinkTimer = NULL;

            /// @brief Size of blinkTimer vector.
            size_t blinkTimerSize = 0;
        public:
            /**
             * @fn LedBlink(int ledPin, int* blinkTimer, size_t blinkTimerSize)
             * 
             * @short Led blink constructor to define the led blink property.
             * 
             * @param[in] ledPin Define the LED's pin number
             * @param[in] blinkTimer A pointer/vector of integer(s) to set the timer(s).
             * @param[in] blinkTimerSize Define the timer vector size.
            */
            LedBlink(int ledPin, int* blinkTimer, size_t blinkTimerSize);

            /**
             * @fn ~LedBlink destructor
             * @short LedBlink destructor
            */
            ~LedBlink();

            /**
             * @fn void blink()
             * 
             * @short Make the LED blink, based on timer vector.
             * 
             * @note The LED only blink when the vector pointer
             * isn'tNULL and the size of vector is greater than zero.
             * 
             * @return No return for this function.
            */
            void blink();

            /**
             * @overload void blink(int delayTimer)
             * 
             * @short Make the LED blink, based specific delay timer.
             * 
             * @note This function will ignore the timer vector.
             * 
             * @return No return for this function.
            */
            void blink(int delayTimer);

            /**
             * @fn void setBlinkTimer(int* blinkTimer, size_t blinkTimerSize)
             * 
             * @short Define the Blink Timer vector, with a new one. All the
             * timer is in milliseconds.
             * 
             * @param[in] blinkTimer Vector of integers representing the timer delay in milliseconds.
             * @note The actual storaged vector will be replaced.
             * 
             * @param[in] blinkTimerSize Size of the new vector.
             * 
             * @return No return from this function.
            */
            void setBlinkTimer(int* blinkTimer, size_t blinkTimerSize);
    };
} // namespace ard


#endif // LED_BLINK_HPP