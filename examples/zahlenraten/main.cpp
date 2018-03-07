#include "zahlenraten.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Zahlenraten w;
    w.show();

    return a.exec();
}
