#include "src/MainScreen/MainScreen.h"
#include "src/LIPO/LIPO.h"
#include "src/Buzzer/Buzzer.h"
#include "src/DrivingTimer/DrivingTimer.h"

#define LIPO_PIN    A2
#define LEVER_PIN   A3
#define BUZZER_PIN  1

MainScreen mainScreen;
LIPO lipo(LIPO_PIN);
Buzzer buzzer(BUZZER_PIN, 2000, 100, 3, 200, 20000, 11.5f);
DrivingTimer drivingTimer(LEVER_PIN, 5000, 512, 50);

void setup()
{
    mainScreen.init();
    buzzer.init();
}

void loop()
{
    // float lipoVoltage = 11.5f;
    // float lipoCellVoltage = 3.61f;
    // byte minutes = 11;
    // byte seconds = 50;

    // char drivingTimeText[20];
    // char lipoVoltageText[7];
    // char lipoCellVoltageText[20];

    // char floatNum[5];

    // sprintf(drivingTimeText, "Time: %d:%d", minutes, seconds);
    
    // dtostrf(lipoVoltage, 4, 1, floatNum);
    // sprintf(lipoVoltageText, "%sV", floatNum);

    // dtostrf(lipoCellVoltage, 4, 2, floatNum);
    // sprintf(lipoCellVoltageText, "Per cell ~%sV", floatNum);

    // mainScreen.draw(drivingTimeText, lipoVoltageText, lipoCellVoltageText);

    drivingTimer.update();

    float lipoVoltage = lipo.getLIPOVoltage();
    float lipoCellVoltage = lipo.getAproximateCellVoltage(lipoVoltage);
    byte minutes = drivingTimer.getMinutes();
    byte seconds = drivingTimer.getSeconds();

    buzzer.check(lipoVoltage);

    char drivingTimeText[20];
    char lipoVoltageText[7];
    char lipoCellVoltageText[20];

    char floatNum[5];

    sprintf(drivingTimeText, "Time: %d:%d", minutes, seconds);
    
    dtostrf(lipoVoltage, 4, 1, floatNum);
    sprintf(lipoVoltageText, "%sV", floatNum);

    dtostrf(lipoCellVoltage, 4, 2, floatNum);
    sprintf(lipoCellVoltageText, "Per cell ~%sV", floatNum);

    mainScreen.draw(drivingTimeText, lipoVoltageText, lipoCellVoltageText);
}
