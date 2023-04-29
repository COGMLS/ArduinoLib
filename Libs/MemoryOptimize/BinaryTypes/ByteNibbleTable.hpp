/**
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
*/

#pragma once

#ifndef MEMORY_OPTIMIZE_BYTE_NIBBLE_TABLE_HPP
#define MEMORY_OPTIMIZE_BYTE_NIBBLE_TABLE_HPP

namespace memopt
{
    typedef struct byte_t
    {
        unsigned char data;

        unsigned char getHighestNibble()
        {
            return ((data & 0b11110000) >> 0b100);
        }

        unsigned char getLowestNibble()
        {
            return (data & 0b00001111);
        }

        void setHighestNibble(unsigned char nibble)
        {
            nibble = (nibble & 0b00001111);		// Make sure that only the values on range 0-15 are available

            nibble = (nibble << 0b100);

            data = (data & 0b00001111);	// Clean the highest nibble
            data = (data | nibble);
        }

        void setLowestNibble(unsigned char nibble)
        {
            nibble = (nibble & 0b00001111);     // Make sure that only the values on range 0-15 are available
            data = (data & 0b11110000);	        // Clean the lowest nibble
            data = (data | nibble);
        }
    };
} // namespace memopt


#endif // !MEMORY_OPTIMIZE_BYTE_NIBBLE_TABLE_HPP