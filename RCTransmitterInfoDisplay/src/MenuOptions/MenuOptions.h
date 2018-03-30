#ifndef __MENUOPTIONS_H_
#define __MENUOPTIONS_H_

// menu options
const byte menuOptionsCount = 5;
String menuOptions[menuOptionsCount] = {
    "Set LIPO alarm",
    "Reset dri. timer",
    "Set timer alarm",
    "Stop timer alarm",
    "Back"
};

// transmitter lipo voltages options
const byte transLIPOVoltagesOptionsCount = 7;
float transLIPOVoltagesOptions[transLIPOVoltagesOptionsCount] = {
    10.9f,
    11.0f,
    11.1f,
    11.2f,
    11.3f,
    11.4f,
    11.5f
};

#endif // __MENUOPTIONS_H_