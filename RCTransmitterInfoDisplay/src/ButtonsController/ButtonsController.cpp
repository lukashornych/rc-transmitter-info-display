#include "ButtonsController.h"

ButtonsController::ButtonsController(byte enterButtonPin, byte selectButtonPin)
    : enterButtonPin(enterButtonPin), selectButtonPin(selectButtonPin)
{}

void ButtonsController::init()
{
    pinMode(enterButtonPin, INPUT);
    pinMode(selectButtonPin, INPUT);
}

bool ButtonsController::enterButtonPressed()
{
    if (digitalRead(enterButtonPin) && !enterButtonPrevState) {
        enterButtonPrevState = true;
        return true;
    } else {
        enterButtonPrevState = false;
        return false;
    }
}

bool ButtonsController::selectButtonPressed()
{
    if (digitalRead(selectButtonPin) && !selectButtonPrevState) {
        selectButtonPrevState = true;
        return true;
    } else {
        selectButtonPrevState = false;
        return false;
    }
}