#include "Buzzer.h"

Buzzer::Buzzer(byte pin, word toneFreq, byte beepDuration, byte beepsCountInOneSeries, word beepDelay, word buzzerDelay)
    : pin(pin), toneFreq(toneFreq), beepDuration(beepDuration), beeps(beepsCountInOneSeries), beepDelay(beepDelay), buzzerDelay(buzzerDelay)
{}

void Buzzer::beep()
{
    tone(pin, toneFreq, beepDuration);
    beepsCounter++;
}

void Buzzer::check(bool underTreshold)
{ 
    if (!buzzerActivated && underTreshold) {
        buzzerActivated = true;

        beep();

        // activate one series of beeps
        beepTimer = millis();
    } else if (buzzerActivated) {
        if (beepsCounter < beeps) {
            if ((beepTimer + beepDelay) < millis()) {
                beep();
                beepTimer = millis();

                // set timer if series of beeps ended
                if (beepsCounter == beeps)
                    timer = millis();
            }
        } else if (beepsCounter == beeps) {
            if ((timer + buzzerDelay) < millis()) {
                beepsCounter = 0;
                beepTimer = millis();
                timer = 0;
            }
        }
    }
}

void Buzzer::reset()
{
    buzzerActivated = false;
    buzzerWaitingForSeries = false;
    beepsCounter = 0;
    beepTimer = 0;
    timer = 0;
}