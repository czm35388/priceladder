#include "preisleiter.h"
#include "ui_preisleiter.h"

Preisleiter::Preisleiter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preisleiter)
{
    ui->setupUi(this);

    ui->pB_Start->setGeometry(150, 150, 100, 25);
    ui->pB_Start->setText("Start");

    ui->lb_TimerInfo->setText("Timer schläft!");
    ui->lb_TimerInfo->setGeometry(150, 25, 250, 15);

    ui->lb_Timer_1->setGeometry(175, 50, 250, 15);
    ui->lb_Timer_2->setGeometry(175, 75, 250, 15);
    ui->lb_Timer_3->setGeometry(175, 100, 250, 15);

    ui->lb_Timer_1->setText(time_1.toString("hh:mm:ss"));
    ui->lb_Timer_2->setText(time_2.toString("hh:mm:ss"));
    ui->lb_Timer_3->setText(time_3.toString("hh:mm:ss"));

    myTimer->setInterval(1000);


    connect(myTimer, SIGNAL(timeout()), this, SLOT(myTimer_TimeOut()));
}

Preisleiter::~Preisleiter()
{
    delete ui;
}

void Preisleiter::myTimer_TimeOut()
{

    if(bCountdown_1 == false)
    {
        Preisleiter::Countdown_1();
    }
    else if(bCountdown_2 == false)
    {
        Preisleiter::Countdown_2();
    }
    else if(bCountdown_3 == false)
    {
        Preisleiter::Countdown_3();
    }

    else
    {
        myTimer->stop();
        ui->lb_TimerInfo->setText("Timer beendet!");
    }

}

void Preisleiter::on_pB_Start_released()
{
    myTimer->start();
    ui->pB_Start->hide();
    ui->lb_TimerInfo->setText("Timer gestartet!");
}

void Preisleiter::Countdown_1()
{
    iTimer_1 -= 1;
    QTime tCount_1 = time_1.addSecs(iTimer_1);
    ui->lb_Timer_1->setText(tCount_1.toString("hh:mm:ss"));

    if(!null.compare(tCount_1.toString("hh:mm:ss")))
    {
        bCountdown_1 = true;
        Preisleiter::Countdown_2();
    }
}

void Preisleiter::Countdown_2()
{
    iTimer_2 -= 1;
    QTime tCount_2 = time_2.addSecs(iTimer_2);
    ui->lb_Timer_2->setText(tCount_2.toString("hh:mm:ss"));

    if(!null.compare(tCount_2.toString("hh:mm:ss")))
    {
        bCountdown_2 = true;
        Preisleiter::Countdown_3();
    }
}

void Preisleiter::Countdown_3()
{
    iTimer_3 -= 1;
    QTime tCount_3 = time_3.addSecs(iTimer_3);
    ui->lb_Timer_3->setText(tCount_3.toString("hh:mm:ss"));

    if(!null.compare(tCount_3.toString("hh:mm:ss")))
    {
        bCountdown_3 = true;
    }
}
