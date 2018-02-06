#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Widget::on_bit3_clicked()
{
    lcdNumber->display(calculate_decimal());
}

void Widget::on_bit2_clicked()
{
    lcdNumber->display(calculate_decimal());
}

void Widget::on_bit1_clicked()
{
    lcdNumber->display(calculate_decimal());
}

void Widget::on_bit0_clicked()
{
    lcdNumber->display(calculate_decimal());
}

int Widget::calculate_decimal()
{
    return bit0->isChecked() + bit1->isChecked() * 2 +
            bit2->isChecked() * 4 + bit3->isChecked() * 8;
}
