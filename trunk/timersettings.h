#pragma once

#include <QDialog>

#include "preisleiter.h"

namespace Ui
{
    class TimerSettings;
}

class TimerSettings : public QDialog
{
    Q_OBJECT

public:
    explicit TimerSettings(QWidget *parent = nullptr);
    ~TimerSettings();



private slots:


    void on_pB_SetTimer_clicked();

    void on_pB_Close_clicked();

private:
    Ui::TimerSettings *ui;
};
