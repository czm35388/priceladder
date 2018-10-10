#include "preisleiter.h"
#include "ui_preisleiter.h"

Preisleiter::Preisleiter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preisleiter)
{
    ui->setupUi(this);
    ui->centralWidget->setWindowTitle("Preisleiter");

    //@todo set the path via the gui-settings "background"
    QPixmap bkgnd("/Users/michael/Documents/Programmierung/02_Git_Repos/priceladder/files/Factory_Preisleiter_Präsentation.jpg");
    bkgnd = bkgnd.scaled(iScreenwidth, iScreenheigth, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //@todo set the geometry dependend on the size of the Screen and fitted to the background
    //maybe its possible to set the geometry via "Drag and Drop" within the Application
    ui->pB_Start->setGeometry(iScreenwidth/2, 167, 100, 25);
    ui->pB_Start->setText("Start");

    ui->lb_Timer_1->setText(time_1.toString("hh:mm:ss"));
    ui->lb_Timer_1->setGeometry(945, 312, 300, 50);

    ui->lb_Timer_2->setText(time_2.toString("hh:mm:ss"));
    ui->lb_Timer_2->setGeometry(945, 465, 300, 50);

    ui->lb_Timer_3->setText(time_3.toString("hh:mm:ss"));
    ui->lb_Timer_3->setGeometry(945, 615, 300, 50);

    ui->lb_Timer_4->setText(time_4.toString("hh:mm:ss"));
    ui->lb_Timer_4->setGeometry(945, 770, 300, 50);

    ui->lb_Timer_5->setText(time_5.toString("hh:mm:ss"));
    ui->lb_Timer_5->setGeometry(945, 925, 300, 50);


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
    else if(bCountdown_4 == false)
    {
        Preisleiter::Countdown_4();
    }
    else if(bCountdown_5 == false)
    {
        Preisleiter::Countdown_5();
    }

    else
    {
        myTimer->stop();
    }

}

void Preisleiter::on_pB_Start_released()
{
    myTimer->start();
    ui->pB_Start->hide();
}

void Preisleiter::Countdown_1()
{
    iTimer_1 -= 1;
    QTime tCount_1 = time_1.addSecs(iTimer_1);
    ui->lb_Timer_1->setText(tCount_1.toString("hh:mm:ss"));

    if(!fünf.compare(tCount_1.toString("hh:mm:ss")))
    {
        ui->lb_Timer_1->setStyleSheet("color: red");
    }

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

    if(!fünf.compare(tCount_2.toString("hh:mm:ss")))
    {
        ui->lb_Timer_2->setStyleSheet("color: red");
    }

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

    if(!fünf.compare(tCount_3.toString("hh:mm:ss")))
    {
        ui->lb_Timer_3->setStyleSheet("color: red");
    }

    if(!null.compare(tCount_3.toString("hh:mm:ss")))
    {
        bCountdown_3 = true;
    }
}

void Preisleiter::Countdown_4()
{
    iTimer_4 -= 1;
    QTime tCount_4 = time_4.addSecs(iTimer_4);
    ui->lb_Timer_4->setText(tCount_4.toString("hh:mm:ss"));

    if(!fünf.compare(tCount_4.toString("hh:mm:ss")))
    {
        ui->lb_Timer_4->setStyleSheet("color: red");
    }

    if(!null.compare(tCount_4.toString("hh:mm:ss")))
    {
        bCountdown_4 = true;
        Preisleiter::Countdown_5();
    }
}

void Preisleiter::Countdown_5()
{
    iTimer_5 -= 1;
    QTime tCount_5 = time_5.addSecs(iTimer_5);
    ui->lb_Timer_5->setText(tCount_5.toString("hh:mm:ss"));

    if(!fünf.compare(tCount_5.toString("hh:mm:ss")))
    {
        ui->lb_Timer_5->setStyleSheet("color: red");
    }

    if(!null.compare(tCount_5.toString("hh:mm:ss")))
    {
        bCountdown_5 = true;
    }
}
