#include "Buzzer.h"

Buzzer::Buzzer(byte pin, word toneFreq, byte beepDuration, byte beepsCountInOneSeries, word beepDelay, word buzzerDelay, float votlageLimit)
    : pin(pin), toneFreq(toneFreq), beepDuration(beepDuration), beeps(beeps), beepDelay(beepDelay), buzzerDelay(buzzerDelay), voltageLimit(voltageLimit)
{}

void Buzzer::init()
{
    pinMode(pin, OUTPUT);
}

void Buzzer::beep()
{
    tone(pin, toneFreq, beepDuration);
    beepsCounter++;
}

void Buzzer::check(float lipoVoltage)
{ 
    if (!buzzerActivated && (lipoVoltage < voltageLimit)) {
        buzzerActivated = true;

        beep();

        // activate one series of beeps
        beepTimer = millis();
    } else if (buzzerActivated) {
        if (!buzzerWaitingForSeries) {
            if ((beepTimer + beepDelay) < millis()) {
                if (beepsCounter < beeps) {
                    beep();

                    beepTimer = millis();
                } else if (beepsCounter == beeps) {
                    beepsCounter = false;

                    // start waiting for next beeps series
                    buzzerWaitingForSeries = true;
                    timer = millis();
                }
            }
        } else if (buzzerWaitingForSeries && ((timer + buzzerDelay) < millis())) {
                buzzerWaitingForSeries = false;
        }
    }
}