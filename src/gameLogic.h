#ifndef GAMELOGIC_H
#define GAMELOGIC_H
#include "ui_gameWindow.h"
#include <QPushButton>

// Number of total grid cells (i.e. 9x10)
#define CELLS 90
// Number of ships
#define SHIPS 4
// Number of cells for each ship
#define SHIP_LENGTH 3

void placeShips_AI(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH]);
void aiGuess(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH], Ui::gameWindow* ui);
void showUserShips(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH]);
void freezeCells(QPushButton* allButtons[]);
void unfreezeCells(QPushButton* allButtons[]);
void processGuess(QPushButton* allButtons[], QPushButton* guessedButton,
                int shipPositions[][SHIP_LENGTH],Ui::gameWindow* ui);
bool checkForWin(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH]);
void onHit(Ui::gameWindow* ui, QPushButton* guessedButton);
void onMiss(Ui::gameWindow* ui, QPushButton* guessedButton);

#endif // GAMELOGIC_H
