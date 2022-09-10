#ifndef ARDUINO_BUTTON_PULLUP_HPP
#define ARDUINO_BUTTON_PULLUP_HPP

class ButtonPullup
{
    private:
        bool buttonStatus;
        int buttonPin;
        int delayPullup;
    public:
        ButtonPullup(int buttonPin);
        ButtonPullup(int buttonPin, int delayPullup);
        ~ButtonPullup();
        void switchStatus();
        void setOn();
        void setOff();
        bool isOn();
};

#endif // ARDUINO_BUTTON_PULLUP_HPP