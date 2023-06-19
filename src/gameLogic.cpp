#include "gameLogic.h"
#include <cstdlib>
#include <ctime>
#include <QDebug> // For debugging purposes

void placeShips_AI(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH])
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
                if (!allButtons[randomIndex_1]->property("ship").toBool() &&
                    !allButtons[randomIndex_2]->property("ship").toBool() &&
                    !allButtons[randomIndex_3]->property("ship").toBool())
                {
                    allButtons[randomIndex_1]->setProperty("ship", QVariant(true));
                    allButtons[randomIndex_2]->setProperty("ship", QVariant(true));
                    allButtons[randomIndex_3]->setProperty("ship", QVariant(true));
                    shipPositions[placed_ships][0] = randomIndex_1;
                    shipPositions[placed_ships][1] = randomIndex_2;
                    shipPositions[placed_ships][2] = randomIndex_3;
                    placed_ships++;
                }
            }
        }
    }
}

void aiGuess(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH],
             Ui::gameWindow* ui)
{
    bool guessPlaced = false;

    while (!guessPlaced)
    {
        int randomIndex = arc4random_uniform(CELLS);
        if (!allButtons[randomIndex]->property("clicked").toBool())
        {
            allButtons[randomIndex]->setProperty("clicked", QVariant(true));
            processGuess(allButtons, allButtons[randomIndex], shipPositions, ui);
            guessPlaced = true;
        }
    }
}

void processGuess(QPushButton* allButtons[], QPushButton* guessedButton,
                  int shipPositions[][SHIP_LENGTH],Ui::gameWindow* ui)
{
    if (guessedButton->property("ship").toBool())
    {
        onHit(ui, guessedButton);
        checkForWin(allButtons, shipPositions);
    }
    else
        onMiss(ui, guessedButton);
}

void showUserShips(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH])
{
    for (int i = 0; i < SHIPS; i++)
    {
        allButtons[shipPositions[i][0]]->setStyleSheet(
            "background-color: rgba(0, 0, 255, 0.45); "
            "border: 2px solid black;"
        );
        allButtons[shipPositions[i][1]]->setStyleSheet(
            "background-color: rgba(0, 0, 255, 0.45); "
            "border: 2px solid black;"
        );
        allButtons[shipPositions[i][2]]->setStyleSheet(
            "background-color: rgba(0, 0, 255, 0.45); "
            "border: 2px solid black;"
        );
    }
}

void freezeCells(QPushButton* allButtons[])
{
    for (int i = 0; i < CELLS; i++)
        allButtons[i]->setEnabled(false);
}

void unfreezeCells(QPushButton* allButtons[])
{
    for (int i = 0; i < CELLS; i++)
    {
        if (!allButtons[i]->property("clicked").toBool())
            allButtons[i]->setEnabled(true);
    }
}

bool checkForWin(QPushButton* allButtons[], int shipPositions[][SHIP_LENGTH])
{
    int shipsHit = 0;
    for (int i = 0; i < SHIPS; i++)
    {
        if (allButtons[shipPositions[i][0]]->property("clicked").toBool() &&
            allButtons[shipPositions[i][1]]->property("clicked").toBool() &&
            allButtons[shipPositions[i][2]]->property("clicked").toBool())
        {
            allButtons[shipPositions[i][0]]->setText("💥");
            allButtons[shipPositions[i][1]]->setText("💥");
            allButtons[shipPositions[i][2]]->setText("💥");
            shipsHit++;
        }
    }

    if (shipsHit == SHIPS)
        return true;
    else
        return false;
}

void onHit(Ui::gameWindow* ui, QPushButton* guessedButton)
{
    guessedButton->setStyleSheet(
        "QPushButton { background-color: rgba(0, 255, 0, 0.65); border: 2px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );

    int hits = ui->hits->value();
    ui->hits->display(++hits);
    int remaining = ui->remaining->value();
    ui->remaining->display(--remaining);
}

void onMiss(Ui::gameWindow* ui, QPushButton* guessedButton)
{
    guessedButton->setStyleSheet(
        "QPushButton { background-color: rgba(255, 0, 0, 0.65); border: 2px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );

    int misses = ui->misses->value();
    ui->misses->display(++misses);
}
