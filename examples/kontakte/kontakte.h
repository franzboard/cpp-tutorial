#ifndef KONTAKTE_H
#define KONTAKTE_H

#include "ui_kontakte.h"

class Kontakte : public QWidget, private Ui::Kontakte
{
    Q_OBJECT

public:
    explicit Kontakte(QWidget *parent = 0);
private slots:
    void on_eingabe_returnPressed();
};

#endif // KONTAKTE_H
