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


void TimerSettings::on_pB_SetTimer_clicked()
{
    mainpage.abortTimer();
    mainpage.time_1.setTime(ui->tE_ts_Timer_1->getTime());
}

void TimerSettings::on_pB_Close_clicked()
{

}
