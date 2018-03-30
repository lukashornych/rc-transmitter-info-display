#ifndef __LIPO_H_
#define __LIPO_H_

#include <Arduino.h>



class LIPO
{
    public:
        float alarmTreshold = 11.0f;

        LIPO(byte lipoPin);
        float getLIPOVoltage();
        float getAproximateCellVoltage();

        void setAlarmTreshold();
        bool alarmIsRinging();

    private:
        byte lipoPin;
};

#endif // __LIPO_H_