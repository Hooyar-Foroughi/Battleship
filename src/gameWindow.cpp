#include "gameWindow.h"
#include "ui_gameWindow.h"
#include <cstdlib>
#include <ctime>
#include <QDebug> // For debugging purposes

// Number of total grid cells (i.e. 9x10)
#define CELLS 90
// Number of ships
#define SHIPS 4
// Number of cells for each ship
#define SHIP_LENGTH 3
// Global array holding pointers to each grid cell
QPushButton* allButtons[CELLS];
// Grid positions of ships
int shipPositions[SHIPS][SHIP_LENGTH];

GameWindow::GameWindow(int windowType, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    if (windowType == USER_WINDOW)
    {
        initializeAllButtons();
        setupGridButtons();
        placeShips_AI();
        setupInfoBar();
    }

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setupInfoBar()
{
    ui->remaining->display(SHIPS*SHIP_LENGTH);
    ui->hits->display(0);
    ui->misses->display(0);
    ui->continue_btn->setEnabled(false);
}

void GameWindow::onHit()
{
    int hits = ui->hits->value();
    ui->hits->display(++hits);
    int remaining = ui->remaining->value();
    ui->remaining->display(--remaining);
}

void GameWindow::onMiss()
{
    int misses = ui->misses->value();
    ui->misses->display(++misses);
}

void GameWindow::enableContinue()
{
    ui->continue_btn->setEnabled(true);
    ui->continue_btn->setStyleSheet(
        "QPushButton { color: black; background-color: rgba(0, 255, 0, 0.65); border: 1px solid black; }"
        "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
        "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
    );
}

bool GameWindow::checkForWin()
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

void GameWindow::placeShips_AI()
{
    // Possible placement moves to choose from
    //int moves[] = {{1, -1}, {10, -10}};
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

void GameWindow::freezeCells()
{
    for (int i = 0; i < CELLS; i++)
        allButtons[i]->setEnabled(false);
}

void GameWindow::unfreezeCells()
{
    for (int i = 0; i < CELLS; i++)
    {
        if (!allButtons[i]->property("clicked").toBool())
            allButtons[i]->setEnabled(true);
    }
}

void GameWindow::onGridClick()
{
    freezeCells();
    // Get the button that triggered the event
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    //QString buttonName = clickedButton->objectName();
    //qDebug() << "Clicked button name: " << buttonName;
    clickedButton->setProperty("clicked", QVariant(true));
    clickedButton->setEnabled(false);

    if (clickedButton->property("ship").toBool())
    {
        clickedButton->setStyleSheet(
            "QPushButton { background-color: rgba(0, 255, 0, 0.65); border: 2px solid black; }"
            "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
            "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
        );
        checkForWin();
        onHit();
    }
    else
    {
        clickedButton->setStyleSheet(
            "QPushButton { background-color: rgba(255, 0, 0, 0.65); border: 2px solid black; }"
            "QPushButton:hover { background-color: rgba(255, 255, 0, 1); }"
            "QPushButton:pressed { background-color: rgba(255, 255, 0, 0.3); }"
        );
        onMiss();
    }

    enableContinue();
}

void GameWindow::setupGridButtons()
{
    // Connect all grid buttons to the onGridClick() slot
    for (int i = 0; i < CELLS; i++)
        connect(allButtons[i], &QPushButton::clicked, this, &GameWindow::onGridClick);
}

void GameWindow::initializeAllButtons()
{
    QPushButton* gridButtons[CELLS] = {
        ui->a1, ui->a2, ui->a3, ui->a4, ui->a5, ui->a6, ui->a7, ui->a8, ui->a9, ui->a10,
        ui->b1, ui->b2, ui->b3, ui->b4, ui->b5, ui->b6, ui->b7, ui->b8, ui->b9, ui->b10,
        ui->c1, ui->c2, ui->c3, ui->c4, ui->c5, ui->c6, ui->c7, ui->c8, ui->c9, ui->c10,
        ui->d1, ui->d2, ui->d3, ui->d4, ui->d5, ui->d6, ui->d7, ui->d8, ui->d9, ui->d10,
        ui->e1, ui->e2, ui->e3, ui->e4, ui->e5, ui->e6, ui->e7, ui->e8, ui->e9, ui->e10,
        ui->f1, ui->f2, ui->f3, ui->f4, ui->f5, ui->f6, ui->f7, ui->f8, ui->f9, ui->f10,
        ui->g1, ui->g2, ui->g3, ui->g4, ui->g5, ui->g6, ui->g7, ui->g8, ui->g9, ui->g10,
        ui->h1, ui->h2, ui->h3, ui->h4, ui->h5, ui->h6, ui->h7, ui->h8, ui->h9, ui->h10,
        ui->i1, ui->i2, ui->i3, ui->i4, ui->i5, ui->i6, ui->i7, ui->i8, ui->i9, ui->i10
    };

    // Copy the buttons/cells to the global array
    std::copy(std::begin(gridButtons), std::end(gridButtons), std::begin(allButtons));
}

void GameWindow::on_continue_btn_clicked()
{
    if (otherGameWindow)
    {
        otherGameWindow->setGeometry(this->geometry());
        this->hide();
        otherGameWindow->show();
    }
}

void GameWindow::setOtherGameWindow(GameWindow* otherWindow)
{
    otherGameWindow = otherWindow;
}

