#ifndef __LIPO_H_
#define __LIPO_H_

#include <Arduino.h>

float getLIPOVoltage(byte lipo);
float getAproximateCellVoltage(float lipoVoltage);

#endif // __LIPO_H_