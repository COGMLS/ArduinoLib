/** Byte Nibble Table Library
 * ------------------------------------
 * @brief Provide an nibble level data control to store two diferent datas in one byte
 * 
 * @author Matheus L. Silvati
 * 
 * @version 1.2.0
 * 
 * @note This library don't define the byte type, but uses the unsigned char as a byte
*/

#pragma once

#ifndef MEMORY_OPTIMIZE_BYTE_NIBBLE_TABLE_HPP
#define MEMORY_OPTIMIZE_BYTE_NIBBLE_TABLE_HPP

namespace memopt
{
    typedef struct nibble_t
    {
        unsigned char data;

        /// @brief Get highest nibble in data byte
        /// @return A nibble transformed in unsigned char (1 byte)
        unsigned char getHighestNibble()
        {
            return ((data & 0b11110000) >> 0b100);
        }

        /// @brief Get lowest nibble in data byte
        /// @return A nibble transformed in unsigned char (1 byte)
        unsigned char getLowestNibble()
        {
            return (data & 0b00001111);
        }

        /// @brief Set the highest nibble data
        /// @param nibble An unsigned char (1 byte data) that only will be considered the first nibble (0xFF)
        void setHighestNibble(unsigned char nibble)
        {
            nibble = (nibble & 0b00001111);		// Make sure that only the values on range 0-15 are available

            nibble = (nibble << 0b100);

            data = (data & 0b00001111);	// Clean the highest nibble
            data = (data | nibble);
        }

        /// @brief Set the lowest nibble data
        /// @param nibble An unsigned char (1 byte data) that only will be considered the first nibble (0xFF)
        void setLowestNibble(unsigned char nibble)
        {
            nibble = (nibble & 0b00001111);     // Make sure that only the values on range 0-15 are available
            data = (data & 0b11110000);	        // Clean the lowest nibble
            data = (data | nibble);
        }
    };
} // namespace memopt


#endif // !MEMORY_OPTIMIZE_BYTE_NIBBLE_TABLE_HPP