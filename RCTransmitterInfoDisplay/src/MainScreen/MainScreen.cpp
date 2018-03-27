#include "MainScreen.h"

// MainScreen::MainScreen(SSD1306Device &display) : display(display)
// {}

void MainScreen::init()
{
    ssd1306_128x64_i2c_init();
    ssd1306_fillScreen(0);
    ssd1306_setFixedFont(ssd1306xled_font5x7);
}

void MainScreen::draw(const char * t, const char * fullLIPOVoltage, const char * cellVoltage)
{
    drawTime(t);
    drawLIPO(fullLIPOVoltage, cellVoltage);
}

void MainScreen::drawTime(const char * t)
{
    // ssd1306_drawBitmap(leftOffset, 1, iconsWidth, iconsHeight, stopwatchIcon);
    // ssd1306_printFixed(leftOffset + iconsWidth + textOffset, 8, t, STYLE_NORMAL);
    
    ssd1306_printFixedN(0, 0, t, STYLE_NORMAL, 1);

}

void MainScreen::drawLIPO(const char * fullLIPOVoltage, const char * cellVoltage)
{
    // ssd1306_drawBitmap(leftOffset, 3, iconsWidth, iconsHeight, lipoIcon);
    // ssd1306_printFixed(leftOffset + iconsWidth + textOffset, 24, fullLIPOVoltage, STYLE_NORMAL);

    ssd1306_printFixedN(0, 16, fullLIPOVoltage, STYLE_NORMAL, 2);

    ssd1306_printFixed(0, 48, cellVoltage, STYLE_NORMAL);
    // ssd1306_printFixed(42, 24, cellVoltage, STYLE_NORMAL);
    // ssd1306_printFixed(84, 24, cellVoltage, STYLE_NORMAL);
}