#include "widget.h"
#include <QTimer>
#include <vector>
#include <string>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    QTimer *timer = new QTimer;
    m_onewire = new ds1820;
    m_sensors = m_onewire->getIds();
    id1->setText(QString::fromStdString(m_sensors[0]));
    id2->setText(QString::fromStdString(m_sensors[1]));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateDisplay()));
    timer->start(1000);

}

Widget::~Widget()
{
}

void Widget::updateDisplay()
{
    float t1 = m_onewire->getTemp(m_sensors[0]);
    float t2 = m_onewire->getTemp(m_sensors[1]);
    temp1->display(QString::number(t1, 'f', 2));
    temp2->display(QString::number(t2, 'f', 2));
}
