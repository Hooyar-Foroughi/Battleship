#include "startWindow.h"
#include "ui_startWindow.h"

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startWindow)
{
    ui->setupUi(this);
    connect(ui->start_btn, &QPushButton::clicked, this, &StartWindow::on_start_btn_clicked);
}

StartWindow::~StartWindow()
{
    delete ui;
}
/*
void StartWindow::on_start_btn_clicked()
{
    this->hide();
    // Get the position and size of the current window
    QRect geometry = this->geometry();
    userGameWindow = new GameWindow(USER_WINDOW);
    aiGameWindow = new GameWindow(AI_WINDOW);
    userGameWindow->setGeometry(geometry);
    aiGameWindow->setGeometry(geometry);
    userGameWindow->show();
}
*/
