/********************************************************************************
** Form generated from reading UI file 'preisleiter.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREISLEITER_H
#define UI_PREISLEITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preisleiter
{
public:
    QAction *actionClose;
    QAction *actionTimers;
    QAction *actionBackground;
    QAction *actionStart_Countdown;
    QAction *actionStop_Countdown;
    QAction *actionAbort_Countdown;
    QAction *actionReset_Time;
    QWidget *centralWidget;
    QPushButton *pB_Start;
    QLabel *lb_Timer_1;
    QLabel *lb_Timer_2;
    QLabel *lb_Timer_3;
    QLabel *lb_Timer_4;
    QLabel *lb_Timer_5;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuSettings;

    void setupUi(QMainWindow *Preisleiter)
    {
        if (Preisleiter->objectName().isEmpty())
            Preisleiter->setObjectName(QStringLiteral("Preisleiter"));
        Preisleiter->setEnabled(true);
        Preisleiter->resize(1980, 1020);
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        Preisleiter->setFont(font);
        Preisleiter->setStyleSheet(QStringLiteral(""));
        actionClose = new QAction(Preisleiter);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionTimers = new QAction(Preisleiter);
        actionTimers->setObjectName(QStringLiteral("actionTimers"));
        actionBackground = new QAction(Preisleiter);
        actionBackground->setObjectName(QStringLiteral("actionBackground"));
        actionStart_Countdown = new QAction(Preisleiter);
        actionStart_Countdown->setObjectName(QStringLiteral("actionStart_Countdown"));
        actionStop_Countdown = new QAction(Preisleiter);
        actionStop_Countdown->setObjectName(QStringLiteral("actionStop_Countdown"));
        actionAbort_Countdown = new QAction(Preisleiter);
        actionAbort_Countdown->setObjectName(QStringLiteral("actionAbort_Countdown"));
        actionReset_Time = new QAction(Preisleiter);
        actionReset_Time->setObjectName(QStringLiteral("actionReset_Time"));
        centralWidget = new QWidget(Preisleiter);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pB_Start = new QPushButton(centralWidget);
        pB_Start->setObjectName(QStringLiteral("pB_Start"));
        pB_Start->setGeometry(QRect(260, 370, 113, 32));
        QFont font1;
        font1.setPointSize(10);
        pB_Start->setFont(font1);
        lb_Timer_1 = new QLabel(centralWidget);
        lb_Timer_1->setObjectName(QStringLiteral("lb_Timer_1"));
        lb_Timer_1->setGeometry(QRect(530, 65, 201, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial Narrow"));
        font2.setPointSize(60);
        font2.setBold(true);
        font2.setWeight(75);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferDefault);
        lb_Timer_1->setFont(font2);
        lb_Timer_1->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        lb_Timer_2 = new QLabel(centralWidget);
        lb_Timer_2->setObjectName(QStringLiteral("lb_Timer_2"));
        lb_Timer_2->setGeometry(QRect(540, 125, 191, 31));
        lb_Timer_2->setFont(font2);
        lb_Timer_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        lb_Timer_3 = new QLabel(centralWidget);
        lb_Timer_3->setObjectName(QStringLiteral("lb_Timer_3"));
        lb_Timer_3->setGeometry(QRect(540, 165, 191, 31));
        lb_Timer_3->setFont(font2);
        lb_Timer_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        lb_Timer_4 = new QLabel(centralWidget);
        lb_Timer_4->setObjectName(QStringLiteral("lb_Timer_4"));
        lb_Timer_4->setGeometry(QRect(550, 205, 181, 31));
        lb_Timer_4->setFont(font2);
        lb_Timer_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        lb_Timer_5 = new QLabel(centralWidget);
        lb_Timer_5->setObjectName(QStringLiteral("lb_Timer_5"));
        lb_Timer_5->setGeometry(QRect(560, 245, 171, 41));
        lb_Timer_5->setFont(font2);
        lb_Timer_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 0);"));
        Preisleiter->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Preisleiter);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1980, 22));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        Preisleiter->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuMenu->addAction(actionStart_Countdown);
        menuMenu->addAction(actionStop_Countdown);
        menuMenu->addAction(actionAbort_Countdown);
        menuMenu->addAction(actionReset_Time);
        menuMenu->addSeparator();
        menuMenu->addAction(actionClose);
        menuSettings->addAction(actionTimers);
        menuSettings->addAction(actionBackground);

        retranslateUi(Preisleiter);

        QMetaObject::connectSlotsByName(Preisleiter);
    } // setupUi

    void retranslateUi(QMainWindow *Preisleiter)
    {
        Preisleiter->setWindowTitle(QApplication::translate("Preisleiter", "Preisleiter", nullptr));
        actionClose->setText(QApplication::translate("Preisleiter", "Close Application", nullptr));
        actionTimers->setText(QApplication::translate("Preisleiter", "Set Timers", nullptr));
        actionBackground->setText(QApplication::translate("Preisleiter", "Set Background", nullptr));
#ifndef QT_NO_TOOLTIP
        actionBackground->setToolTip(QApplication::translate("Preisleiter", "Set Background", nullptr));
#endif // QT_NO_TOOLTIP
        actionStart_Countdown->setText(QApplication::translate("Preisleiter", "Start Time", nullptr));
        actionStop_Countdown->setText(QApplication::translate("Preisleiter", "Stop Time", nullptr));
#ifndef QT_NO_TOOLTIP
        actionStop_Countdown->setToolTip(QApplication::translate("Preisleiter", "Stop Time", nullptr));
#endif // QT_NO_TOOLTIP
        actionAbort_Countdown->setText(QApplication::translate("Preisleiter", "Abort Time", nullptr));
#ifndef QT_NO_TOOLTIP
        actionAbort_Countdown->setToolTip(QApplication::translate("Preisleiter", " Abort Time", nullptr));
#endif // QT_NO_TOOLTIP
        actionReset_Time->setText(QApplication::translate("Preisleiter", "Reset Time", nullptr));
        pB_Start->setText(QApplication::translate("Preisleiter", "PushButton", nullptr));
        lb_Timer_1->setText(QApplication::translate("Preisleiter", "TextLabel", nullptr));
        lb_Timer_2->setText(QApplication::translate("Preisleiter", "TextLabel", nullptr));
        lb_Timer_3->setText(QApplication::translate("Preisleiter", "TextLabel", nullptr));
        lb_Timer_4->setText(QApplication::translate("Preisleiter", "TextLabel", nullptr));
        lb_Timer_5->setText(QApplication::translate("Preisleiter", "TextLabel", nullptr));
        menuMenu->setTitle(QApplication::translate("Preisleiter", "Menu", nullptr));
        menuSettings->setTitle(QApplication::translate("Preisleiter", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Preisleiter: public Ui_Preisleiter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREISLEITER_H
