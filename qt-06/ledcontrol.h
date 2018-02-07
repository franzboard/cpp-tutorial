#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include "ui_ledcontrol.h"

#define LED1 18
#define LED2 23
#define LED3 24
#define LED4 25

class LedControl : public QWidget, private Ui::LedControl
{
    Q_OBJECT

public:
    explicit LedControl(QWidget *parent = 0);
    ~LedControl();

private slots:
    void on_led_4_clicked();
    void on_led_3_clicked();
    void on_led_2_clicked();
    void on_led_1_clicked();
};

#endif // LEDCONTROL_H
