#include "DisplayScreen.h"

DisplayScreen::DisplayScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display) : display(display)
{}

void DisplayScreen::drawTitledHeader(String title)
{
    char titleChars[20];
    title.toCharArray(titleChars, sizeof(titleChars));
    
    int titleWidth = display.getStrWidth(titleChars);

    display.drawBox(0, 0, DISPLAY_WIDTH, DISPLAY_LINE_HEIGHT);

    display.setDrawColor(0);
    display.drawStr(((DISPLAY_WIDTH / 2) - (titleWidth / 2)), DISPLAY_LINE_TEXT_Y_POS, titleChars);
    display.setDrawColor(1);
}

void DisplayScreen::draw()
{
    display.firstPage();
    do {
        display.setFont(u8g2_font_7x14_mr);
        drawHeader();
        drawContent();
    } while (display.nextPage());
}