#include "LIPO.h"

LIPO::LIPO(byte lipoPin) : lipoPin(lipoPin)
{}

void LIPO::init()
{
    char readBytes[3];
    for (byte addr = 0; addr < 3; addr++) {
        readBytes[addr] = EEPROM.read(addr);
    }

    float readValue = atof(readBytes);
    if (readValue > 0.0f)
        alarmTreshold = readValue;
}

float LIPO::getLIPOVoltage()
{
    return analogRead(lipoPin) / 205.0f;
}

void LIPO::setAlarmTreshold(float treshold)
{
    alarmTreshold = treshold;

    String tresholdBytes = String(treshold, 1);
    for (byte i = 0; i < 3; i++) {
        EEPROM.write(i, tresholdBytes[i]);
    }
}

float LIPO::getAlarmTreshold()
{
    return alarmTreshold;
}

bool LIPO::alarmIsRinging()
{
    return (getLIPOVoltage() < getAlarmTreshold());
}