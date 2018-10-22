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

private:
    Ui::TimerSettings *ui;
};
