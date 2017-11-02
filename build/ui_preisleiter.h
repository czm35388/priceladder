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
    QLabel *lb_Timer_2;
    QLabel *lb_Timer_3;
    QLabel *lb_Timer_4;
    QLabel *lb_Timer_5;

    void setupUi(QMainWindow *Preisleiter)
    {
        if (Preisleiter->objectName().isEmpty())
            Preisleiter->setObjectName(QStringLiteral("Preisleiter"));
        Preisleiter->resize(1280, 800);
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        Preisleiter->setFont(font);
        Preisleiter->setStyleSheet(QStringLiteral(""));
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
        font2.setPointSize(46);
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

        retranslateUi(Preisleiter);

        QMetaObject::connectSlotsByName(Preisleiter);
    } // setupUi

    void retranslateUi(QMainWindow *Preisleiter)
    {
        Preisleiter->setWindowTitle(QApplication::translate("Preisleiter", "Preisleiter", 0));
        pB_Start->setText(QApplication::translate("Preisleiter", "PushButton", 0));
        lb_Timer_1->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_Timer_2->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_Timer_3->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_Timer_4->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
        lb_Timer_5->setText(QApplication::translate("Preisleiter", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Preisleiter: public Ui_Preisleiter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREISLEITER_H
