#ifndef __MAINSCREEN_H_
#define __MAINSCREEN_H_

#include <U8g2lib.h>
#include "MainScreenIcons.h"

class MainScreen
{
    public:
        MainScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display);
        void draw(const char * t, float lipoVoltage, const char * fullLIPOVoltageText, const char * cellVoltageText);

    private:
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display;

        const byte leftOffsetX = 5;
        const byte textOffsetX = 3;

        void drawTime(const char * t);
        void drawLIPO(float lipoVoltage, const char * fullLIPOVoltageText, const char * cellsVoltagesText);
};

#endif // __MAINSCREEN_H_