#include "startWindow.h"
#include <QApplication>
#define USER_WINDOW 0
#define AI_WINDOW 1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow startWindow;
    GameWindow userWindow(USER_WINDOW);
    GameWindow oppWindow(AI_WINDOW);

    userWindow.setOtherGameWindow(&oppWindow);
    oppWindow.setOtherGameWindow(&userWindow);

    QObject::connect(&startWindow, &StartWindow::on_start_btn_clicked, [&]() {
        userWindow.setGeometry(startWindow.geometry());
        startWindow.hide();
        userWindow.show();
    });

    startWindow.show();

    return a.exec();
}
