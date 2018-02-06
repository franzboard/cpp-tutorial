#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Widget::on_input_returnPressed()
{
    QString text = "Hallo " + input->text();
    output->setText(text);
}
