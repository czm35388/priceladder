#pragma once

#include <QDialog>
#include <QLabel>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTimeEdit>
#include <QSPinBox>
#include <QGroupBox>
#include <QTime>

struct tTimerSettings
{
    QTime oTime     = {0,0,0};
    int nXLocation  = { 1050 };
    int nYLocation  = { 0 };
};

class cTimerSetupDialog : public QDialog
{
    Q_OBJECT

public:
    cTimerSetupDialog(QWidget* parent = 0);
    ~cTimerSetupDialog();

    QGroupBox* createTimerGroupBox(int nTimerIncrement);

    std::vector<tTimerSettings> vecTimerSettings = {};

private slots:
    void getTimerSettings();

signals:
    void setTimerSettings();

private:
    QPushButton* okButton       = { nullptr };
    QPushButton* cancelButton   = { nullptr };
    int nTimer                  = { 0 };
    std::vector<QGroupBox*> vecGroupBoxList = { };
};