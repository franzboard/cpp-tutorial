#include "widget.h"
#include <QTime>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    time = new QTime();
    lcdNumber->display("00:00:00:000");
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(show_time()));
}

void Widget::on_startButton_clicked()
{
    startButton->setEnabled(0);
    stopButton->setEnabled(1);
    lcdNumber->display("00:00:00:000");
    time->restart();
    timer->start(100); // Update time display every 100 ms
}

void Widget::on_stopButton_clicked()
{
    startButton->setEnabled(1);
    stopButton->setEnabled(0);
    timer->stop();
}

void Widget::show_time()
{
    QTime t(0, 0, 0, 0);
    lcdNumber->display(t.addMSecs(time->elapsed()).toString("hh:mm:ss:zzz"));
}
