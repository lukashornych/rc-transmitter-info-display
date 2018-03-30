#ifndef __BUTTONSCONTROLLER_H_
#define __BUTTONSCONTROLLER_H_

#include <Arduino.h>

class ButtonsController
{
    public:
        ButtonsController(byte enterButtonPin, byte selectButtonPin);
        void init();
        bool enterButtonPressed();
        bool selectButtonPressed();

    private:
        byte enterButtonPin;
        byte selectButtonPin;

        bool enterButtonPrevState = false;
        bool selectButtonPrevState = false;
};

#endif // __BUTTONSCONTROLLER_H_