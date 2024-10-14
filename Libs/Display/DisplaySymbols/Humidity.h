#pragma once

#ifndef SYMBOL_HUMIDITY_DISPLAY_H
#define SYMBOL_HUMIDITY_DISPLAY_H

/**
 * @short Humidity symbol 1
 * @version 1
*/
static byte humidity1Symbol[8] = 
{
    0b00100,
    0b00100,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b11111,
    0b01110
};

/**
 * @short Humidity symbol 2
 * @version 2
*/
static byte humidity2Symbol[8] = 
{
    0b00100,
    0b00100,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b10001,
    0b01110
};

#endif // !SYMBOL_HUMIDITY_DISPLAY_H