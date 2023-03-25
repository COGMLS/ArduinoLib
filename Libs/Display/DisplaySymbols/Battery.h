#pragma once

#ifndef SYMBOL_BATTERY_DISPLAY_H
#define SYMBOL_BATTERY_DISPLAY_H

/**
 * @short Battery empty symbol
 * @version 1
*/
static byte batteryEmptySymbol[8] = 
{
    0b01110,
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b11111
};

/**
 * @short Battery low symbol
 * @version 1
*/
static byte batteryLowSymbol[8] = 
{
    0b01110,
    0b11111,
    0b10001,
    0b10001,
    0b10001,
    0b10001,
    0b11111,
    0b11111
};

/**
 * @short Battery Medium symbol
 * @version 1
*/
static byte batteryMidSymbol[8] = 
{
    0b01110,
    0b11111,
    0b10001,
    0b10001,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};

/**
 * @short Battery Full symbol
 * @version 1
*/
static byte batteryFullSymbol[8] = 
{
    0b01110,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111
};

/**
 * @short Battery critical symbol
 * @version 1
*/
static byte batteryCriticalSymbol[8] = 
{
    0b01110,
    0b11111,
    0b10101,
    0b10101,
    0b10101,
    0b10001,
    0b10101,
    0b11111
};

/**
 * @short No battery symbol
 * @version 1
*/
static byte noBatterySymbol[8] = 
{
    0b01110,
    0b11111,
    0b10001,
    0b11011,
    0b10101,
    0b11011,
    0b10001,
    0b11111
};

#endif // !SYMBOL_BATTERY_DISPLAY_H