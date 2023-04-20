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

void SerialDebugger::printByteDebugInfo(const char title[], byte data)
{
    
}

void SerialDebugger::printNibbleDebugInfo(const char title[], byte data, bool highestNibble)
{
    
}