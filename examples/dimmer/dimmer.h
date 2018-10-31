#ifndef DIMMER_H
#define DIMMER_H

#include "ui_dimmer.h"
#include <vector>

const std::vector<int> LEDS = {18, 23, 24, 25};

class Dimmer : public QWidget, private Ui::Dimmer
{
    Q_OBJECT

public:
    explicit Dimmer(QWidget *parent = 0);
    ~Dimmer();

private slots:
    void on_slider_valueChanged(int value);

private:
    void LedSet(int value);
};

#endif // DIMMER_H
