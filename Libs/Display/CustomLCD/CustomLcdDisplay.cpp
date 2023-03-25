#include "CustomLcdDisplay.hpp"

CustomLCD::~CustomLCD()
{
    delete this->lcd;
    this->lcd = nullptr;
}

CustomLCD::CustomLCD(uint8_t cols, uint8_t rows)
{
    const int rs = DEFAULTDISPLAYPIN_RS, en = DEFAULTDISPLAYPIN_EN, d4 = DEFAULTDISPLAYPIN_D4, d5 = DEFAULTDISPLAYPIN_D5, d6 = DEFAULTDISPLAYPIN_D6, d7 = DEFAULTDISPLAYPIN_D7;
    const int backlight = DEFAULTDISPLAYPIN_BACKLIGHT;

    this->lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    lcd->begin(cols, rows);

    this->backlight = backlight;
    this->cols = cols;
    this->rows = rows;

    pinMode(this->backlight, OUTPUT);

    this->setDefaultConfig();
}

CustomLCD::CustomLCD(uint8_t cols, uint8_t rows, uint8_t backlight, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
    this->lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    this->lcd->begin(cols, rows);

    this->backlight = backlight;
    this->cols = cols;
    this->rows = rows;

    pinMode(this->backlight, OUTPUT);

    this->setDefaultConfig();
}

void CustomLCD::makeCustomChar(uint8_t charIndex, uint8_t &charData)
{
    this->lcd->createChar(charIndex, &charData);
}

LiquidCrystal* CustomLCD::getLCD()
{
    return this->lcd;
}

void CustomLCD::setBacklight(bool value)
{
    if (value)
    {
        digitalWrite(this->backlight, true);
    }
    else
    {
        digitalWrite(this->backlight, false);
    }
}

void CustomLCD::setBacklight(short rawValue)
{
    if (rawValue <= 0)
    {
        analogWrite(this->backlight, 0);
    }
    else if (rawValue >= 255)
    {
        analogWrite(this->backlight, 255);
    }
    else
    {
        analogWrite(this->backlight, rawValue);
    }
}

void CustomLCD::setAutoscroll(bool autoscroll)
{
    this->autoscroll = autoscroll;

    if (this->autoscroll)
    {
        this->lcd->autoscroll();
    }
    else
    {
        this->lcd->noAutoscroll();
    }
}

void CustomLCD::setCursorBlink(bool cursorBlink)
{
    this->cursorBlink = cursorBlink;

    if (this->cursorBlink)
    {
        this->lcd->blink();
    }
    else
    {
        this->lcd->noBlink();
    }
}

void CustomLCD::setCursorState(bool cursorState)
{
    this->cursorState = cursorState;

    if (this->cursorState)
    {
        this->lcd->cursor();
    }
    else
    {
        this->lcd->noCursor();
    }
}

void CustomLCD::setCursorPosition(unsigned int col, unsigned int row)
{
    this->lcd->setCursor(col, row);
}

void CustomLCD::setDisplayState(bool displayState)
{
    this->displayState = displayState;

    if (this->displayState)
    {
        this->lcd->display();
    }
    else
    {
        this->lcd->noDisplay();
    }
}

void CustomLCD::clearDisplay()
{
    this->lcd->clear();
}

void CustomLCD::goHomeDisplay()
{
    this->lcd->home();
}

void CustomLCD::setWriting(bool leftToRight)
{
    this->writeRight2Left = !leftToRight;

    if (this->writeRight2Left)
    {
        this->lcd->rightToLeft();
    }
    else
    {
        this->lcd->leftToRight();
    }
}

void CustomLCD::scrollDisplay(int scroll)
{
    if (scroll > 0)
    {
        for (int i = 0; i < scroll; i++)
        {
            this->lcd->scrollDisplayRight();
        }
    }
    
    if (scroll < 0)
    {
        for (scroll; scroll < 0; scroll++)
        {
            this->lcd->scrollDisplayRight();
        }
    }
}

void CustomLCD::writeCustomChar(unsigned short index)
{
    this->lcd->write(index);
}

void CustomLCD::setDefaultConfig()
{
    this->setAutoscroll(false);
    this->setCursorBlink(false);
    this->setCursorState(true);
    this->setDisplayState(true);
    this->setWriting(false);
}

void CustomLCD::print(const Printable &p)
{
    this->lcd->print(p);
}
void CustomLCD::print(const String &s)
{
    this->lcd->print(s);
}
void CustomLCD::print(const __FlashStringHelper* fsH)
{
    this->lcd->print(fsH);
}
void CustomLCD::print(const char s[])
{
    this->lcd->print(s);
}
void CustomLCD::print(const unsigned char s[])
{
    this->lcd->print((char)s);
}
void CustomLCD::print(const char c)
{
    this->lcd->print(c);
}
void CustomLCD::print(const unsigned char c)
{
    this->lcd->print(c);
}
void CustomLCD::print(const short n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const unsigned short n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const int n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const unsigned int n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const long n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const unsigned long n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const float n, int base)
{
    this->lcd->print(n, base);
}
void CustomLCD::print(const double n, int base)
{
    this->lcd->print(n, base);
}
