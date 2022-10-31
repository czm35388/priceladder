#pragma once

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <QPixmap>
#include <QDir>
#include <QDesktopWidget>
#include <QTime>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <QGroupBox>

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

    QTime time_1 = QTime(0,  5,  0, 0);
    QTime time_2 = QTime(0,  5,  0, 0);
    QTime time_3 = QTime(0,  5,  0, 0);
    QTime time_4 = QTime(0,  5,  0, 0);
    QTime time_5 = QTime(0,  5,  0, 0);

private slots:
    //Menu settings
    void on_startTimer_triggered();
    void on_stopTimer_triggered();
    void on_abortTimer_triggered();
    void on_closeApp_triggered();
    void on_resetTimer_triggered();

    //Timer Settings
    void on_setTimers_triggered();
    void on_setBackground_triggered();
    void on_pB_SetTimer_clicked();
    void on_pB_CloseSettings_clicked();

public slots:
    void myTimer_TimeOut();
    void abortTimer();
    void fResetTimer();
    void SetTimer();
    void Rendering();

public:
    void CallGif(int iTimer);

private:
    Ui::Preisleiter *ui;

    QTimer* myTimer = new QTimer();

    QString null = "0:00:00";
    QString fuenf = "0:05:00";
    QString strStylesheet = "font: ";
    QString strColor = "";

    bool bRender = false;
    int iPixelsize = 0;
    int iLabelPosX = 0;
    int iLabelPosY_1 = 0;
    int iLabelPosY_2 = 0;
    int iLabelPosY_3 = 0;
    int iLabelPosY_4 = 0;
    int iLabelPosY_5 = 0;

    QRect oScreensize = QApplication::desktop()->screenGeometry();
    int iScreenheigth = oScreensize.height();
    int iScreenwidth  = oScreensize.width();
};

