#include "gameLogic.h"
#include <cstdlib>
#include <ctime>
#include <QDebug> // For debugging purposes

void placeShips_AI(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH])
{
    // Possible placement moves to choose from
    int moves[] = {1, -1, 10, -10};
    // Count for AI ships placed
    int placed_ships = 0;
    // Algorithm for random ship placement
    while (placed_ships < SHIPS)
    {
        int randomDirection = arc4random_uniform(4);
        int randomIndex_1 = arc4random_uniform(CELLS);
        int randomIndex_2 = randomIndex_1+moves[randomDirection];
        int randomIndex_3 = randomIndex_2+moves[randomDirection];

        if ((randomIndex_3 < CELLS) &&
            (randomIndex_3 >= 0))
        {
            if ((randomDirection >= 2) ||
                (randomIndex_1/10 == randomIndex_3/10))
            {
                if (!gridCells[randomIndex_1]->property("ship").toBool() &&
                    !gridCells[randomIndex_2]->property("ship").toBool() &&
                    !gridCells[randomIndex_3]->property("ship").toBool())
                {
                    gridCells[randomIndex_1]->setProperty("ship", QVariant(true));
                    gridCells[randomIndex_2]->setProperty("ship", QVariant(true));
                    gridCells[randomIndex_3]->setProperty("ship", QVariant(true));
                    shipPositions[placed_ships][0] = randomIndex_1;
                    shipPositions[placed_ships][1] = randomIndex_2;
                    shipPositions[placed_ships][2] = randomIndex_3;
                    placed_ships++;
                }
            }
        }
    }
}

void aiGuess(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH],
             Ui::gameWindow* ui, int &lastHitIndex)
{
    bool guessPlaced = false;
    int randomMove;
    int chosenCellIndex;

    while (!guessPlaced)
    {
        if (lastHitIndex != -1 && !gridCells[lastHitIndex]->property("destroyed").toBool())
        {
            // Possible placement moves to choose from
            int allMoves[] = {1, -1, 10, -10};
            randomMove = arc4random_uniform(4);
            randomMove = allMoves[randomMove];
            QPushButton* nextCell;

            for (int i = 0; i < 4; i++) // When side-by-side hits that arent the same ship occur, one of the hits is forgotten
            {
                if (lastHitIndex+allMoves[i] < CELLS && lastHitIndex+allMoves[i] >= 0)
                {
                    nextCell = gridCells[lastHitIndex+allMoves[i]];

                    if (nextCell->property("clicked").toBool() &&
                        nextCell->property("ship").toBool() &&
                        !nextCell->property("destroyed").toBool() &&
                        (((i < 2) && (lastHitIndex/10 == (lastHitIndex+allMoves[i])/10)) ||
                         ((i >= 2) && (lastHitIndex/10 != (lastHitIndex+allMoves[i])/10))))
                    {
                        int validMoves[] = {(2)*allMoves[i], (-1)*allMoves[i]};
                        if (!gridCells[lastHitIndex+validMoves[0]]->property("clicked").toBool() ||
                            !gridCells[lastHitIndex+validMoves[1]]->property("clicked").toBool())
                        {
                            randomMove = arc4random_uniform(2);
                            randomMove = validMoves[randomMove];
                        }
                    }
                }
            }
            chosenCellIndex = lastHitIndex + randomMove;
        }
        else
        {
            chosenCellIndex = arc4random_uniform(CELLS);
        }
        if (chosenCellIndex < CELLS && chosenCellIndex >= 0 &&
            !gridCells[chosenCellIndex]->property("clicked").toBool())
        {
            gridCells[chosenCellIndex]->setProperty("clicked", QVariant(true));
            processGuess(
                gridCells,
                chosenCellIndex,
                shipPositions,
                ui,
                lastHitIndex
                );
            guessPlaced = true;
        }
    }
}

// Processing AI's guess
void processGuess(QPushButton* gridCells[], int guessedCellIndex,
            int shipPositions[][SHIP_LENGTH], Ui::gameWindow* ui, int &lastHitIndex)
{
    if (gridCells[guessedCellIndex]->property("ship").toBool())
    {
        lastHitIndex = guessedCellIndex;
        onHit(ui, gridCells[guessedCellIndex]);
        checkForWin(gridCells, shipPositions);
    }
    else
        onMiss(ui, gridCells[guessedCellIndex]);

    enableContinue(ui);
}

// Processing user's guess
void processGuess(QPushButton* gridCells[], QPushButton* guessedCell,
                  int shipPositions[][SHIP_LENGTH], Ui::gameWindow* ui)
{
    if (guessedCell->property("ship").toBool())
    {
        onHit(ui, guessedCell);
        checkForWin(gridCells, shipPositions);
    }
    else
        onMiss(ui, guessedCell);

    enableContinue(ui);
}

void showUserShips(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH])
{
    for (int i = 0; i < SHIPS; i++)
    {
        setCellBlue(gridCells[shipPositions[i][0]]);
        setCellBlue(gridCells[shipPositions[i][1]]);
        setCellBlue(gridCells[shipPositions[i][2]]);
    }
}

void freezeCells(QPushButton* gridCells[])
{
    for (int i = 0; i < CELLS; i++)
        gridCells[i]->setEnabled(false);
}

void unfreezeCells(QPushButton* gridCells[])
{
    for (int i = 0; i < CELLS; i++)
    {
        if (!gridCells[i]->property("clicked").toBool())
            gridCells[i]->setEnabled(true);
    }
}

bool checkForWin(QPushButton* gridCells[], int shipPositions[][SHIP_LENGTH])
{
    int shipsHit = 0;
    for (int i = 0; i < SHIPS; i++)
    {
        if (gridCells[shipPositions[i][0]]->property("clicked").toBool() &&
            gridCells[shipPositions[i][1]]->property("clicked").toBool() &&
            gridCells[shipPositions[i][2]]->property("clicked").toBool())
        {
            for (int j = 0; j < SHIP_LENGTH; j++)
            {
               setDestroyedView(gridCells[shipPositions[i][j]]);
               gridCells[shipPositions[i][j]]->setProperty("destroyed", QVariant(true));
            }
            shipsHit++;
        }
    }

    if (shipsHit == SHIPS)
        return true;
    else
        return false;
}

void onHit(Ui::gameWindow* ui, QPushButton* guessedCell)
{
    setCellGreen(guessedCell);
    int hits = ui->hits->value();
    setHitDisplay(ui, ++hits);
    int remaining = ui->remaining->value();
    setRemainingDisplay(ui, --remaining);
}

void onMiss(Ui::gameWindow* ui, QPushButton* guessedCell)
{
    setCellRed(guessedCell);
    int misses = ui->misses->value();
    setMissDisplay(ui, ++misses);
}

void enableContinue(Ui::gameWindow* ui)
{
    ui->continue_btn->setEnabled(true);
    highlightContinue(ui);
}
