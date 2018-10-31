#include "dimmer.h"
#include <wiringPi.h>
#include <softPwm.h>

Dimmer::Dimmer(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    wiringPiSetupGpio();
    for (auto &led : LEDS)
        softPwmCreate(led, 0, 100);
}

Dimmer::~Dimmer()
{
    LedSet(0);
}

void Dimmer::on_slider_valueChanged(int value)
{
    display->display(value);
    LedSet(value);

}

void Dimmer::LedSet(int value)
{
    for (auto &led : LEDS)
        softPwmWrite(led, value);
}
