#include "cputemp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CPUTemp w;
    w.show();

    return a.exec();
}
