#ifndef GPIO_H
#define GPIO_H
#include <wiringPi.h>
#include <QObject>

#define BUTTON1 22
#define BUTTON2 27
#define BUTTON3 17

class Gpio : public QObject
{
    Q_OBJECT
public:
    Gpio() {}
    static void setup();

};

class CallbackAdapter : public QObject
{
    Q_OBJECT
public:
    CallbackAdapter();
    static CallbackAdapter *instance();
    void registerButton1Callback(int edgeType);
    void registerButton2Callback(int edgeType);
    void registerButton3Callback(int edgeType);

signals:
    void button1CallbackTriggered();
    void button2CallbackTriggered();
    void button3CallbackTriggered();

private:
    static CallbackAdapter *m_instance;
    static void button1Callback();
    static void button2Callback();
    static void button3Callback();

};
#endif // GPIO_H
