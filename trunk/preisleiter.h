#ifndef PREISLEITER_H
#define PREISLEITER_H

#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QLCDNumber>
#include <QFont>

namespace Ui
{
    class Preisleiter;
}

class Preisleiter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Preisleiter(QWidget *parent = nullptr);
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

   public:


private slots:
    void on_pB_Start_released();
    void on_actionStart_Countdown_triggered();
    void on_actionStop_Countdown_triggered();
    void on_actionAbort_Countdown_triggered();
    void on_actionReset_Time_triggered();
    void on_actionClose_triggered();

public slots:
    void myTimer_TimeOut();

private:
    Ui::Preisleiter *ui;

    QTimer* myTimer = new QTimer();

    QTime time_1 = QTime(0, 0, 5, 0);
    QTime time_2 = QTime(0, 0, 5, 0);
    QTime time_3 = QTime(0, 0, 5, 0);
    QTime time_4 = QTime(0, 0, 5, 0);
    QTime time_5 = QTime(0, 0, 5, 0);

    QString null = "00:00:00";
    QString fünf = "00:05:00";

    void Countdown_1();
    void Countdown_2();
    void Countdown_3();
    void Countdown_4();
    void Countdown_5();

    QRect oScreensize = QApplication::desktop()->screenGeometry();
    int iScreenheigth = oScreensize.height();
    int iScreenwidth  = oScreensize.width();
};

#endif // PREISLEITER_H
