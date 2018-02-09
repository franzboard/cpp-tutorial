// Up-/down counter with reset
// can be controlled from GUI as well as from GPIO pins.
#ifndef COUNTER_H
#define COUNTER_H

#include "ui_counter.h"
#include "gpio.h"

#define BUTTON1 22
#define BUTTON2 27
#define BUTTON3 17

class Counter : public QWidget, private Ui::Counter
{
    Q_OBJECT

public:
    explicit Counter(QWidget *parent = 0);
    ~Counter();

private:
    int m_counter;
    int m_edge;
    Gpio *m_up;
    Gpio *m_reset;
    Gpio *m_down;

private slots:
    void on_pushButtonDown_clicked();
    void on_pushButtonReset_clicked();
    void on_pushButtonUp_clicked();

signals:
    void button1Pressed();
    void button2Pressed();
    void button3Pressed();
};

#endif // COUNTER_H
