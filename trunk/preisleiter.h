#ifndef PREISLEITER_H
#define PREISLEITER_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QLCDNumber>
#include <QFont>

namespace Ui {
class Preisleiter;
}

class Preisleiter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Preisleiter(QWidget *parent = 0);
    ~Preisleiter();

    int iSecs = 0;
    int iTimer_1 = 1;
    int iTimer_2 = 1;
    int iTimer_3 = 1;
    int iTimer_4 = 1;
    int iTimer_5 = 1;

    bool bCountdown_1 = false;
    bool bCountdown_2 = false;
    bool bCountdown_3 = false;
    bool bCountdown_4 = false;
    bool bCountdown_5 = false;

private slots:
    void on_pB_Start_released();

public slots:
    void myTimer_TimeOut();

private:
    Ui::Preisleiter *ui;

    QTimer* myTimer = new QTimer();

    QTime time_1 = QTime::QTime(0, 30, 0, 0);
    QTime time_2 = QTime::QTime(1,  0, 0, 0);
    QTime time_3 = QTime::QTime(0, 30, 0, 0);
    QTime time_4 = QTime::QTime(1,  0, 0, 0);
    QTime time_5 = QTime::QTime(3,  0, 0, 0);

    QString null = "00:00:00";
    QString fünf = "00:05:00";

    void Countdown_1();
    void Countdown_2();
    void Countdown_3();
    void Countdown_4();
    void Countdown_5();
};

#endif // PREISLEITER_H
