#include "woerterbuch.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Woerterbuch w;
    w.show();

    return a.exec();
}
