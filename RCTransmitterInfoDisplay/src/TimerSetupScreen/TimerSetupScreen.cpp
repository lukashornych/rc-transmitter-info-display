#include "TimerSetupScreen.h"

TimerSetupScreen::TimerSetupScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display)
    : DisplayScreen(display)
{}

byte TimerSetupScreen::getSelectedValue()
{
    return currentValue;
}

void TimerSetupScreen::selectNextValue()
{
    if (currentValue < maxValue)
        currentValue++;
}



void TimerSetupScreen::drawHeader()
{
    drawTitledHeader(headerTitle);
}

void TimerSetupScreen::drawContent()
{
    char valueChars[7];
    sprintf(valueChars, "%d", currentValue);

    char secondsText[4] = ":00";

    display.drawBox(35, DISPLAY_VALUE_Y_POS - 1, 27, DISPLAY_LINE_HEIGHT + 1);
    display.setDrawColor(0);
    display.drawStr(39, DISPLAY_VALUE_Y_POS + DISPLAY_LINE_TEXT_Y_POS, valueChars);
    display.setDrawColor(1);
    display.drawStr(64, DISPLAY_VALUE_Y_POS + DISPLAY_LINE_TEXT_Y_POS, secondsText);
}