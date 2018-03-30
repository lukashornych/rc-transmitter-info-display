#ifndef __DISPLAYPAGE_H_
#define __DISPLAYPAGE_H_

#include <Arduino.h>
#include <U8g2lib.h>

class DisplayScreen
{
    public:
        /**
         * Creates display page object with display on selected I2C pins
         * @param display U8G2_SSD1306_128X64_NONAME_1_HW_I2C display object
         */
        DisplayScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display);
        /**
         * Draws page
         */
        void draw();

    protected:
        /**
         * Display positions constants
         */
        const byte DISPLAY_WIDTH            = 128;
        const byte DISPLAY_HEIGHT           = 64;
        const byte DISPLAY_LINE_HEIGHT      = 16;  
        const byte DISPLAY_LINE_TEXT_X_POS  = 3;
        const byte DISPLAY_LINE_TEXT_Y_POS  = 13;

        U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display;

        /**
         * Draws header with centered title
         * @param title Title
         */
        void drawTitledHeader(String title);

        /**
         * Draws header
         */
        virtual void drawHeader() = 0;
        /**
         * Draws everything what have to be drawed on the page but header
         */
        virtual void drawContent() = 0;
};

#endif // __DISPLAYPAGE_H_