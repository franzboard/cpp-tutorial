// Control GPIO Pins via Qt widget

#include "ledcontrol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LedControl w;
    w.show();

    return a.exec();
}
