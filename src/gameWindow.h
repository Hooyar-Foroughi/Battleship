#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#define USER_WINDOW 0
#define AI_WINDOW 1

#include <QWidget>
#include "gameLogic.h"
#include "gameView.h"

namespace Ui {
class gameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    // Game-board UI object
    Ui::gameWindow *ui;
    // Constructor
    explicit GameWindow(int windowType, QWidget *parent = nullptr);
    // Destructor
    ~GameWindow();
    // Method to set window to swtich to (opponent's window)
    void setOtherGameWindow(GameWindow* otherWindow);
    // User/AI game-board window identifier
    int windowID;
    // Grid positions of ships
    int shipPositions[SHIPS][SHIP_LENGTH];
    // Array for pointers to each grid cell
    QPushButton* gridCells[CELLS];

private slots:
    void onGridClick();
    void onContinueClick();

private:
    GameWindow *otherGameWindow;
    void setupButtons();
    void setupInfoBar();
    void initializeAllCells();
};

#endif // GAMEWINDOW_H
