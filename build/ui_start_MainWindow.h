/********************************************************************************
** Form generated from reading UI file 'start_MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_MAINWINDOW_H
#define UI_START_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_start_MainWindow
{
public:
    QWidget *start_CentralWidget;
    QGridLayout *gridLayout_4;
    QPushButton *start_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *start_MainWindow)
    {
        if (start_MainWindow->objectName().isEmpty())
            start_MainWindow->setObjectName(QString::fromUtf8("start_MainWindow"));
        start_MainWindow->resize(770, 560);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start_MainWindow->sizePolicy().hasHeightForWidth());
        start_MainWindow->setSizePolicy(sizePolicy);
        start_MainWindow->setMinimumSize(QSize(770, 560));
        start_MainWindow->setMaximumSize(QSize(970, 760));
        start_MainWindow->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(13);
        start_MainWindow->setFont(font);
        start_MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        start_CentralWidget = new QWidget(start_MainWindow);
        start_CentralWidget->setObjectName(QString::fromUtf8("start_CentralWidget"));
        start_CentralWidget->setMinimumSize(QSize(770, 560));
        start_CentralWidget->setMaximumSize(QSize(970, 760));
        gridLayout_4 = new QGridLayout(start_CentralWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        start_btn = new QPushButton(start_CentralWidget);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(start_btn->sizePolicy().hasHeightForWidth());
        start_btn->setSizePolicy(sizePolicy1);
        start_btn->setMinimumSize(QSize(100, 30));
        start_btn->setMaximumSize(QSize(350, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Futura"));
        font1.setPointSize(18);
        start_btn->setFont(font1);

        gridLayout_4->addWidget(start_btn, 1, 0, 1, 1);

        start_MainWindow->setCentralWidget(start_CentralWidget);
        statusbar = new QStatusBar(start_MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        start_MainWindow->setStatusBar(statusbar);

        retranslateUi(start_MainWindow);

        QMetaObject::connectSlotsByName(start_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *start_MainWindow)
    {
        start_MainWindow->setWindowTitle(QCoreApplication::translate("start_MainWindow", "MainWindow", nullptr));
        start_btn->setText(QCoreApplication::translate("start_MainWindow", "START GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class start_MainWindow: public Ui_start_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_MAINWINDOW_H
