#include "MenuScreen.h"

MenuScreen::MenuScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display, String* options, byte optionsCount)
    : DisplayScreen(display), options(options), optionsCount(optionsCount)
{}

MenuScreen::~MenuScreen()
{
    delete [] options;
}

byte MenuScreen::getSelectedOptionIndex()
{
    return selectedOptionIndex;
}

void MenuScreen::selectNextOption()
{
    selectedOptionIndex = (selectedOptionIndex < (optionsCount - 1)) ? selectedOptionIndex + 1 : 0;
}

void MenuScreen::resetSelectedOption()
{
    selectedOptionIndex = 0;
}



void MenuScreen::drawOption(byte optionIndex, byte line)
{
    char optionChars[20];
    options[optionIndex].toCharArray(optionChars, 20);
    
    if (optionIndex == getSelectedOptionIndex()) {
        display.drawBox(0, DISPLAY_LINE_HEIGHT * line, DISPLAY_WIDTH, DISPLAY_LINE_HEIGHT);

        display.setDrawColor(0); // set color for string            
    }
    
    display.drawStr(DISPLAY_LINE_TEXT_X_POS, (DISPLAY_LINE_HEIGHT * line) + DISPLAY_LINE_TEXT_Y_POS, optionChars);
    display.setDrawColor(1);
}

void MenuScreen::drawAllOptions()
{
    byte firstIndexToDisplay = ((selectedOptionIndex + 1) > MAX_OPTIONS_TO_DISPLAY) ? ((selectedOptionIndex + 1) - MAX_OPTIONS_TO_DISPLAY) : 0;

    for (byte i = firstIndexToDisplay; i < (firstIndexToDisplay + MAX_OPTIONS_TO_DISPLAY); i++) {
        drawOption(i, (i + 1) - firstIndexToDisplay);
    }
}



void MenuScreen::drawHeader()
{
    drawTitledHeader("Menu");

}

void MenuScreen::drawContent()
{
    drawAllOptions();
}