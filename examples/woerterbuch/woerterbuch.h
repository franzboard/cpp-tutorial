#ifndef WOERTERBUCH_H
#define WOERTERBUCH_H

#include "ui_woerterbuch.h"

struct wb[] {
    QString de;
    QString en;
}
class Woerterbuch : public QWidget, private Ui::Woerterbuch
{
    Q_OBJECT

public:
    explicit Woerterbuch(QWidget *parent = 0);
private slots:
    void on_input_returnPressed();
};

#endif // WOERTERBUCH_H
