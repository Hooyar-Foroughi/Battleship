#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QPushButton>
#include "ui_gameWindow.h"
#include "gameView.h"

// Number of total grid cells (i.e. 9x10)
#define CELLS 90
// Number of ships
#define SHIPS 4
// Number of cells for each ship
#define SHIP_LENGTH 3

void placeShips_AI(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH]);
void aiGuess(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH], Ui::gameWindow* ui);
void showUserShips(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH]);
void freezeCells(QPushButton* gridCells[]);
void unfreezeCells(QPushButton* gridCells[]);
void processGuess(QPushButton* gridCells[], QPushButton* guessedCell,
                int shipPositions[][SHIP_LENGTH],Ui::gameWindow* ui);
bool checkForWin(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH]);
void onHit(Ui::gameWindow* ui, QPushButton* guessedCell);
void onMiss(Ui::gameWindow* ui, QPushButton* guessedCell);
void enableContinue(Ui::gameWindow* ui);

#endif // GAMELOGIC_H
