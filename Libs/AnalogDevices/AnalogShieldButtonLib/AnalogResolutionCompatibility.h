#pragma once

#ifndef ANALOG_RESOLUTION_COMPATIBILITY_HPP
#define ANALOG_RESOLUTION_COMPATIBILITY_HPP

typedef enum AnalogResolution : unsigned short
{
    BACKWARD_COMPATIBILITY = 10,
    _12BITS_COMPATIBILITY = 12,
    _16BITS_COMPATIBILITY = 16,
    _32BITS_COMPATIBILITY = 32
};

/**
 * @brief Convert the AnalogResolution enumerator to integer
 * @param res Enum value compatible with AnalogResolution
 * @return Integer value corresponding with the number of bits used to analog resolution
*/
inline int AnalogResolutionToInt(AnalogResolution res)
{
    switch (res)
    {
        case BACKWARD_COMPATIBILITY:
        {
            return 10;
        }
        case _12BITS_COMPATIBILITY:
        {
            return 12;
        }
        case _16BITS_COMPATIBILITY:
        {
            return 16;
        }
        case _32BITS_COMPATIBILITY:
        {
            return 32;
        }
        default:
        {
            return 10;
        }
    }
}

#endif // !ANALOG_RESOLUTION_COMPATIBILITY_HPP