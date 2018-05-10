#include "counter.h"
#include "gpio.h"

Counter::Counter(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    m_counter = 0;
    Gpio::setup(); // setup GPIO hardware

    CallbackAdapter *callbacks1 = CallbackAdapter::instance();
    connect(callbacks1, SIGNAL(button1CallbackTriggered()), this, SLOT(on_pushButtonDown_clicked()));
    callbacks1->registerButton1Callback(INT_EDGE_FALLING);

    CallbackAdapter *callbacks2 = CallbackAdapter::instance();
    connect(callbacks2, SIGNAL(button2CallbackTriggered()), this, SLOT(on_pushButtonReset_clicked()));
    callbacks2->registerButton2Callback(INT_EDGE_FALLING);

    CallbackAdapter *callbacks3 = CallbackAdapter::instance();
    connect(callbacks3, SIGNAL(button3CallbackTriggered()), this, SLOT(on_pushButtonUp_clicked()));
    callbacks3->registerButton3Callback(INT_EDGE_FALLING);
}

// Connect GUI pushbuttons to GUI display
void Counter::on_pushButtonDown_clicked()
{
    m_counter--;
    lcdNumber->display(m_counter);
}

void Counter::on_pushButtonReset_clicked()
{
    m_counter = 0;
    lcdNumber->display(m_counter);
}

void Counter::on_pushButtonUp_clicked()
{
    m_counter++;
    lcdNumber->display(m_counter);
}



