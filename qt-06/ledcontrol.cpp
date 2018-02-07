#include <wiringPi.h>
#include "ledcontrol.h"

LedControl::LedControl(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    wiringPiSetupGpio();
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
}
LedControl::~LedControl()
{
    digitalWrite(LED1, 0);
    digitalWrite(LED2, 0);
    digitalWrite(LED3, 0);
    digitalWrite(LED4, 0);
}

void LedControl::on_led_4_clicked()
{
    digitalWrite(LED4, led_4->isChecked());
}

void LedControl::on_led_3_clicked()
{
    digitalWrite(LED3, led_3->isChecked());
}

void LedControl::on_led_2_clicked()
{
    digitalWrite(LED2, led_2->isChecked());
}

void LedControl::on_led_1_clicked()
{
    digitalWrite(LED1, led_1->isChecked());
}


