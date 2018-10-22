#include "timersettings.h"
#include "ui_timersettings.h"

TimerSettings::TimerSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimerSettings)
{
    ui->setupUi(this);
}

TimerSettings::~TimerSettings()
{
    delete ui;

}
