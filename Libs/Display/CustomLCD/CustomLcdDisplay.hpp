/**
 * @short LCD Display Library
 * @author Matheus L. Silvati
 * @version 0.5.12a
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

        /// @brief Columns of lcd
        int cols;
        /// @brief Rows of lcd
        int rows;

        /**
         * Variables available to control the Custom LCD display:
        */

        // @brief Control the auto scroll on LCD display
        bool autoscroll;

        // @brief Control the writing
        bool writeRight2Left;

        // @brief Control the cursor blinking
        bool cursorBlink;

        // @brief Control if cursor if active/deactivate
        bool cursorState;

        // @brief Control the display state
        bool displayState;

        void setDefaultConfig();

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

        void setAutoscroll(bool autoscroll);
        void setCursorBlink(bool cursorBlink);
        void setCursorState(bool cursorState);
        void setCursorPosition(unsigned int col, unsigned int row);
        void setDisplayState(bool displayState);
        void clearDisplay();
        void goHomeDisplay();
        void setWriting(bool leftToRight);
        void scrollDisplay(int scroll);
        void writeCustomChar(unsigned short index);

        void print(const Printable &p);
        void print(const String &s);
        void print(const __FlashStringHelper* fsH);
        void print(const char s[]);
        void print(const unsigned char s[]);
        void print(const char c);
        void print(const unsigned char c);
        void print(const short n, int base = 10);
        void print(const unsigned short n, int base = 10);
        void print(const int n, int base = 10);
        void print(const unsigned int n, int base = 10);
        void print(const long n, int base = 10);
        void print(const unsigned long n, int base = 10);
        void print(const float n, int base = 2);
        void print(const double n, int base = 2);
        
        //void println();
        //void println(const Printable &p);
        //void println(const String &s);
        //void println(const __FlashStringHelper* fsH);
        //void println(const char s[]);
        //void println(const unsigned char s[]);
        //void println(const char c);
        //void println(const unsigned char c);
        //void println(const short n, int base = 10);
        //void println(const unsigned short n, int base = 10);
        //void println(const int n, int base = 10);
        //void println(const unsigned int n, int base = 10);
        //void println(const long n, int base = 10);
        //void println(const unsigned long n, int base = 10);
        //void println(const float n, int base = 2);
        //void println(const double n, int base = 2);
};

#endif // !CUSTOM_LCD_DISPLAY_HPP