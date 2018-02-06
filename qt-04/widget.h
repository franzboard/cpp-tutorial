#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    int calculate_decimal();
private slots:
    void on_bit3_clicked();
    void on_bit2_clicked();
    void on_bit1_clicked();
    void on_bit0_clicked();
};

#endif // WIDGET_H
