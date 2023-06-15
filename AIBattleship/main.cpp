#include "startWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    startWindow startwindow;
    startwindow.show();

    return a.exec();
}
