#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include "../ds1820/ds1820.h"
#include <string>
#include <vector>

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void updateDisplay();

private:
    ds1820 *m_onewire;
    vector<string> m_sensors;

};

#endif // WIDGET_H
