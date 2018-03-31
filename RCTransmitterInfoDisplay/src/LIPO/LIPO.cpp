#include "LIPO.h"

LIPO::LIPO(byte lipoPin) : lipoPin(lipoPin)
{}

float LIPO::getLIPOVoltage()
{
    return (float) map(analogRead(lipoPin), 0, 1023, 0, 500) / 100.0f;
}

bool LIPO::alarmIsRinging()
{
    return (getLIPOVoltage() < alarmTreshold);
}