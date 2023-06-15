#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "gameWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class startWindow; }
QT_END_NAMESPACE

class startWindow : public QMainWindow
{
    Q_OBJECT

public:
    startWindow(QWidget *parent = nullptr);
    ~startWindow();

private slots:
    void on_start_btn_clicked();

private:
    Ui::startWindow *ui;
};
#endif // STARTWINDOW_H
