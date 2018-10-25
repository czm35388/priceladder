#include "preisleiter.h"
#include "ui_preisleiter.h"

#define SetLabel(oTimer, iHeight)\
    ui->lb_Timer_##oTimer->setText(time_##oTimer.toString("h:mm:ss"));\
    ui->lb_Timer_##oTimer->setGeometry(((iScreenwidth/100)*57), ((iScreenheigth/100)*iHeight), 300, 75);

// CTOR
Preisleiter::Preisleiter(QWidget *parent) : QMainWindow(parent),
                                            ui(new Ui::Preisleiter)
{
    ui->setupUi(this);
    ui->centralWidget->setWindowTitle("Preisleiter");
    ui->qW_TimerSettings->setVisible(false);

    ui->qT_SetTime_1->time() = time_1;
    ui->qT_SetTime_2->time() = time_2;
    ui->qT_SetTime_3->time() = time_3;
    ui->qT_SetTime_4->time() = time_4;
    ui->qT_SetTime_5->time() = time_5;

    //@todo set the path via the gui-settings "background"
    QDir dir = QDir::currentPath();
    QString file = "FactoryPreisleiter.jpg";
    QFileInfo fi(dir, file);
    QString path = fi.absoluteFilePath();

    QPixmap bkgnd(path);
    bkgnd = bkgnd.scaled(iScreenwidth, iScreenheigth, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    Rendering();

    SetLabel(1, 29);
    SetLabel(2, 44);
    SetLabel(3, 60);
    SetLabel(4, 76);
    SetLabel(5, 91);

    myTimer->setInterval(1000);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(myTimer_TimeOut()));
}

// DTOR
Preisleiter::~Preisleiter()
{
    delete ui;
}

void Preisleiter::Rendering()
{
    if(iScreenwidth >= 1870 && iScreenwidth <= 1200)
    {
        SetLabel(1, 29);
        SetLabel(2, 44);
        SetLabel(3, 60);
        SetLabel(4, 76);
        SetLabel(5, 91);
    }
    else if (iScreenwidth >= 1200 && iScreenwidth <= 1300)
    {
        SetLabel(1, 29);
        SetLabel(2, 44);
        SetLabel(3, 60);
        SetLabel(4, 76);
        SetLabel(5, 91);
    }

    else if(iScreenwidth >= 1310 && iScreenwidth <= 1410)
    {
        SetLabel(1, 29);
        SetLabel(2, 44);
        SetLabel(3, 60);
        SetLabel(4, 76);
        SetLabel(5, 91);
    }
}

// makro for refreshing the shown time
#define Timerrunner(oTimer)\
    iTimer_##oTimer -= 1;\
    QTime tCount_##oTimer = time_##oTimer.addSecs(iTimer_##oTimer);\
    ui->lb_Timer_##oTimer->setText(tCount_##oTimer.toString("h:mm:ss"));\
    if(!fuenf.compare(tCount_##oTimer.toString("h:mm:ss")))\
    {\
        ui->lb_Timer_##oTimer->setStyleSheet("color: rgb(255, 0, 0);");\
    }\
    if(!null.compare(tCount_##oTimer.toString("h:mm:ss")))\
    {\
        CallGif(oTimer);\
        bCountdown_##oTimer = true;\
    };


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

#define SetTimerValue(oTimer)\
    ui->lb_Timer_##oTimer->setText(time_##oTimer.toString("h:mm:ss"));\

void Preisleiter::SetTimer()
{
    abortTimer();
    ui->lb_Timer_1->setText(time_1.toString("h:mm:ss"));
    ui->lb_Timer_2->setText(time_2.toString("h:mm:ss"));
    ui->lb_Timer_3->setText(time_3.toString("h:mm:ss"));
    ui->lb_Timer_4->setText(time_4.toString("h:mm:ss"));
    ui->lb_Timer_5->setText(time_5.toString("h:mm:ss"));
}

//*************************************************************************************************
//*************************************************************************************************
//
//  Settings of menu-bar-entries
//
//*************************************************************************************************
//*************************************************************************************************

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
    ui->lb_Timer_##oTimer->setText(time_##oTimer.toString("h:mm:ss"));

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
        fResetTimer();
    }
}

void Preisleiter::fResetTimer()
{
    ResetTimer(1);
    ResetTimer(2);
    ResetTimer(3);
    ResetTimer(4);
    ResetTimer(5);
}

// called after menu-bar entry 'Abort Timer' was pushed
// if pressed, timer will be stopped and all timer's will be reseted
void Preisleiter::on_abortTimer_triggered()
{
    abortTimer();
}

void Preisleiter::abortTimer()
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


//*************************************************************************************************
//*************************************************************************************************
//
//  Settings of menu-bar-entries
//
//*************************************************************************************************
//*************************************************************************************************

// called after settings-bar entry 'Set Timers' was pushed
void Preisleiter::on_setTimers_triggered()
{
    if(myTimer->isActive())
    {
        QMessageBox::warning(this,
                             tr("Preisleiter"),
                             tr("There is still a timer running. \
                                 You only can set the timers, if you stop the timers"));
    }
    else
    {
        ui->qW_TimerSettings->setVisible(true);

    }
}

// @todo implementation of the functionality
// called after settings-bar entry 'Set Background' was pushed
void Preisleiter::on_setBackground_triggered()
{
    QMessageBox::warning(this,
                         tr("Preisleiter"),
                         tr("This function is not implemented yet."));
}


// @todo implementation of calling Gif's after Timers run down
void Preisleiter::CallGif(int iTimer)
{
    switch (iTimer) {
        case 1:
                 break;
        case 2:
                 break;
        case 3:
                 break;
        case 4:
                 break;
        case 5:
                 break;
        default: break;
    }
}

void Preisleiter::on_pB_SetTimer_clicked()
{
    time_1 = ui->qT_SetTime_1->time();
    time_2 = ui->qT_SetTime_2->time();
    time_3 = ui->qT_SetTime_3->time();
    time_4 = ui->qT_SetTime_4->time();
    time_5 = ui->qT_SetTime_5->time();

    SetTimer();
}

void Preisleiter::on_pB_CloseSettings_clicked()
{
    ui->qW_TimerSettings->setVisible(false);
}
