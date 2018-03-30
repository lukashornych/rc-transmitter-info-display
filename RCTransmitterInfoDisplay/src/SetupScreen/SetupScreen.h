#ifndef __SETUPDISPLAYPAGE_H_
#define __SETUPDISPLAYPAGE_H_

#include <Arduino.h>
#include <U8g2lib.h>
#include "../DisplayScreen/DisplayScreen.h"

class SetupScreen : public DisplayScreen
{
    public:
        /**
         * Creates setup display page object for actual value setup
         * @param display U8G2_SSD1306_128X64_NONAME_1_HW_I2C display
         * @param headerTitle Header title
         * @param values Array of available values to choose from
         * @param valuesCount Values count
         * @param selectedValueIndex Index of selected value
         * @param valuesUnit Values unit to display next to selected value
         */
        SetupScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display, String headerTitle, float * values, byte valuesCount, byte selectedValueIndex, String valuesUnit);
        // ~SetupScreen();
        /**
         * Gets selected value
         * @return Selected value from array of available values
         */
        float getSelectedValue();
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

        String headerTitle;
        float * valuesFloats;
        byte valuesCount;
        byte selectedValueIndex;
        String valuesUnit;
};

#endif // __SETUPDISPLAYPAGE_H_