#ifndef __MAINSCREEN_H_
#define __MAINSCREEN_H_

#include <U8g2lib.h>
#include "MainScreenIcons.h"

// used fonts
// u8g2_font_7x14_mr
// u8g2_font_fur25_tf

class MainScreen
{
    public:
        MainScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display);
        void draw(byte minutes, byte seconds, float lipoVoltage, bool alarmIsRunning, byte setAlarmMinutes);

    private:
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display;

        const byte leftOffsetX = 5;
        const byte textOffsetX = 3;

        void drawTime(const char * t,  bool alarmIsRunning, const char * alarm);
        void drawLIPO(float lipoVoltage, const char * fullLIPOVoltageText);
};

#endif // __MAINSCREEN_H_