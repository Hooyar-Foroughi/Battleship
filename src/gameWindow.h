#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#define USER_WINDOW 0
#define AI_WINDOW 1
#include <QWidget>

namespace Ui {
class gameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(int windowType, QWidget *parent = nullptr);
    void setOtherGameWindow(GameWindow* otherWindow);
    ~GameWindow();

private slots:
    void onGridClick();
    void on_continue_btn_clicked();

private:
    Ui::gameWindow *ui;
    GameWindow *otherGameWindow;
    void setupGridButtons();
    void placeShips_AI();
    void initializeAllButtons();
    bool checkForWin();
    void freezeCells();
    void unfreezeCells();
    void setupInfoBar();
    void onHit();
    void onMiss();
    void enableContinue();
};

#endif // GAMEWINDOW_H
