#include "cputemp.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <qmqtt>


CPUTemp::CPUTemp(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    // MQTT Configuration
    QHostInfo ip = QHostInfo::fromName(MQTT_SERVER);
    client = new QMQTT::Client(QHostAddress(ip.addresses().first()), MQTT_PORT);
    client->connectToHost();

    // Update values every 2 seconds
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowTemperature()));
    timer->start(2000);

}

void CPUTemp::ShowTemperature()
{
    QFile temp(TEMPFILE);
    if (temp.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString value = temp.readLine();
        temp.close();

        // format value e.g. 65.1 and show on LCD
        double t = value.toFloat() / 1000.0;
        value = value.setNum(t, 'f', 1);
        lcdNumber->display(value);

        // publish via mqtt
        QByteArray msg;
        msg.append(value);
        client->publish(QMQTT::Message(0, MQTT_TOPIC, msg));

    }
    else
        lcdNumber->display("EEEEEE");
}


void CPUTemp::on_actionInfo_triggered()
{
    QMessageBox::information(this, "CPUTemp", "Read Raspberry CPU Temperature and publish value on test.mosquitto.org under topic rpi-001-temp");
}
