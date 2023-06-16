#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

namespace Ui {
class gameWindow;
}

class gameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow(QWidget *parent = nullptr);
    ~gameWindow();

private slots:
    void onGridClick();

    void on_continue_btn_clicked();

private:
    Ui::gameWindow *ui;
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
