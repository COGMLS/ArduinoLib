#ifndef ARDUINO_BUTTON_PULLUP_HPP
#define ARDUINO_BUTTON_PULLUP_HPP

class ButtonPullup
{
    private:
        bool buttonStatus;
        int buttonPin;
        int delay;
    public:
        ButtonPullup(int buttonPin);
        ButtonPullup(int buttonPin, int delay);
        ~ButtonPullup();
        void switchStatus();
        void setOn();
        void setOff();
        bool isOn();
};

#endif // ARDUINO_BUTTON_PULLUP_HPP