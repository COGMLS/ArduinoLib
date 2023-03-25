#pragma once

#ifndef SYMBOL_SERIAL_DEBUG_DISPLAY_H
#define SYMBOL_SERIAL_DEBUG_DISPLAY_H

/**
 * @short Debug/Serial symbol 1
 * @version 1
*/
static byte debug_SerialSymbol1[8] = 
{
    0b00100,
    0b00101,
    0b10101,
    0b10101,
    0b10110,
    0b01100,
    0b00100,
    0b00100
};

/**
 * @short Debug/Serial symbol 2
 * @version 2
*/
static byte debug_SerialSymbol2[8] = 
{
    0b11111,
    0b00000,
    0b11111,
    0b11111,
    0b00000,
    0b01110,
    0b00000,
    0b11111
};

/**
 * @short Debug/Serial symbol 3
 * @version 3
*/
static byte debug_SerialSymbol3[8] = 
{
    0b11111,
    0b10001,
    0b10001,
    0b11111,
    0b01110,
    0b11111,
    0b11101,
    0b11111
};

#endif // !SYMBOL_SERIAL_DEBUG_DISPLAY_H