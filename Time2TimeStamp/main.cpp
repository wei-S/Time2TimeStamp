#include "Time2TimeStamp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Time2TimeStamp w;
    w.show();
    return a.exec();
}
