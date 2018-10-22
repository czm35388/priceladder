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
        TimerSettings oTimerSettings;
        oTimerSettings.setModal(true);
        oTimerSettings.exec();
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
