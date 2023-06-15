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

private:
    Ui::gameWindow *ui;
    void setupGridButtons();
    void placeShips_AI();
    void initializeAllButtons();
    void checkForWin();
    void freezeCells();
    void unfreezeCells();
};

#endif // GAMEWINDOW_H
