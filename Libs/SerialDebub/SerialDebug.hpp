#pragma once

#ifndef SERIAL_DEBUG_LIB_HPP
#define SERIAL_DEBUG_LIB_HPP

#include <USBAPI.h>

#define SERIAL_DEBUGGER_REFERENCE Serial

class SerialDebugger
{
    private:
        void printNibbleAux(unsigned char data, bool printAsNibble, bool highestNibble, bool printHex);

    public:
        SerialDebugger();
        ~SerialDebugger();

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the message
        /// @param message Message content
        void printDebugInfo(const char title[], const char msg[]);

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the value
        /// @param val Value to exibit
        void printDebugInfo(const char title[], int val);

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the value
        /// @param val Value to exibit
        void printDebugInfo(const char title[], unsigned int val);

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the value
        /// @param val Value to exibit
        void printDebugInfo(const char title[], long val);

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the value
        /// @param val Value to exibit
        void printDebugInfo(const char title[], unsigned long val);

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the value
        /// @param val Value to exibit
        void printDebugInfo(const char title[], float val, unsigned short precision = 2);

        /// @brief Print Debug Informations to Serial
        /// @param title Title of the value
        /// @param val Value to exibit
        /// @param precision Define the precision
        void printDebugInfo(const char title[], double val, unsigned short precision = 2);

        /// @brief Print a byte data Debug Informations to Serial
        /// @param title Title of the value
        /// @param data Byte data to be printed on serial
        /// @param printHex Define how will print the byte data, 0 - Binary format, 1 - Hexadecimal
        void printByteDebugInfo(const char title[], unsigned char data, bool printHex);

        /// @brief Print a nibble data Debug Informations to Serial
        /// @param title Title of the value
        /// @param data Byte data to be printed on serial
        /// @param highestNibble Print the highest nibble, otherwise will be printed the lowest
        /// @param printHex Define how will print the byte data, 0 - Binary format, 1 - Hexadecimal
        void printNibbleDebugInfo(const char title[], unsigned char data, bool highestNibble = false, bool printHex = false);
};

#endif // !SERIAL_DEBUG_LIB_HPP