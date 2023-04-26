#include "I2CScanner.hpp"


I2CScanner::I2CScanner(TwoWire &wire)
{
    this->wire = &wire;
    this->devices = nullptr;
    this->devicesFounded = -1;  // Means the I2C Scanner was only created
    this->errorsFounded = -1;   // Means the I2C Scanner was only created
}

I2CScanner::~I2CScanner()
{
    this->wire = nullptr;

    if (this->devices != nullptr)
    {
        delete[] this->devices;
        this->devices = nullptr;
    }
}

void I2CScanner::addDevice(uint8_t address, uint8_t error)
{
    this->devicesFounded++;

    if (this->devices == nullptr)
    {
        this->devices = new I2CDevice[this->devicesFounded];
        this->devices[0].address = address;
        this->devices[0].error = error;
    }
    else
    {
        // Create a new list with one more device
        I2CDevice* tmpDvc = new I2CDevice[this->devicesFounded];

        // Copy the devices already founded to tmpDvc
        for (int i = 0; i < this->devicesFounded--; i++)
        {
            tmpDvc[i] = this->devices[i];
        }

        // Add the new device
        tmpDvc[this->devicesFounded].address = address;
        tmpDvc[this->devicesFounded].error = error;

        // Remove the old data and switch the pointers
        delete[] this->devices;
        this->devices = tmpDvc;
        tmpDvc = nullptr;
    }
}

void I2CScanner::scan()
{
    this->devicesFounded = 0;
    this->errorsFounded = 0;

    // Remove previous scan data to avoid problems
    if (this->devices != nullptr)
    {
        delete[] this->devices;
        this->devices = nullptr;
    }

    uint8_t error;

    for (uint8_t address = 0; address < 127; address++)
    {
        this->wire->beginTransmission(address);

        error = this->wire->endTransmission();

        /**
         * 0 - Success
         * 2 - Sended address, nothing receaved
         * 3 - Sended data, nothing receaved
         * X - Other error
        */

        if (error != 0)
        {
            this->errorsFounded++;
        }
        else
        {
            this->devicesFounded++;
        }

        addDevice(address, error);
    }
}

int I2CScanner::getNnumberDevices()
{
    return this->devicesFounded;
}

int I2CScanner::getNumberErrors()
{
    return this->errorsFounded;
}

I2CDevice I2CScanner::getDevice(unsigned int index)
{
    if (index >= 127 || index >= this->devicesFounded)
    {
        return I2CDevice();
    }
    
    return this->devices[index];
}

I2CDevice I2CScanner::getDevice(uint8_t address)
{
    if (address >= 127)
    {
        return I2CDevice();
    }

    for (uint8_t i = 0; i < this->devicesFounded; i++)
    {
        if (this->devices[i].address == address)
        {
            return this->devices[i];
        }
    }

    return I2CDevice();
}

