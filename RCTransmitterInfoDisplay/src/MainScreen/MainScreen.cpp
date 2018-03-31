#include "MainScreen.h"

MainScreen::MainScreen(U8G2_SSD1306_128X64_NONAME_1_HW_I2C &display) : display(display)
{}

void MainScreen::draw(byte minutes, byte seconds, float lipoVoltage, bool alarmIsSet, byte setAlarmMinutes)
{
    // format values to texts
    char drivingTimeText[7];
    char drivingTimerAlarmText[7];
    char lipoVoltageText[7];

    char floatNum[5];

    sprintf(drivingTimeText, "%02d:%02d", minutes, seconds);
    sprintf(drivingTimerAlarmText, "%02d:00", setAlarmMinutes);
    
    dtostrf(lipoVoltage, 4, 2, floatNum);
    sprintf(lipoVoltageText, "%sV", floatNum);

    // display formatted texts
    display.firstPage();
    do {
        drawTime(drivingTimeText, alarmIsSet, drivingTimerAlarmText);
        drawLIPO(lipoVoltage, lipoVoltageText);
    } while (display.nextPage());
}

void MainScreen::drawTime(const char * t, bool alarmIsRunning, const char * alarm)
{
    display.drawXBM(0, 0, iconsWidth, iconsHeight, stopwatchIcon);

    display.setFont(u8g2_font_7x14_mr);
    display.drawStr(iconsWidth + textOffsetX, 13, t);

    if (alarmIsRunning) {
        display.drawXBM(64, 0, iconsWidth, iconsHeight, alarmIcon);
        display.drawStr(64 + iconsWidth + textOffsetX, 13, alarm);
    }
}

void MainScreen::drawLIPO(float lipoVoltage, const char * fullLIPOVoltageText)
{
    const byte width = 8;
    const byte maxHeight = 21;

    // calculate height of box in battery icon from percentage of battery
    byte lipoCapacityRectHeight = constrain(lipoVoltage - 10.8f, 0, 12.6f) / 1.8f * maxHeight;
    
    display.drawXBM(0, 16, lipoIconWidth, lipoIconHeight, lipoIcon);
    display.drawBox(4, 23 + (maxHeight - lipoCapacityRectHeight), width, lipoCapacityRectHeight);

    display.setFont(u8g2_font_fur25_tf);
    display.drawStr(iconsWidth + textOffsetX, 45, fullLIPOVoltageText);
}