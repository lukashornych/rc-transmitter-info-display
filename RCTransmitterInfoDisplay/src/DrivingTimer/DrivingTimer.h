#ifndef __DRIVINGTIMER_H_
#define __DRIVINGTIMER_H_

#include <Arduino.h>

class DrivingTimer
{
    public:
        /**
         * @param leverPin Lever pin
         * @param leverPin timeToWaitBeforePauseMeasuring
         * @param leverNeutralValue Value of lever when it's in neutral position
         * @param leverNeutralPositionDeadzone Lever neutral position deadzones
         */
        DrivingTimer(byte leverPin, word timeToWaitBeforePauseMeasuring, word leverNeutralValue, byte leverNeutralPositionDeadzone);
        /**
         * Updates timers from current lever position
         */
        void update();
        void resetTimer();
        unsigned long getRawTime();
        byte getMinutes();
        byte getSeconds();

        void setAlarm(byte minutes);
        byte getAlarmMinutes();
        void stopAlarm();
        bool alarmIsRunning();
        bool alarmIsRinging();

    private:
        byte leverPin;

        unsigned long totalDrivingTime = 0;
        unsigned long drivingStartTime = 0; 
        bool startedDriving = false;

        // lever deadzones
        word leverNeutralValue;
        byte leverNeutralPositionDeadzone;
        word leverUpperDeadzone;
        word leverLowerDeadzone;

        // car movement control
        unsigned long pauseTimer = 0;
        word timeToWaitBeforePauseMeasuring;
        bool carIsMoving = false;

        // alarm
        bool alarmRunning = false;
        byte alarmMinutes = 0;


        /**
         * Check if lever is pressed or not to let know that car is moving
         */
        void controlCarMovement();
        /**
         * Measure driving time based on car movement
         */
        void measureDrivingTime();
};

#endif // __DRIVINGTIMER_H_