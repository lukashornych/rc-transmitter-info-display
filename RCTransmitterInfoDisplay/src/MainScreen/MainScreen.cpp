#include "MainScreen.h"

MainScreen::MainScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display) : display(display)
{}

void MainScreen::draw(const char * t, float lipoVoltage, const char * fullLIPOVoltageText, const char * cellVoltageText)
{
    display.firstPage();
    do {
        drawTime(t);
        drawLIPO(lipoVoltage, fullLIPOVoltageText, cellVoltageText);
    } while (display.nextPage());
}

void MainScreen::drawTime(const char * t)
{
    display.drawXBM(0, 0, iconsWidth, iconsHeight, stopwatchIcon);

    display.setFont(u8g2_font_7x14_mr);
    display.drawStr(iconsWidth + textOffsetX, 13, t);
}

void MainScreen::drawLIPO(float lipoVoltage, const char * fullLIPOVoltageText, const char * cellVoltageText)
{
    const byte width = 8;
    const byte maxHeight = 21;

    // calculate height of box in battery icon from percentage of battery
    byte lipoCapacityRectHeight = constrain(lipoVoltage - 10.8f, 0, 12.6f) / 1.8f * maxHeight;
    
    display.drawXBM(0, 16, lipoIconWidth, lipoIconHeight, lipoIcon);
    display.drawBox(4, 23 + (maxHeight - lipoCapacityRectHeight), width, lipoCapacityRectHeight);

    display.setFont(u8g2_font_fur25_tf);
    display.drawStr(iconsWidth + textOffsetX, 45, fullLIPOVoltageText);

    display.setFont(u8g2_font_7x14_mr);
    display.drawStr(1, 61, cellVoltageText);
}