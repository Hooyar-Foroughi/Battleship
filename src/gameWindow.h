#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#define USER_WINDOW 0
#define AI_WINDOW 1
#include <QWidget>
#include "gameLogic.h"

namespace Ui {
class gameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    Ui::gameWindow *ui;
    // Constructor
    explicit GameWindow(int windowType, QWidget *parent = nullptr);
    // Destructor
    ~GameWindow();
    // Method to set window to swtich to (opponent's window)
    void setOtherGameWindow(GameWindow* otherWindow);
    // User/AI game-board window identifier
    int playerWindow;
    // Grid positions of ships
    int shipPositions[SHIPS][SHIP_LENGTH];
    // Array for holding pointers to each grid cell
    QPushButton* allButtons[CELLS];

private slots:
    void onGridClick();
    void on_continue_btn_clicked();

private:
    GameWindow *otherGameWindow;
    void setupGridButtons();
    void setupInfoBar();
    void initializeAllButtons();
    void enableContinue();
};

#endif // GAMEWINDOW_H
