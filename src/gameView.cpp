#include "gameView.h"

void highlightContinue(Ui::gameWindow* ui)
{
    ui->continue_btn->setStyleSheet(
        "QPushButton { color: black; background-color: rgba(0, 255, 0, 0.65); border: 1px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );
}

void unhighlightContinue(Ui::gameWindow* ui)
{
    ui->continue_btn->setStyleSheet(
        "color: black; "
        "background-color: grey; "
        "border: 1px solid black;"
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

void shipDestroyed(QPushButton* cell)
{
    cell->setText("💥");
}

void setHitDisplay(Ui::gameWindow* ui, int value)
{
    ui->hits->display(value);
}

void setMissDisplay(Ui::gameWindow* ui, int value)
{
    ui->misses->display(value);
}

void setRemainingDisplay(Ui::gameWindow* ui, int value)
{
    ui->remaining->display(value);
}

void setTurnLabel(Ui::gameWindow* ui, QString text)
{
    ui->turn_label->setText(text);
}
