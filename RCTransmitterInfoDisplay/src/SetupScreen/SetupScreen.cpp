#include "SetupScreen.h"

SetupScreen::SetupScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display, String headerTitle, float * values, byte valuesCount, byte selectedValueIndex, String valuesUnit)
    : DisplayScreen(display), headerTitle(headerTitle), valuesFloats(values), valuesCount(valuesCount), selectedValueIndex(selectedValueIndex), valuesUnit(valuesUnit)
{}

float SetupScreen::getSelectedValue()
{
    return valuesFloats[selectedValueIndex];
}

void SetupScreen::selectNextValue()
{
    selectedValueIndex = (selectedValueIndex < (valuesCount - 1)) ? selectedValueIndex + 1 : 0;
}



void SetupScreen::drawHeader()
{
    drawTitledHeader(headerTitle);
}

void SetupScreen::drawContent()
{
    char valueChars[10];
    String value = String(valuesFloats[selectedValueIndex]);
    value.toCharArray(valueChars, 10);
    
    char valuesUnitChars[10];
    valuesUnit.toCharArray(valuesUnitChars, 10);

    display.drawBox(DISPLAY_VALUE_X_PADDING - 1, DISPLAY_VALUE_Y_POS - 1, DISPLAY_VALUE_WIDTH + 1, DISPLAY_LINE_HEIGHT + 1);
    display.setDrawColor(0);
    display.drawStr(DISPLAY_VALUE_X_PADDING + DISPLAY_LINE_TEXT_X_POS, DISPLAY_VALUE_Y_POS + DISPLAY_LINE_TEXT_Y_POS, valueChars);
    display.setDrawColor(1);
    display.drawStr(DISPLAY_VALUE_X_PADDING + DISPLAY_VALUE_WIDTH + DISPLAY_VALUE_UNIT_X_PADDING, DISPLAY_VALUE_Y_POS + DISPLAY_LINE_TEXT_Y_POS, valuesUnitChars);
}