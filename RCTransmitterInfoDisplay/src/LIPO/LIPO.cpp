#include "LIPO.h"

LIPO::LIPO(byte lipoPin) : lipoPin(lipoPin)
{}

float LIPO::getLIPOVoltage()
{
    return analogRead(lipoPin) / 205.0f;
}

bool LIPO::alarmIsRinging()
{
    return (getLIPOVoltage() < alarmTreshold);
}