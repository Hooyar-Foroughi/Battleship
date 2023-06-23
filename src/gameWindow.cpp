#include "gameWindow.h"
#include "ui_gameWindow.h"
#include <cstdlib>
#include <ctime>
#include <QDebug> // For debugging purposes

GameWindow::GameWindow(int windowType, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gameWindow)
{
    windowID = windowType;
    lastHitIndex = -1;
    ui->setupUi(this);
    initializeAllCells();
    setupButtons();
    setupInfoBar();
    placeShips_AI(gridCells, shipPositions);

    if (windowID == USER_WINDOW)
        showUserShips(gridCells, shipPositions);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::setupInfoBar()
{
    if (windowID == USER_WINDOW)
        setTurnLabel(ui, QString("Opponent's turn!"));
    else if (windowID == AI_WINDOW)
        setTurnLabel(ui, QString("Your turn!"));

    setRemainingDisplay(ui, SHIPS*SHIP_LENGTH);
    setHitDisplay(ui, 0);
    setMissDisplay(ui, 0);
    ui->continue_btn->setEnabled(false);
}

void GameWindow::setupButtons()
{
    // Connect all grid buttons to the onGridClick() slot
    for (int i = 0; i < CELLS; i++)
        connect(gridCells[i], &QPushButton::clicked, this, &GameWindow::onGridClick);
    // Disable clicking buttons on user's game-board (AI's turn)
    if (windowID == USER_WINDOW)
        freezeCells(gridCells);

    connect(ui->continue_btn, &QPushButton::clicked, this, &GameWindow::onContinueClick);
}

void GameWindow::initializeAllCells()
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
    std::copy(std::begin(gridButtons), std::end(gridButtons), std::begin(gridCells));
}

void GameWindow::onGridClick()
{
    freezeCells(gridCells);
    // Get the button that triggered the event
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());
    //QString buttonName = clickedButton->objectName();
    //qDebug() << "Clicked button name: " << buttonName;
    clickedButton->setProperty("clicked", QVariant(true));
    clickedButton->setEnabled(false);
    processGuess(gridCells, clickedButton, shipPositions, ui);
    enableContinue(ui);
}

void GameWindow::onContinueClick()
{
    if (otherGameWindow)
    {
        otherGameWindow->setGeometry(this->geometry());
        this->hide();
        otherGameWindow->show();
        unhighlightContinue(ui);

        if (windowID == AI_WINDOW)
        {
            aiGuess(
                otherGameWindow->gridCells,
                otherGameWindow->shipPositions,
                otherGameWindow->ui,
                otherGameWindow->lastHitIndex
            );
            unfreezeCells(gridCells);
        }
    }
}

void GameWindow::setOtherGameWindow(GameWindow* otherWindow)
{
    otherGameWindow = otherWindow;
}

