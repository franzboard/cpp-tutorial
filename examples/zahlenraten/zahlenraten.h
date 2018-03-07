#ifndef ZAHLENRATEN_H
#define ZAHLENRATEN_H

#include "ui_zahlenraten.h"

class Zahlenraten : public QWidget, private Ui::Zahlenraten
{
    Q_OBJECT

public:
    explicit Zahlenraten(QWidget *parent = 0);

private slots:
    void on_zehner_currentIndexChanged(int index);
    void on_einer_currentIndexChanged(int index);

private:
    int value;
    void CheckValue();

};

#endif // ZAHLENRATEN_H
