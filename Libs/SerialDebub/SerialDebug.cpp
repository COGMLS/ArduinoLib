#include "SerialDebug.hpp"

SerialDebugger::SerialDebugger()
{

}

SerialDebugger::~SerialDebugger()
{

}

void SerialDebugger::printDebugInfo(const char title[], const char msg[])
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(msg);
}

void SerialDebugger::printDebugInfo(const char title[], int val)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(val);
}

void SerialDebugger::printDebugInfo(const char title[], unsigned int val)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(val);
}

void SerialDebugger::printDebugInfo(const char title[], long val)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(val);
}

void SerialDebugger::printDebugInfo(const char title[], unsigned long val)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(val);
}

void SerialDebugger::printDebugInfo(const char title[], float val, unsigned short precision)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(val, precision);
}

void SerialDebugger::printDebugInfo(const char title[], double val, unsigned short precision)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);
    SERIAL_DEBUGGER_REFERENCE.println(val, precision);
}

void SerialDebugger::printByteDebugInfo(const char title[], unsigned char data, bool printHex)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);

    if (printHex)
    {
        SERIAL_DEBUGGER_REFERENCE.print("0x");
    }
    else
    {
        SERIAL_DEBUGGER_REFERENCE.print("0b");
    }

    // Print the highest nibble first:
    SerialDebugger::printNibbleAux(data, false, true, printHex);

    // Print the lowest nibble:
    SerialDebugger::printNibbleAux(data, false, false, printHex);

    SERIAL_DEBUGGER_REFERENCE.println("");
}

void SerialDebugger::printNibbleDebugInfo(const char title[], unsigned char data, bool highestNibble, bool printHex)
{
    SERIAL_DEBUGGER_REFERENCE.print(title);

    if (printHex)
    {
        SERIAL_DEBUGGER_REFERENCE.print("0x");
    }
    else
    {
        SERIAL_DEBUGGER_REFERENCE.print("0b");
    }

    SerialDebugger::printNibbleAux(data, true, highestNibble, printHex);

    SERIAL_DEBUGGER_REFERENCE.println("");
}

void SerialDebugger::printNibbleAux(unsigned char data, bool printAsNibble, bool highestNibble, bool printHex)
{
    // Extract the nible data
    if (highestNibble)
    {
        data = ((data & 0b11110000) >> 0b100);
    }
    else
    {
        data = (data & 0b00001111);
    }

    // Print extra zeros if want to print full nibble.
    if (printAsNibble && !printHex)
    {
        if (data <= 0b1)
        {
            SERIAL_DEBUGGER_REFERENCE.print("000");
        }
        else if (data <= 0b11)
        {
            SERIAL_DEBUGGER_REFERENCE.print("00");
        }
        else if (data <= 0b111)
        {
            SERIAL_DEBUGGER_REFERENCE.print("0");
        }
    }

    // Print the nibble data
    switch (data)
    {
        case 0x0:
        {
            SERIAL_DEBUGGER_REFERENCE.print("0");
            break;
        }
        case 0x1:
        {
            SERIAL_DEBUGGER_REFERENCE.print("1");
            break;
        }
        case 0x2:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("2");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("10");
            }
            break;
        }
        case 0x3:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("3");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("11");
            }
            break;
        }
        case 0x4:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("4");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("100");
            }
            break;
        }
        case 0x5:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("5");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("101");
            }
            break;
        }
        case 0x6:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("6");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("110");
            }
            break;
        }
        case 0x7:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("7");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("111");
            }
            break;
        }
        case 0x8:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("8");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1000");
            }
            break;
        }
        case 0x9:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("9");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1001");
            }
            break;
        }
        case 0xA:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("A");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1010");
            }
            break;
        }
        case 0xB:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("B");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1011");
            }
            break;
        }
        case 0xC:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("C");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1100");
            }
            break;
        }
        case 0xD:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("D");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1101");
            }
            break;
        }
        case 0xE:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("E");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1110");
            }
            break;
        }
        case 0xF:
        {
            if (printHex)
            {
                SERIAL_DEBUGGER_REFERENCE.print("F");
            }
            else
            {
                SERIAL_DEBUGGER_REFERENCE.print("1111");
            }
            break;
        }
    }
}