#include "CustomLcdDisplay.hpp"

CustomLCD::~CustomLCD()
{
    delete this->lcd;
    this->lcd = nullptr;
}

CustomLCD::CustomLCD(uint8_t cols, uint8_t rows)
{
    const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
    const int backlight = 10;

    this->lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    lcd->begin(cols, rows);

    this->backlight = backlight;
    this->cols = cols;
    this->rows = rows;

    pinMode(this->backlight, OUTPUT);
}

CustomLCD::CustomLCD(uint8_t cols, uint8_t rows, uint8_t backlight, uint8_t rs, uint8_t en, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
    this->lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    this->lcd->begin(cols, rows);

    this->backlight = backlight;
    this->cols = cols;
    this->rows = rows;

    pinMode(this->backlight, OUTPUT);
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
        digitalWrite(this->backlight, false);
    }
    else
    {
        digitalWrite(this->backlight, true);
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