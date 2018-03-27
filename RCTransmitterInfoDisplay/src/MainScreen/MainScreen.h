#ifndef __MAINSCREEN_H_
#define __MAINSCREEN_H_

#include <ssd1306.h>
#include "MainScreenIcons.h"

class MainScreen
{
    public:
        void init();
        void draw(const char * t, const char * fullLIPOVoltage, const char * cellVoltage);

    private:
        const byte leftOffset = 5;
        const byte textOffset = 3;

        void drawTime(const char * t);
        void drawLIPO(const char * fullLIPOVoltage, const char * cellsVoltages);
};

#endif // __MAINSCREEN_H_