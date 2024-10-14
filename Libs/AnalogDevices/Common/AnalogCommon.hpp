/**
 * @file AnalogCommon.hpp
 * 
 * @short Basic controls to analog devices.
*/

#pragma once

#ifndef ARDUINO_ANALOG_COMMON_LIB
#define ARDUINO_ANALOG_COMMON_LIB

/// @brief Arduino custom libraries namespace
namespace ard
{
    /**
     * @class AnalogCommon
     * 
     * @short Class with basic controls to analog devices.
    */
    class AnalogCommon
    {
        protected:
            /// @brief Analog device pin number
            int analogPin;

            /// @brief Buffer to access the last data read
            int lastReadVal;
        public:
            /**
             * @fn AnalogCommon(int analogPin)
             * 
             * @short Constructor to define the basic analog device.
            */
            AnalogCommon(int analogPin);

            /**
             * @fn ~AnalogCommon()
             * 
             * @short Destructor of AnalogCommon
            */
            ~AnalogCommon();

            /**
             * @fn int read()
             * 
             * @short Read the analog device pin
             * 
             * @details Read the analog value from the device
             * with value between 0 to 1023.
             * 
             * @return Return a integer (int) value, between 0 to 1023.
            */
            int read();
            
            /**
             * @overload int read(int out_min, int out_max))
             * 
             * @short Read the analog device pin
             * 
             * @details Read the analog value from the device
             * with value between out_min to out_max. This function
             * provides a custom map to define the output range.
             * 
             * @param[in] out_min Minimum output range.
             * @param[in] out_max Maximum output range.
             * 
             * @return Return a integer (int) value, between out_min to out_max.
            */
            int read(int out_min, int out_max);

            /**
             * @fn void write(int val)
             * 
             * @short Send a raw value to analog device.
             * 
             * @details Write an value to analog device between 0 to 255.
             * 
             * @param[in] val Raw integer value to send to device (0 - 255).
             * 
             * @note If the raw value is sended out of the range,
             * the function will detect it and won't send the
             * value.
             * 
             * @return This function don't return.
            */
            void write(int val);

            /**
             * @overload void write(short percentage)
             * 
             * @short Send a percentage value to analog device.
             * 
             * @details Write an value to analog device between 0 to 100.
             * 
             * @param[in] percentage Percentage value to define the PWM output generate.
             * 
             * @note If the percentage value is sended out of the range,
             * the function will detect it and won't send the
             * value.
             * 
             * @return This function don't return.
            */
            void write(short percentage);

            /**
             * @fn int getLastRead()
             * 
             * @short Read the last value stored on buffer.
             * 
             * @return Return the stored buffer from last read.
            */
            int getLastRead();

            /**
             * @overload int getLastRead()
             * 
             * @short Read the last value stored on buffer, and
             * transform to a custom range.
             * 
             * @details Read the last value on buffer from the last
             * read and return the range.
             * 
             * @param[in] out_max Maximum output range.
             * @param[in] out_min Minimum output range.
             * 
             * @return Return the stored buffer from last read on
             * defined range output.
            */
            int getLastRead(int out_max, int out_min);
    };
}   // namespace ard

#endif // ARDUINO_ANALOG_COMMON_LIB