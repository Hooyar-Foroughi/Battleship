#include "startWindow.h"
#include "ui_startWindow.h"

startWindow::startWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startWindow)
{
    ui->setupUi(this);
}

startWindow::~startWindow()
{
    delete ui;
}


void startWindow::on_start_btn_clicked()
{
    this->hide();
    // Get the position and size of the current window
    QRect geometry = this->geometry();
    gameWindow *gamewindow = new gameWindow;
    gamewindow->setGeometry(geometry);
    gamewindow->show();

}

