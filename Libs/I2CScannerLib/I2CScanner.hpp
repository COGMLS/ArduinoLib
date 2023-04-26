/** I2C Scanner Devices
 * ------------------------------------
 * @brief Scan for I2C device address available
 * 
 * @author Matheus L. Silvati
 * 
 * @version 0.3.2a
 * ------------------------------------
*/

#ifndef I2C_SCANNER_HPP
#define I2C_SCANNER_HPP

#include <Wire.h>

/// @brief I2C Device Report
/// @note -1 means the address/error is unknown or not initialized for use
struct I2CDevice
{
    uint8_t address = -1;
    uint8_t error = -1;
}
typedef I2CDevice;

/// @brief I2C Scanner Device object
class I2CScanner
{
    private:
        TwoWire* wire = nullptr;

        int devicesFounded;
        int errorsFounded;

        I2CDevice* devices = nullptr;

        // Add a new device to I2C Devices array
        void addDevice(uint8_t address, uint8_t error);

        // Remove an device previous added by it's address
        //void remDevice(uint8_t address);
    public:
        /// @brief Create an I2C Scanner device
        /// @param wire Send the wire communication port to use
        I2CScanner(TwoWire &wire);

        ~I2CScanner();

        // Scan for I2C devices
        void scan();

        // Get the number of devices founded
        int getNnumberDevices();

        // Get the number of error founded
        int getNumberErrors();

        // Get a I2C device details by the index
        I2CDevice getDevice(unsigned int index);

        // Get a I2C device details by it's address
        I2CDevice getDevice(uint8_t address);

        // Get all I2C devices reported
        //I2CDevice* getDevices();

        // Get a printable string report
        //char* getReport();
};

#endif // !I2C_SCANNER_HPP