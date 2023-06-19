#include "gameView.h"

void highlightContinue(Ui::gameWindow* ui)
{
    ui->continue_btn->setStyleSheet(
        "QPushButton { color: black; background-color: rgba(0, 255, 0, 0.65); border: 1px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );
}

void setCellRed(QPushButton* cell)
{
    cell->setStyleSheet(
        "QPushButton { background-color: rgba(255, 0, 0, 0.65); border: 2px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );
}

void setCellGreen(QPushButton* cell)
{
    cell->setStyleSheet(
        "QPushButton { background-color: rgba(0, 255, 0, 0.65); border: 2px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );
}

void setCellBlue(QPushButton* cell)
{
    cell->setStyleSheet(
        "background-color: rgba(0, 0, 255, 0.45); "
        "border: 2px solid black;"
    );
}
