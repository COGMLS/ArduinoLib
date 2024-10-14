/** Analog Shield Button Library
 * ------------------------------------
 * @brief Provide simple way to determinate what button was pressed in an analog shield button, detecting the analog input with different resistances associated with each button.
 * 
 * @anchor Matheu L. Silvati
 * @version 2.1.0
 * 
 * @date 2023/05/09
*/

#pragma once

#ifndef ANALOG_SHIELD_BUTTON_HPP
#define ANALOG_SHIELD_BUTTON_HPP

#include <Arduino.h>
#include "AnalogResolutionCompatibility.h"

//#define REUSEARRAY
//#define USE_ANALOG_RESOLUTION

/**
 * @brief Analog Shield Button control to perform control and identify the button ID. The AnalogShieldButton identify the FIRST button that has the raw reading as the lowest value possible inside the idArr.
 * 
 * @note Verify the maximum value that your board can read and make the test with the buttons to determinate the value to identify it.
 * @note The AnalogShieldButton don't have an tolerance value to identify the buttons, to avoid extra CPU cycles. Add a value from the raw readings to avoid identification fail.
 * @note The button ID correspond with the array's index.
 * @note bits_res or Bits Resolution isn't active in this version.
*/
class AnalogShieldButton
{
    private:
        unsigned int analogPin;                     // Analog pin address
        size_t activationSize;                      // Activation Values Array size
        unsigned int* activationValue = nullptr;    // Activation Values Array pointer
        unsigned int rawRead;                       // Register for raw analog reading
        unsigned int threshold;                     // Threshold to determinate if will consider the value checking or not
        bool useFastCheck;                          // Fast checking the Activation Values array, will check between each value or not. If true will only check for the first lowest value founded, otherwise will make an more precision checking.
        AnalogResolution bits_res;                  // Analog bit resolution to determinate the units per voltage (2 ^ bits_res). Ex: 2 ^ 10 = 1024; 0 - 1023.

        // Internal function to make an fast button value checking
        int verifyButton_FastCheck();

        // Internal function to make an more precise button value checking
        int verifyButton_PrecisionCheck();
    public:
        /// @brief Create an object to represent the AnalogShieldButton
        /// @param analogPin Analog pin address
        /// @param idArr Array with analog values reference to identify the button
        /// @param arrSize Determinate the array size
        /// @param bits_res Determinate the reading precision. Your board need be compatible with higher values. By default the 10-bits reading resolution is applyed
        AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, AnalogResolution bits_res = BACKWARD_COMPATIBILITY);

        /// @brief Create an object to represent the AnalogShieldButton
        /// @param analogPin Analog pin address
        /// @param idArr Array with analog values reference to identify the button
        /// @param arrSize Determinate the array size
        /// @param useFastCheck Determinate if will use an less precision value checking or not
        /// @param bits_res Determinate the reading precision. Your board need be compatible with higher values. By default the 10-bits reading resolution is applyed
        AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, bool useFastCheck, AnalogResolution bits_res = BACKWARD_COMPATIBILITY);
        
        /// @brief Create an object to represent the AnalogShieldButton
        /// @param analogPin Analog pin address
        /// @param idArr Array with analog values reference to identify the button
        /// @param arrSize Determinate the array size
        /// @param threshold Limit to ignore other values, specially micro voltages reading, when using an voltage divisor to build the analog shield.
        /// @param bits_res Determinate the reading precision. Your board need be compatible with higher values. By default the 10-bits reading resolution is applyed
        AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, unsigned int threshold, AnalogResolution bits_res = BACKWARD_COMPATIBILITY);

        /// @brief Create an object to represent the AnalogShieldButton
        /// @param analogPin Analog pin address
        /// @param idArr Array with analog values reference to identify the button
        /// @param arrSize Determinate the array size
        /// @param threshold Limit to ignore other values, specially micro voltages reading, when using an voltage divisor to build the analog shield.
        /// @param useFastCheck Determinate if will use an less precision value checking or not
        /// @param bits_res Determinate the reading precision. Your board need be compatible with higher values. By default the 10-bits reading resolution is applyed
        AnalogShieldButton(unsigned int analogPin, unsigned int idArr[], size_t arrSize, unsigned int threshold, bool useFastCheck, AnalogResolution bits_res = BACKWARD_COMPATIBILITY);

        ~AnalogShieldButton();
        
        /// @brief Get the number of buttons managed by Analog Shield Button object
        /// @return Number of buttons
        size_t getNumButtons();

        /// @brief Get the activation value inside the button id array
        /// @return Activation value array
        unsigned int* getActivationValues();

        /// @brief Identify the last button pressed when the read function was callled
        /// @return Button ID
        int getButton();

        /// @brief Get the raw reading from the last button pressed when the read function was callled
        /// @return Raw value from analog reading
        unsigned int getLastRawRead();

        /// @brief Read the analog shield button and store the value to identify the button or get the raw value
        void read();
};

#endif // !ANALOG_SHIELD_BUTTON_HPP