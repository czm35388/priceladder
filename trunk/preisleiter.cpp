#include "preisleiter.h"
#include "ui_preisleiter.h"


// CTOR
Preisleiter::Preisleiter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Preisleiter)
{
    ui->setupUi(this);
    ui->centralWidget->setWindowTitle("Preisleiter");

    //@todo set the path via the gui-settings "background"
    QPixmap bkgnd("c:\\Users\\mc\\work\\05_Git\\Preisleiter\\Factory_Preisleiter_Präsentation.jpg");
    bkgnd = bkgnd.scaled(iScreenwidth, iScreenheigth, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

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

// DTOR
Preisleiter::~Preisleiter()
{
    delete ui;
}


// makro for refreshing the shown time
#define Timerrunner(oTimer)\
    iTimer_##oTimer -= 1;\
    QTime tCount_##oTimer = time_##oTimer.addSecs(iTimer_##oTimer);\
    ui->lb_Timer_##oTimer->setText(tCount_##oTimer.toString("hh:mm:ss"));\
    if(!fünf.compare(tCount_##oTimer.toString("hh:mm:ss")))\
        ui->lb_Timer_##oTimer->setStyleSheet("color: red");\
    if(!null.compare(tCount_##oTimer.toString("hh:mm:ss")))\
        bCountdown_##oTimer = true;


// called after 1 second of the timer runned down (declaration see l. 34)
void Preisleiter::myTimer_TimeOut()
{

    if(bCountdown_1 == false)
    {
        Timerrunner(1);
    }
    else if(bCountdown_2 == false)
    {
        Timerrunner(2);
    }
    else if(bCountdown_3 == false)
    {
        Timerrunner(3);
    }
    else if(bCountdown_4 == false)
    {
        Timerrunner(4);
    }
    else if(bCountdown_5 == false)
    {
        Timerrunner(5);
    }

    else
    {
        myTimer->stop();
    }

}

// called after menu-bar entry 'Start Timer' was pushed
void Preisleiter::on_startTimer_triggered()
{
    myTimer->start();
}

// called after menu-bar entry 'Stop Timer' was pushed
void Preisleiter::on_stopTimer_triggered()
{
    myTimer->stop();
}


//Macro for reseting the timer's
#define ResetTimer(oTimer)\
    bCountdown_##oTimer = false ;\
    iTimer_##oTimer = 1;\
    ui->lb_Timer_##oTimer->setText(time_##oTimer.toString("hh:mm:ss"));

// called after menu-bar entry 'Reset Timer' was pushed
void Preisleiter::on_resetTimer_triggered()
{
    if(myTimer->isActive())
    {
        QMessageBox::warning(this,
                             tr("Preisleiter"),
                             tr("There is still a timer running."));
    }
    else
    {
        ResetTimer(1);
        ResetTimer(2);
        ResetTimer(3);
        ResetTimer(4);
        ResetTimer(5);
    }
}

// called after menu-bar entry 'Abort Timer' was pushed
// if pressed, timer will be stopped and all timer's will be reseted
void Preisleiter::on_abortTimer_triggered()
{
    myTimer->stop();
    ResetTimer(1);
    ResetTimer(2);
    ResetTimer(3);
    ResetTimer(4);
    ResetTimer(5);
}

void Preisleiter::on_closeApp_triggered()
{
    this->close();
}
