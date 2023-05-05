/** Binary Table Library
 * ------------------------------------
 * @brief Provide an binary table to reduce the quantity of unsigned chareans used on project
 *
 * @details The binary table uses a byte (8-Bits) to store 8 unsigned chareans, instead the traditional unsigned char uses 1 byte to store 0 or 1
 *
 * @author Matheus L. Silvati
 *
 * @version 1.0.1
*/

#pragma once

#ifndef MEMORY_OPTIMIZE_BIN_TABLE_HPP
#define MEMORY_OPTIMIZE_BIN_TABLE_HPP

namespace memopt
{
    /// @brief Provide 8 booleans with only 1 byte space
    /// @note The version 1 has 8 getters and setters to access the binary table
    typedef struct bintable_byte_t
    {
        unsigned char data = 0b00000000;

        unsigned char getBit0()
        {
            return ((data & 0b00000001));               // Select the bit sector
        }

        unsigned char getBit1()
        {
            return ((data & 0b00000010) >> 0b01);       // Select the bit sector and move it to position 0
        }
        unsigned char getBit2()
        {
            return ((data & 0b00000100) >> 0b010);      // Select the bit sector and move it to position 0
        }
        unsigned char getBit3()
        {
            return ((data & 0b00001000) >> 0b011);      // Select the bit sector and move it to position 0
        }
        unsigned char getBit4()
        {
            return ((data & 0b00010000) >> 0b100);      // Select the bit sector and move it to position 0
        }

        unsigned char getBit5()
        {
            return ((data & 0b00100000) >> 0b101);      // Select the bit sector and move it to position 0
        }

        unsigned char getBit6()
        {
            return ((data & 0b01000000) >> 0b110);      // Select the bit sector and move it to position 0
        }

        unsigned char getBit7()
        {
            return ((data & 0b10000000) >> 0b111);      // Select the bit sector and move it to position 0
        }

        void setBit0(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            data = (data & 0b11111110);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit1(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b1);             // Move the bit to the right sector
            data = (data & 0b11111101);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit2(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b10);            // Move the bit to the right sector
            data = (data & 0b11111011);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit3(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b11);            // Move the bit to the right sector
            data = (data & 0b11110111);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit4(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b100);           // Move the bit to the right sector
            data = (data & 0b11101111);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit5(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b101);           // Move the bit to the right sector
            data = (data & 0b11011111);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit6(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b110);           // Move the bit to the right sector
            data = (data & 0b10111111);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }

        void setBit7(unsigned char bit)
        {
            bit = (bit & 0b00000001);       // Make sure just 1 will be set
            bit = (bit << 0b111);           // Move the bit to the right sector
            data = (data & 0b01111111);     // Clean the bit sector status before set a new value
            data = (data | bit);            // Merge the bit with other bits
        }
    };
} // namespace memopt


#endif // !MEMORY_OPTIMIZE_BIN_TABLE_HPP