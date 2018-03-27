#ifndef __BUZZER_H_
#define __BUZZER_H_

#include <Arduino.h>

class Buzzer 
{
    public:
        Buzzer(byte pin, word toneFreq, byte beepDuration, byte beepsCountInOneSeries, word beepDelay, word buzzerDelay, float votlageLimit);
        void init();
        void check(float lipoVoltage);

    private:
        byte pin;

        word toneFreq;
        byte beepDuration;

        byte beeps;
        byte beepsCounter = 0;

        unsigned long beepTimer = 0;
        unsigned long timer = 0;

        word beepDelay;
        word buzzerDelay;

        bool buzzerActivated = false;
        bool buzzerWaitingForSeries = false;

        float voltageLimit = 11.5f;

        void beep();
};

#endif // __BUZZER_H_