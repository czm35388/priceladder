#include "timersettings.h"
#include "ui_timersettings.h"


#define getTime(oTimer)\
    ui->tE_ts_Timer_##oTimer->setTime(mainpage.time_##oTimer);

TimerSettings::TimerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSettings)
{
    ui->setupUi(this);
    Preisleiter mainpage;
    getTime(1);
    getTime(2);
    getTime(3);
    getTime(4);
    getTime(5);
}



TimerSettings::~TimerSettings()
{
    delete ui;

}

#define setTime(oTimer)\
    mainpage.time_##oTimer = ui->tE_ts_Timer_##oTimer->time();

void TimerSettings::on_pB_SetTimer_clicked()
{
    Preisleiter mainpage;
    setTime(1);
    setTime(2);
    setTime(3);
    setTime(4);
    setTime(5);
    this->close();
    mainpage.activateWindow();
    mainpage.SetTimer();

}

void TimerSettings::on_pB_Close_clicked()
{

}
