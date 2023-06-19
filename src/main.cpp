#include "startWindow.h"
#include <QApplication>
#define USER_WINDOW 0
#define AI_WINDOW 1

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartWindow startWindow;
    GameWindow userWindow = GameWindow(USER_WINDOW);
    GameWindow aiWindow = GameWindow(AI_WINDOW);

    userWindow.setOtherGameWindow(&aiWindow);
    aiWindow.setOtherGameWindow(&userWindow);

    QObject::connect(&startWindow, &StartWindow::on_start_btn_clicked, &startWindow, [&]() {
        aiWindow.setGeometry(startWindow.geometry());
        startWindow.hide();
        aiWindow.show();
    });

    startWindow.show();

    return a.exec();
}
