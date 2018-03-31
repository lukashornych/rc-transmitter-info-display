#include "DrivingTimer.h"

DrivingTimer::DrivingTimer(byte leverPin, word timeToWaitBeforePauseMeasuring, word leverNeutralValue, byte leverNeutralPositionDeadzone)
    : leverPin(leverPin), timeToWaitBeforePauseMeasuring(timeToWaitBeforePauseMeasuring), leverNeutralValue(leverNeutralValue), leverNeutralPositionDeadzone(leverNeutralPositionDeadzone)
{
    leverUpperDeadzone = leverNeutralValue + leverNeutralPositionDeadzone;
    leverLowerDeadzone = leverNeutralValue - leverNeutralPositionDeadzone;
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
    word leverValue = analogRead(leverPin);

    // lever is pressed
    if ((leverUpperDeadzone < leverValue) || (leverLowerDeadzone > leverValue)) {
        carIsMoving = true;
        pauseTimer = 0;

    // lever is in neutral
    } else if ((leverUpperDeadzone > leverValue) || (leverLowerDeadzone < leverValue)) {
        if (pauseTimer == 0) {
            pauseTimer = millis();
        } else {
            if ((pauseTimer + timeToWaitBeforePauseMeasuring) < millis()) {
                pauseTimer = 0;
                carIsMoving = false;
            }
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
    return (totalDrivingTime / 60000);
}

byte DrivingTimer::getSeconds()
{
    return (totalDrivingTime / 1000) % 60;
}

void DrivingTimer::resetTimer()
{
    totalDrivingTime = 0;
}




void DrivingTimer::setAlarm(byte minutes)
{
    alarmMinutes = minutes;
    alarmRunning = true;
}

byte DrivingTimer::getAlarmMinutes()
{
    return alarmMinutes;
}

bool DrivingTimer::alarmIsRinging()
{
    return (alarmIsRunning() && (totalDrivingTime >= (getAlarmMinutes() * 60000)));
}

void DrivingTimer::stopAlarm()
{
    alarmRunning = false;
    alarmMinutes = 0;
}

bool DrivingTimer::alarmIsRunning()
{
    return alarmRunning;
}