#include <U8g2lib.h>
#include "src/MainScreen/MainScreen.h"
#include "src/LIPO/LIPO.h"
#include "src/Buzzer/Buzzer.h"
#include "src/DrivingTimer/DrivingTimer.h"

#define LIPO_PIN    A2
#define LEVER_PIN   A3
#define BUZZER_PIN  1

U8G2_SSD1306_128X64_NONAME_1_HW_I2C display(U8G2_R0, U8X8_PIN_NONE, 21, 20);

MainScreen mainScreen(display);
LIPO lipo(LIPO_PIN);
Buzzer buzzer(BUZZER_PIN, 2000, 100, 3, 200, 20000, 11.5f);
DrivingTimer drivingTimer(LEVER_PIN, 5000, 540, 50);

void setup()
{
    display.begin();

    buzzer.init();
}

void loop()
{
    drivingTimer.update();

    float lipoVoltage = lipo.getLIPOVoltage();
    float lipoCellVoltage = lipo.getAproximateCellVoltage(lipoVoltage);
    byte minutes = drivingTimer.getMinutes();
    byte seconds = drivingTimer.getSeconds();

    buzzer.check(lipoVoltage);

    mainScreen.draw(minutes, seconds, lipoVoltage, lipoCellVoltage);
}
