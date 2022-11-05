#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include <iostream>

#include "timer_setup_dialog.h"

class cPreisleiter : public QMainWindow 
{
    Q_OBJECT

public:
    cPreisleiter();
    virtual ~cPreisleiter();

    void addMenu();
    void initTimerLabels();

private slots:
    void startTimer();
    void stopTimer();
    void resetTimer();
    void setupTimer();
    void setupBackground();
    void setupTimerSettings();
    void refreshTimer();

signals:
    void updateTimerSettings();

private:
    // Default application elements
    QWidget* pCentralWidget   = { nullptr };
    QVBoxLayout* pLayout      = { nullptr };
    QLabel* pDescription      = { nullptr };
                              
    // Menuentries            
    QMenu* timerMenu          = { nullptr };
    QMenu* settingsMenu       = { nullptr };
                              
    // Actions                
    QAction* pStartTimer      = { nullptr };
    QAction* pStopTimer       = { nullptr };
    QAction* pResetTimer      = { nullptr };
    QAction* pSetupTimer      = { nullptr };
    QAction* pSetupBackground = { nullptr };

    // Timer
    QTimer* pCountdown      = { nullptr };

    // Timer Labels
    QLabel* pTimerLabel1 = { nullptr };
    QLabel* pTimerLabel2 = { nullptr };
    QLabel* pTimerLabel3 = { nullptr };
    QLabel* pTimerLabel4 = { nullptr };
    QLabel* pTimerLabel5 = { nullptr };

    // Additional Dialogs
    cTimerSetupDialog oTimerSetupDialog;

    // Timer Status
    bool bCountdown_1 = { false };
    bool bCountdown_2 = { false };
    bool bCountdown_3 = { false };
    bool bCountdown_4 = { false };
    bool bCountdown_5 = { false };

    // Timer Value
    int nSeconds      = { 0 };
    int nTimerValue_1 = { 1 };
    int nTimerValue_2 = { 1 };
    int nTimerValue_3 = { 1 };
    int nTimerValue_4 = { 1 };
    int nTimerValue_5 = { 1 };
    QTime oTime_1 = QTime{ 0, 0, 0, 0 };
    QTime oTime_2 = QTime{ 0, 0, 0, 0 };
    QTime oTime_3 = QTime{ 0, 0, 0, 0 };
    QTime oTime_4 = QTime{ 0, 0, 0, 0 };
    QTime oTime_5 = QTime{ 0, 0, 0, 0 };

public:
    std::vector<tTimerSettings> vecTimerSettings = {};
};