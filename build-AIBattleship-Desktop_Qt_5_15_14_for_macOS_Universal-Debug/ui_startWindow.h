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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startWindow
{
public:
    QWidget *start_CentralWidget;
    QGridLayout *gridLayout_4;
    QSpacerItem *bottom_spacer;
    QSpacerItem *middle_spacer;
    QWidget *title_widget;
    QGridLayout *gridLayout_6;
    QLabel *title;
    QWidget *start_btn_widget;
    QGridLayout *gridLayout_5;
    QPushButton *start_btn;
    QSpacerItem *top_spacer;

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
        font.setBold(false);
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
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        bottom_spacer = new QSpacerItem(20, 250, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(bottom_spacer, 8, 0, 1, 1);

        middle_spacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(middle_spacer, 4, 0, 1, 1);

        title_widget = new QWidget(start_CentralWidget);
        title_widget->setObjectName(QString::fromUtf8("title_widget"));
        gridLayout_6 = new QGridLayout(title_widget);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        title = new QLabel(title_widget);
        title->setObjectName(QString::fromUtf8("title"));
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setMaximumSize(QSize(1000, 1000));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Krungthep"));
        font1.setPointSize(80);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        title->setFont(font1);
        title->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color: black; \n"
"}"));
        title->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(title, 0, 0, 1, 1);


        gridLayout_4->addWidget(title_widget, 3, 0, 1, 1);

        start_btn_widget = new QWidget(start_CentralWidget);
        start_btn_widget->setObjectName(QString::fromUtf8("start_btn_widget"));
        gridLayout_5 = new QGridLayout(start_btn_widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        start_btn = new QPushButton(start_btn_widget);
        start_btn->setObjectName(QString::fromUtf8("start_btn"));
        sizePolicy.setHeightForWidth(start_btn->sizePolicy().hasHeightForWidth());
        start_btn->setSizePolicy(sizePolicy);
        start_btn->setMinimumSize(QSize(100, 50));
        start_btn->setMaximumSize(QSize(350, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Futura"));
        font2.setPointSize(18);
        font2.setBold(true);
        start_btn->setFont(font2);
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

        gridLayout_5->addWidget(start_btn, 0, 0, 1, 1);


        gridLayout_4->addWidget(start_btn_widget, 5, 0, 1, 1);

        top_spacer = new QSpacerItem(20, 170, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(top_spacer, 1, 0, 1, 1);

        startWindow->setCentralWidget(start_CentralWidget);

        retranslateUi(startWindow);

        QMetaObject::connectSlotsByName(startWindow);
    } // setupUi

    void retranslateUi(QMainWindow *startWindow)
    {
        startWindow->setWindowTitle(QCoreApplication::translate("startWindow", "Battleship", nullptr));
        title->setText(QCoreApplication::translate("startWindow", "Battleship", nullptr));
        start_btn->setText(QCoreApplication::translate("startWindow", "START GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startWindow: public Ui_startWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
