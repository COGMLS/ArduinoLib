/**
 * @short LCD Display Library
 * @author Matheus L. Silvati
 * @version 0.1.7a
*/

#pragma once

#ifndef CUSTOM_LCD_DISPLAY_HPP
#define CUSTOM_LCD_DISPLAY_HPP

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "displayPinSetup.h"

/**
 * @class CustomLCD
 * @short Custom Liquid Crystal class for more code control.
*/
class CustomLCD
{
    private:
        /// @brief LiquidCrystal variable to access the LCD display
        LiquidCrystal* lcd = nullptr;
        int backlight;

        /// @brief Colluns of lcd
        int cols;
        /// @brief Rows of lcd
        int rows;

    public:
        /**
         * @brief Destructor
        */
        ~CustomLCD();
        
        /**
         * @short Create an LCD display based on default pin positions.
        */
        CustomLCD(uint8_t cols, uint8_t rows);

        /**
         * @short Create an LCD display on specific pins
        */
        CustomLCD(uint8_t cols, uint8_t rows, uint8_t backlight, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

        /**
         * @short Create a custom char on display memory
        */
        void makeCustomChar(uint8_t charIndex, uint8_t &charData);

        /**
         * @short Exposes the lcd class pointer to get directly communication.
         * @return Return an LiquidCrystal pointer for lcd.
        */
        LiquidCrystal* getLCD();

        /**
         * @short Define the backlight ON(true)/OFF(false)
         * @note To use the backlight as digital/PWM signal the pinMode needs be defined.
        */
        void setBacklight(bool value);

        /**
         * @short Define the backlight intensity with analog/PWM signal.
         * @note The values acceptable are between 0 to 255. A low value than 0 will considered as 0 and any value higher than 255 will be considered as 255.
         * @note To use the backlight as digital/PWM signal the pinMode needs be defined.
        */
        void setBacklight(short rawValue);

        /**
         * @short This function display any custom function for the display.
        */
        //void displayFunction(msgType msg, String (*cutomDisplay)());
};

#endif // !CUSTOM_LCD_DISPLAY_HPP