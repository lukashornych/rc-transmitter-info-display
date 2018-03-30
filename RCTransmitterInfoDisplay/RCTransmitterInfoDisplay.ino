#include <U8g2lib.h>
#include "src/MainScreen/MainScreen.h"
#include "src/MenuScreen/MenuScreen.h"
#include "src/MenuOptions/MenuOptions.h"
#include "src/SetupScreen/SetupScreen.h"
#include "src/TimerSetupScreen/TimerSetupScreen.h"

#include "src/LIPO/LIPO.h"
#include "src/Buzzer/Buzzer.h"
#include "src/DrivingTimer/DrivingTimer.h"
#include "src/ButtonsController/ButtonsController.h"



// pins
#define LIPO_PIN            A2
#define LEVER_PIN           A3
#define BUZZER_PIN          2

#define ENTER_BUTTON_PIN    3
#define SELECT_BUTTON_PIN   4



// display
U8G2_SSD1306_128X64_NONAME_1_HW_I2C display(U8G2_R0, U8X8_PIN_NONE, 21, 20);

enum Pages {
    PAGE_MAIN,
    PAGE_MENU,
    PAGE_LIPO_ALARM,
    PAGE_TIMER_ALARM
};
byte currentPage = PAGE_MAIN;

MainScreen mainScreen(display);
MenuScreen menuScreen(display, menuOptions, menuOptionsCount);
SetupScreen lipoAlarmSetupScreen(display, "Set LIPO alarm", transLIPOVoltagesOptions, transLIPOVoltagesOptionsCount, 0, "V");
TimerSetupScreen timerSetupScreen(display);



LIPO lipo(LIPO_PIN);
DrivingTimer drivingTimer(LEVER_PIN, 5000, 540, 50);
ButtonsController buttonsController(ENTER_BUTTON_PIN, SELECT_BUTTON_PIN);

Buzzer lipoBuzzer(BUZZER_PIN, 7000, 100, 4, 100, 10000);
Buzzer drivingTimerAlarmBuzzer(BUZZER_PIN, 9000, 100, 2, 100, 1000);



void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);

    display.begin();
    buttonsController.init();
}

void loop()
{
    drivingTimer.update();

    float lipoVoltage = lipo.getLIPOVoltage();
    float lipoCellVoltage = lipo.getAproximateCellVoltage();
    byte minutes = drivingTimer.getMinutes();
    byte seconds = drivingTimer.getSeconds();

    // control buzzers
    lipoBuzzer.check(lipo.alarmIsRinging());
    drivingTimerAlarmBuzzer.check(drivingTimer.alarmIsRinging());

    // control buttons action
    if (buttonsController.enterButtonPressed()) {
        switch (currentPage) {
            case PAGE_MAIN: currentPage = PAGE_MENU; break;

            case PAGE_MENU: 
                switch (menuScreen.getSelectedOptionIndex()) {
                    case 0: currentPage = PAGE_LIPO_ALARM;  break;
                    case 1: 
                        drivingTimer.resetTimer();
                        currentPage = PAGE_MAIN;
                        break;
                    case 2: currentPage = PAGE_TIMER_ALARM; break;
                    case 3: 
                        drivingTimer.stopAlarm();
                        drivingTimerAlarmBuzzer.reset();
                        currentPage = PAGE_MAIN;
                        break;
                    case 4: currentPage = PAGE_MAIN; break;
                }
                menuScreen.resetSelectedOption();
                break;

            case PAGE_LIPO_ALARM:
                lipo.alarmTreshold = lipoAlarmSetupScreen.getSelectedValue();
                lipoBuzzer.reset();
                currentPage = PAGE_MAIN;
                break;

            case PAGE_TIMER_ALARM: 
                drivingTimer.setAlarm(timerSetupScreen.getSelectedValue());
                timerSetupScreen.resetValue();
                drivingTimerAlarmBuzzer.reset();
                currentPage = PAGE_MAIN;
                break;
        }
    } else if (buttonsController.selectButtonPressed()) {
        switch (currentPage) {
            case PAGE_MENU: menuScreen.selectNextOption(); break;
            case PAGE_LIPO_ALARM: lipoAlarmSetupScreen.selectNextValue(); break;
            case PAGE_TIMER_ALARM: timerSetupScreen.selectNextValue(); break;
        }
    }

    // draw page
    switch (currentPage) {
        case PAGE_MAIN: mainScreen.draw(minutes, seconds, lipoVoltage, lipoCellVoltage, drivingTimer.alarmIsRunning(), drivingTimer.getAlarmMinutes()); break;
        case PAGE_MENU: menuScreen.draw(); break;
        case PAGE_LIPO_ALARM: lipoAlarmSetupScreen.draw(); break;
        case PAGE_TIMER_ALARM: timerSetupScreen.draw(); break;
    }
}
