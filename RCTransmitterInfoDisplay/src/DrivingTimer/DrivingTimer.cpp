#include "DrivingTimer.h"

DrivingTimer::DrivingTimer(byte leverPin, word timeToWaitBeforePauseMeasuring, word leverNeutralValue, byte leverNeutralPositionDeadzone)
    : leverPin(leverPin), timeToWaitBeforePauseMeasuring(timeToWaitBeforePauseMeasuring), leverNeutralValue(leverNeutralValue), leverNeutralPositionDeadzone(leverNeutralPositionDeadzone)
{
    leverUpperDeadzone = leverNeutralValue + leverNeutralPositionDeadzone;
    leverLowerDeadzone = leverNeutralValue - leverNeutralPositionDeadzone;
}

int DrivingTimer::getLeverValue()
{
    return analogRead(leverPin);
}

void DrivingTimer::measureDrivingTime()
{
    if (carIsMoving) {
        if (startedDriving)
            totalDrivingTime += millis() - drivingStartTime;
        else
            startedDriving = true;

        drivingStartTime = millis();
    } else {
        startedDriving = false;
        drivingStartTime = 0;
    }
}

void DrivingTimer::controlCarMovement()
{
    word leverValue = getLeverValue();

    // lever was pressed
    if (!carIsMoving && ((leverUpperDeadzone < leverValue) || (leverLowerDeadzone > leverValue))) {
        carIsMoving = true;
    
    // car is moving but lever is in neutral
    } else if (carIsMoving && ((leverUpperDeadzone > leverValue) || (leverLowerDeadzone < leverValue))) {
        pauseTimer = millis();
    
    // car is not moving anymore
    } else if (carIsMoving && (pauseTimer != 0)) {
        if ((pauseTimer + timeToWaitBeforePauseMeasuring) < millis()) {
            carIsMoving = false;
            pauseTimer = 0;
        }
    }
}

void DrivingTimer::update()
{
    controlCarMovement();
    measureDrivingTime();    
}

unsigned long DrivingTimer::getRawTime()
{
    return totalDrivingTime;
}

byte DrivingTimer::getMinutes()
{
    return (byte) floor(totalDrivingTime / 60000.0);
}

byte DrivingTimer::getSeconds()
{
    return (byte) floor((totalDrivingTime - (getMinutes() * 60000)) / 1000.0);
}