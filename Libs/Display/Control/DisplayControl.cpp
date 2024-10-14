#include "DisplayControl.hpp"

// Contructors and destructor:
DisplayControl::DisplayControl()
{
    this->backlightStatus = false;
    this->cursorCoordinates.cursorCoordinatesX = 0;
    this->cursorCoordinates.cursorCoordinatesY = 0;
    this->maxCursorCoordinates.cursorCoordinatesX = 0;
    this->maxCursorCoordinates.cursorCoordinatesY = 0;
}
DisplayControl::DisplayControl(void* displayController, const int maxCursorCoordinatesX, const int maxCursorCoordinatesY, bool backlightStatus)
{
    this->displayController = displayController;
    this->backlightStatus = backlightStatus;
    this->cursorCoordinates.cursorCoordinatesX = 0;
    this->cursorCoordinates.cursorCoordinatesY = 0;
    this->maxCursorCoordinates.cursorCoordinatesX = maxCursorCoordinatesX;
    this->maxCursorCoordinates.cursorCoordinatesY = maxCursorCoordinatesY;

    // Create the vector pointer p and create internal vectors of pointers, to define the buffer
    char*** p = new char**[maxCursorCoordinatesX];

    for(int i = 0; i < maxCursorCoordinatesX; i++)
    {
        p[i] = new char*[maxCursorCoordinatesY];
    }

    this->screenBuffer = p;

    p = nullptr;
}
DisplayControl::~DisplayControl()
{

}

// Getters:

// Verify if the backlight is ON (true) or OFF (false)
bool DisplayControl::getBacklight()
{
    return this->backlightStatus;
}

// Get the cursor coordinates structure
struct DisplayControlCursor DisplayControl::getCursorCoordinates()
{
    return this->cursorCoordinates;
}

// Get the screen buffer data
char*** DisplayControl::getScreenBuffer()
{
    return this->screenBuffer;
}

// Setters:

// Set ON (true) or OFF (false) the backlight display
void DisplayControl::setBacklight(bool backlightStatus)
{
    this->backlightStatus = backlightStatus;
}

// Set the cursor coordinates
void DisplayControl::setCursorCoordinates(int x, int y)
{
    if(x >= 0 && x < this->maxCursorCoordinates.cursorCoordinatesX && y >= 0 && y < this->maxCursorCoordinates.cursorCoordinatesY)
    {
        this->cursorCoordinates.cursorCoordinatesX = x;
        this->cursorCoordinates.cursorCoordinatesY = y;
    }
}

// Define the screen buffer;
bool DisplayControl::setScreenBuffer(char* buffer)
{
    return true;
}

// Other controls:
void DisplayControl::switchBacklight()
{
    if(this->backlightStatus)
    {
        this->backlightStatus = false;
        // Make backlight off
    }
    else
    {
        this->backlightStatus = true;
        // Make backlight on
    }
}

// Clean the screen, but not the Display Control buffer
void DisplayControl::cleanScreen()
{

}

// Clean the buffer
void DisplayControl::cleanBuffer()
{
    for(int i = 0; i < this->maxCursorCoordinates.cursorCoordinatesX; i++)
    {
        for(int j = 0; j < this->maxCursorCoordinates.cursorCoordinatesY; j++)
        {
            this->screenBuffer[i][j] = " ";
        }
    }
}

// Make the display refresh with the buffer
void DisplayControl::refreshScreen()
{

}

// Make the display refresh only a specific line buffer
void DisplayControl::refreshScreenLine(int y)
{

}

// Make the display refresh only a specific row buffer
void DisplayControl::refreshScreenRow(int x)
{

}

// Move the cursor to coordinates x,y
void DisplayControl::moveCursor(int x, int y)
{

}

// Write a buffer content
int DisplayControl::writeBuffer(char* contentBuffer, int maxContentBufferX, int maxContentBufferY)
{

}