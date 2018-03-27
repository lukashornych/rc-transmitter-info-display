#ifndef __LIPO_H_
#define __LIPO_H_

#include <Arduino.h>



class LIPO
{
    public:
        LIPO(byte lipoPin);
        float getLIPOVoltage();
        float getAproximateCellVoltage(float lipoVoltage);

    private:
        byte lipoPin;
};

#endif // __LIPO_H_