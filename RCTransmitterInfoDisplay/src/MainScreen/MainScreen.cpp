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
    display.setFont(u8g2_font_fur25_tf);
    byte tWidth = display.getStrWidth(t);
    display.drawStr(64 - (tWidth / 2), 53, t);

    if (alarmIsRunning) {
        display.setFont(u8g2_font_7x14_mr);
        display.drawXBM(70, 0, iconsWidth, iconsHeight, alarmIcon);
        display.drawStr(70 + iconsWidth + textOffsetX, 13, alarm);
    }
}

void MainScreen::drawLIPO(float lipoVoltage, const char * fullLIPOVoltageText)
{
    const byte maxWidth = 9;
    const byte maxHeight = 4;

    // calculate height of box in battery icon from percentage of battery
    // 0.7f is difference between highest and lowest lipo cell value
    byte lipoCapacityRectWidth = constrain(lipoVoltage - 3.5f, 0, 4.2f) / 0.7f * (float) maxWidth;
    
    display.drawXBM(0, 0, iconsWidth, iconsHeight, lipoIcon);
    display.drawBox(3, 6, lipoCapacityRectWidth, maxHeight);

    display.setFont(u8g2_font_7x14_mr);
    display.drawStr(iconsWidth + textOffsetX, 13, fullLIPOVoltageText);
}