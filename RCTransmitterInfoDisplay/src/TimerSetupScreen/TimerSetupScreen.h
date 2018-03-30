#ifndef __TIMERSETUPDISPLAYPAGE_H_
#define __TIMERSETUPDISPLAYPAGE_H_

#include <Arduino.h>
#include <U8g2lib.h>
#include "../DisplayScreen/DisplayScreen.h"

class TimerSetupScreen : public DisplayScreen
{
    public:
        /**
         * @param display U8G2_SSD1306_128X64_NONAME_1_HW_I2C display
         */
        TimerSetupScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display);
        /**
         * Gets selected value
         * @return Selected value from array of available values
         */
        byte getSelectedValue();
        /**
         * Selects next value in array of available values
         */
        void selectNextValue();

    protected:
        void drawHeader();
        void drawContent();

    private:
        const byte DISPLAY_VALUE_Y_POS = DISPLAY_LINE_HEIGHT * 2;
        const byte DISPLAY_VALUE_X_PADDING = 16;
        const byte DISPLAY_VALUE_WIDTH = 65;
        const byte DISPLAY_VALUE_UNIT_X_PADDING = 5;

        String headerTitle = "Set timer alarm";
        byte currentValue = 0;
        byte maxValue = 255;
};

#endif // __TIMERSETUPDISPLAYPAGE_H_