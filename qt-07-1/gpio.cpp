// Wrapper Class for wiringPi library
#include "gpio.h"


void Gpio::setup()  // to be called only once for all GPIOs, therefore static
{
    wiringPiSetupGpio(); // BCM numbering
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(BUTTON3, INPUT);
}

// Class CallbackAdapter
CallbackAdapter *CallbackAdapter::m_instance;

CallbackAdapter::CallbackAdapter()
{
}

CallbackAdapter *CallbackAdapter::instance()
{
    if (m_instance == 0) {
        m_instance = new CallbackAdapter();
    }
    return m_instance;
}

void CallbackAdapter::registerButton1Callback(int edgeType)
{
    wiringPiISR(BUTTON1, edgeType, CallbackAdapter::button1Callback);
}

void CallbackAdapter::button1Callback()
{
    emit m_instance->button1CallbackTriggered();
}

void CallbackAdapter::registerButton2Callback(int edgeType)
{
    wiringPiISR(BUTTON2, edgeType, CallbackAdapter::button2Callback);
}

void CallbackAdapter::button2Callback()
{
    emit m_instance->button2CallbackTriggered();
}

void CallbackAdapter::registerButton3Callback(int edgeType)
{
    wiringPiISR(BUTTON3, edgeType, CallbackAdapter::button3Callback);
}

void CallbackAdapter::button3Callback()
{
    emit m_instance->button3CallbackTriggered();
}
