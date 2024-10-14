#pragma once

#ifndef ARDUINO_DISPLAY_CONTROL_HPP
#define ARDUINO_DISPLAY_CONTROL_HPP

struct DisplayControlCursor
{
    int cursorCoordinatesX;             // Actual cursor coordinates on X axis
    int cursorCoordinatesY;             // Actual cursor coordinates on Y axis
};

class DisplayControl
{
    protected:
        void* displayController = nullptr;                      // Generic pointer to display controller
        bool backlightStatus;                                   // Backlight status
        char*** screenBuffer = nullptr;                         // Pointer to a custom screen buffer used to keep updated the content
        struct DisplayControlCursor cursorCoordinates;         // Actual cursor coordinates
        struct DisplayControlCursor maxCursorCoordinates;      // Maximum cursor coordinates to navigate in screen buffer

        // Protected setters:
        virtual void setMaxCursorCoordinates(int x, int y);     // Only for inheritance classes.
    public:
        // Constructors and destructor:
        DisplayControl();
        DisplayControl(void* displayController, const int maxCursorCoordinatesX, const int maxCursorCoordinatesY, bool backlightStatus);
        ~DisplayControl();

        // Getters:
        bool getBacklight();
        struct DisplayControlCursor getCursorCoordinates();
        char*** getScreenBuffer();

        // Setters:
        void setBacklight(bool backlightStatus);
        void setCursorCoordinates(int x, int y);
        bool setScreenBuffer(char* buffer);

        // Other controls:
        void switchBacklight();
        void cleanScreen();
        void cleanBuffer();
        void refreshScreen();
        void refreshScreenLine(int y);
        void refreshScreenRow(int x);
        void moveCursor(int x, int y);
        int writeBuffer(char* contentBuffer, int maxContentBufferX, int maxContentBufferY);
};

#endif // ARDUINO_DISPLAY_CONTROL_HPP