#ifndef __LIPO_H_
#define __LIPO_H_

#include <Arduino.h>
#include <EEPROM.h>

class LIPO
{
    public:
        LIPO(byte lipoPin);
        void init();
        float getLIPOVoltage();

        void setAlarmTreshold(float treshold);
        float getAlarmTreshold();
        bool alarmIsRinging();

    private:
        byte lipoPin;
        float alarmTreshold = 3.5f;
};

#endif // __LIPO_H_