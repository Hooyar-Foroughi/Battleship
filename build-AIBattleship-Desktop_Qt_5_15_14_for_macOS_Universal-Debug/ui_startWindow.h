/********************************************************************************
** Form generated from reading UI file 'startWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.14
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startWindow
{
public:
    QWidget *start_CentralWidget;
    QGridLayout *gridLayout_4;
    QPushButton *start_btn;

    void setupUi(QMainWindow *startWindow)
    {
        if (startWindow->objectName().isEmpty())
            startWindow->setObjectName(QString::fromUtf8("startWindow"));
        startWindow->resize(900, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startWindow->sizePolicy().hasHeightForWidth());
        startWindow->setSizePolicy(sizePolicy);
        startWindow->setMinimumSize(QSize(900, 680));
        startWindow->setMaximumSize(QSize(900, 680));
        startWindow->setBaseSize(QSize(0, 0));
        QFont font;
        font.setPointSize(13);
        startWindow->setFont(font);
        startWindow->setCursor(QCursor(Qt::ArrowCursor));
        startWindow->setStyleSheet(QString::fromUtf8(""));
        start_CentralWidget = new QWidget(startWindow);
        start_CentralWidget->setObjectName(QString::fromUtf8("start_CentralWidget"));
        start_CentralWidget->setMinimumSize(QSize(770, 560));
        start_CentralWidget->setMaximumSize(QSize(970, 760));
        start_CentralWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	background-color:grey;\n"
"}"));
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
        font1.setBold(true);
        start_btn->setFont(font1);
        start_btn->setStyleSheet(QString::fromUtf8("QPushButton { \n"
"	border: 5px solid black; \n"
"	color: black; \n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: rgba(255, 255, 0, 1); \n"
"}\n"
"\n"
"QPushButton:pressed { \n"
"	background-color: rgba(255, 255, 0, 0.3); \n"
"}"));

        gridLayout_4->addWidget(start_btn, 1, 0, 1, 1);

        startWindow->setCentralWidget(start_CentralWidget);

        retranslateUi(startWindow);

        QMetaObject::connectSlotsByName(startWindow);
    } // setupUi

    void retranslateUi(QMainWindow *startWindow)
    {
        startWindow->setWindowTitle(QCoreApplication::translate("startWindow", "Battleship", nullptr));
        start_btn->setText(QCoreApplication::translate("startWindow", "START GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startWindow: public Ui_startWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
