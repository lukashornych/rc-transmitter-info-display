#ifndef __MENUOPTIONS_H_
#define __MENUOPTIONS_H_

// menu options
const byte menuOptionsCount = 5;
String menuOptions[menuOptionsCount] = {
    "Reset dri. timer",
    "Set timer alarm",
    "Stop timer alarm",
    "Set LIPO alarm",
    "Back"
};

// transmitter lipo voltages options
const byte transLIPOVoltagesOptionsCount = 5;
float transLIPOVoltagesOptions[transLIPOVoltagesOptionsCount] = {
    3.5f,
    3.6f,
    3.7f,
    3.8f,
    3.9f
};

#endif // __MENUOPTIONS_H_