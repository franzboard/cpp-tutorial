#include "dimmer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dimmer w;
    w.show();

    return a.exec();
}
