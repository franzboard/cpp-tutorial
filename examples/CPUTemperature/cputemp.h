#ifndef CPUTEMP_H
#define CPUTEMP_H

#include "ui_cputemp.h"
#include <qmqtt>

const QString MQTT_SERVER = "test.mosquitto.org";
const int MQTT_PORT = 1883;
const QString MQTT_TOPIC = "rpi-001-temp";
const QString TEMPFILE = "/sys/class/thermal/thermal_zone0/temp";

class CPUTemp : public QMainWindow, private Ui::CPUTemp
{
    Q_OBJECT

public:
    explicit CPUTemp(QWidget *parent = 0);
private slots:
    void ShowTemperature();
    void on_actionInfo_triggered();

private:
    QMQTT::Client *client;

};

#endif // CPUTEMP_H
