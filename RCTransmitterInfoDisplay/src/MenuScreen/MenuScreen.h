#ifndef __MENUDISPLAYPAGE_H_
#define __MENUDISPLAYPAGE_H_

#include <Arduino.h>
#include <U8g2lib.h>
#include "../DisplayScreen/DisplayScreen.h"

class MenuScreen : public DisplayScreen
{
    public:
        /**
         * Creates menu page object on selected I2C pins
         * @param display U8G2_SSD1306_128X64_NONAME_1_HW_I2C display object
         * @param optionsCount Number of options
         */
        MenuScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display, String* options, byte optionsCount);
        ~MenuScreen();
        /**
         * Getter for index of selected option
         * @return Index of selected option
         */
        byte getSelectedOptionIndex();
        /**
         * Selects next option
         */
        void selectNextOption();
        void resetSelectedOption();

    protected:
        void drawHeader();
        void drawContent();

    private:
        const byte MAX_OPTIONS_TO_DISPLAY = 3;

        String* options;
        byte optionsCount;
        byte selectedOptionIndex = 0;

        /**
         * Draws one option to display
         * @param optionIndex Index of option to draw
         * @param line On which line the option have to be drawn
         */
        void drawOption(byte optionIndex, byte line);
        /**
         * Draws all options on display
         */
        void drawAllOptions();
};

#endif // __MENUDISPLAYPAGE_H_