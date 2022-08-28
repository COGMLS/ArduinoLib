#ifndef ARDUINO_ANALOG_COMMON_LIB
#define ARDUINO_ANALOG_COMMON_LIB

class AnalogCommon
{
    protected:
        int analogPin;
        int lastReadedVal;
    public:
        AnalogCommon(int analogPin);
        ~AnalogCommon();
        int read();
        int read(int out_min, int out_max);
        void write(int val);
        int getLastRead();
        int getLastRead(int out_min, int out_max);
};

#endif // ARDUINO_ANALOG_COMMON_LIB