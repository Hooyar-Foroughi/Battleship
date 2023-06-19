#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QPushButton>
#include "ui_gameWindow.h"

void highlightContinue(Ui::gameWindow* ui);
void unhighlightContinue(Ui::gameWindow* ui);
void setCellRed(QPushButton* cell);
void setCellGreen(QPushButton* cell);
void setCellBlue(QPushButton* cell);
void shipDestroyed(QPushButton* cell);
void setHitDisplay(Ui::gameWindow* ui, int value);
void setMissDisplay(Ui::gameWindow* ui, int value);
void setRemainingDisplay(Ui::gameWindow* ui, int value);
void setTurnLabel(Ui::gameWindow* ui, QString text);

#endif // GAMEVIEW_H
