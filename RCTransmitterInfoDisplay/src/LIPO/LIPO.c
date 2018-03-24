#include "LIPO.h"

float getLIPOVoltage(byte lipo)
{
    float value = (float) map(analogRead(lipo), 0, 1023, 0, 500) / 100.0f;
    value *= 3.00200020002f;

    return value;
}

float getAproximateCellVoltage(float lipoVoltage)
{
    return (lipoVoltage / 3.0f);
}