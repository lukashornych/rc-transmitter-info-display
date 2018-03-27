#include "LIPO.h"

LIPO::LIPO(byte lipoPin) : lipoPin(lipoPin)
{}

float LIPO::getLIPOVoltage()
{
    float value = (float) map(analogRead(lipoPin), 0, 1023, 0, 500) / 100.0f;
    value *= 3.00200020002f;

    return value;
}

float LIPO::getAproximateCellVoltage(float lipoVoltage)
{
    return (lipoVoltage / 3.0f);
}