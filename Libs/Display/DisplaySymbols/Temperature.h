#pragma once

#ifndef SYMBOL_TEMPERATURE_DISPLAY_H
#define SYMBOL_TEMPERATURE_DISPLAY_H

/**
 * @short Celcius symbol 1
 * @version 1
*/
static byte celcius1Symbol[8] = 
{
    0b01000,
    0b10100,
    0b01000,
    0b00011,
    0b00100,
    0b00100,
    0b00100,
    0b00011
};

/**
 * @short Celcius symbol 2
 * @version 2
*/
static byte celcius2Symbol[8] = 
{
    0b11000,
    0b11011,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00011,
    0b00000
};

/**
 * @short Celcius symbol 3
 * @version 3
*/
static byte celcius3Symbol[8] = 
{
    0b01000,
    0b10100,
    0b01011,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00011
};

/**
 * @short Celcius symbol 4
 * @version 4
*/
static byte celcius4Symbol[8] = 
{
    0b01000,
    0b10100,
    0b01000,
    0b00110,
    0b01001,
    0b01000,
    0b01001,
    0b00110
};

/**
 * @short Fahrenheit symbol 1
 * @version 1
*/
static byte fahrenheit1Symbol[8] = 
{
    0b01000,
    0b10100,
    0b01000,
    0b00111,
    0b00100,
    0b00110,
    0b00100,
    0b00100
};

/**
 * @short Temperature symbol 1
 * @version 1
*/
static byte temp1Symbol[8] = 
{
    0b00100,
    0b01010,
    0b01010,
    0b01010,
    0b01010,
    0b10001,
    0b10001,
    0b01110
};

/**
 * @short Temperature symbol 2
 * @version 2
*/
static byte temp2Symbol[8] = 
{
    0b00100,
    0b01010,
    0b01010,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b01110
};

#endif // !SYMBOL_TEMPERATURE_DISPLAY_H