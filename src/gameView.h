#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QPushButton>
#include "ui_gameWindow.h"

void highlightContinue(Ui::gameWindow* ui);
void setCellRed(QPushButton* cell);
void setCellGreen(QPushButton* cell);
void setCellBlue(QPushButton* cell);

#endif // GAMEVIEW_H
