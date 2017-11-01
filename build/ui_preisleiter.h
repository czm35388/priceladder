/********************************************************************************
** Form generated from reading UI file 'preisleiter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREISLEITER_H
#define UI_PREISLEITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Preisleiter
{
public:
    QWidget *centralWidget;
    QPushButton *pB_Start;
    QLabel *lb_Timer_1;
    QLabel *lb_Timer_3;
    QLabel *lb_Timer_2;
    QLabel *lb_TimerInfo;

    void setupUi(QMainWindow *Preisleiter)
    {
        if (Preisleiter->objectName().isEmpty())
            Preisleiter->setObjectName(QStringLiteral("Preisleiter"));
        Preisleiter->resize(400, 300);
        centralWidget = new QWidget(Preisleiter);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pB_Start = new QPushButton(centralWidget);
        pB_Start->setObjectName(QStringLiteral("pB_Start"));
        pB_Start->setGeometry(QRect(120, 210, 113, 32));
        lb_Timer_1 = new QLabel(centralWidget);
        lb_Timer_1->setObjectName(QStringLiteral("lb_Timer_1"));
        lb_Timer_1->setGeometry(QRect(150, 90, 60, 16));
        lb_Timer_3 = new QLabel(centralWidget);
        lb_Timer_3->setObjectName(QStringLiteral("lb_Timer_3"));
        lb_Timer_3->setGeometry(QRect(150, 140, 60, 16));
        lb_Timer_2 = new QLabel(centralWidget);
        lb_Timer_2->setObjectName(QStringLiteral("lb_Timer_2"));
        lb_Timer_2->setGeometry(QRect(150, 50, 60, 16));
        lb_TimerInfo = new QLabel(centralWidget);
        lb_TimerInfo->setObjectName(QStringLiteral("lb_TimerInfo"));
        lb_TimerInfo->setGeometry(QRect(150, 180, 60, 16));
        Preisleiter->setCentralWidget(centralWidget);

        retranslateUi(Preisleiter);

        QMetaObject::connectSlotsByName(Preisleiter);
    } // setupUi

    void retranslateUi(QMainWindow *Preisleiter)
    {
        Preisleiter->setWindowTitle(QApplication::translate("Preisleiter", "Preisleiter", 0));
        pB_Start->setText(QApplication::translate("Preisleiter", "PushButton", 0));
        lb_Timer_1->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_Timer_3->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_Timer_2->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_TimerInfo->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Preisleiter: public Ui_Preisleiter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREISLEITER_H
