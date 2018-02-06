#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"

class Widget : public QWidget, private Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void show_time();
private:
    QTime *time;
    QTimer *timer;
};

#endif // WIDGET_H
