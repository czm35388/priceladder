#include "preisleiter.h"

cPreisleiter::cPreisleiter()
{
    pCentralWidget = new QWidget();
    setCentralWidget(pCentralWidget);

    pCentralWidget->setObjectName("Preisleiter_Widget");
    pCentralWidget->setMinimumSize(400, 350);
    pCentralWidget->resize(400, 350);

    // Setup a first description, this will be shown in the CentralWidget 
    // and deleted after the Background has been setup.
    pDescription = new QLabel( pCentralWidget );
    pDescription->setText(
        "Usage: \n"
        "1. Setup Background:\tWill set your img to the Background of the application. \n"
        "2. Setup Timer:\t\tSetup the duration and location of your timers. \n"
        "3. Start Timer:\t\tStart the timers. \n"
        "4. Stop Timer:\t\tStop the timers.");

    pDescription->setGeometry(0, 0, 400, 250);

    pTimerLabel1 = new QLabel { pCentralWidget };
    pTimerLabel2 = new QLabel { pCentralWidget };
    pTimerLabel3 = new QLabel { pCentralWidget };
    pTimerLabel4 = new QLabel { pCentralWidget };
    pTimerLabel5 = new QLabel { pCentralWidget };

    setWindowTitle(tr("Preisleiter"));

    addMenu();

    pCountdown = new QTimer();
    pCountdown->setInterval(1000);
    connect(pCountdown, &QTimer::timeout, this, &cPreisleiter::refreshTimer);


    connect(this, &cPreisleiter::updateTimerSettings, this, &cPreisleiter::setupTimerSettings);
}

cPreisleiter::~cPreisleiter()
{
    // delete all pointers
    // the QAction pointers will be destroyed automatically by destroying the QMenu pointers!
    delete(pLayout);
    delete(timerMenu);
    delete(settingsMenu);
    delete(pTimerLabel1);
    delete(pTimerLabel2);
    delete(pTimerLabel3);
    delete(pTimerLabel4);
    delete(pTimerLabel5);


}

void cPreisleiter::addMenu()
{
    timerMenu = menuBar()->addMenu("Timer");
    pStartTimer = timerMenu->addAction("Start Timer");
    pStopTimer = timerMenu->addAction("Stop Timer");
    
    settingsMenu = menuBar()->addMenu("Settings");
    pSetupTimer = settingsMenu->addAction("Setup Timer");
    pSetupBackground = settingsMenu->addAction("Setup Background");

    connect(pStartTimer, &QAction::triggered, this, &cPreisleiter::startTimer);
    connect(pStopTimer, &QAction::triggered, this, &cPreisleiter::stopTimer);
    connect(pSetupTimer, &QAction::triggered, this, &cPreisleiter::setupTimer);
    connect(pSetupBackground, &QAction::triggered, this, &cPreisleiter::setupBackground);
}

void cPreisleiter::initTimerLabels()
{
    QString strLabelStyle = { "font: 40pt; color: rgb(255, 255, 0);" };
    pTimerLabel1->setGeometry(0, 0, 300, 75);
    pTimerLabel2->setGeometry(0, 75, 300, 75);
    pTimerLabel3->setGeometry(0, 150, 300, 75);
    pTimerLabel4->setGeometry(0, 225, 300, 75);
    pTimerLabel5->setGeometry(0, 300, 300, 75);
    pTimerLabel1->setStyleSheet(strLabelStyle);
    pTimerLabel2->setStyleSheet(strLabelStyle);
    pTimerLabel3->setStyleSheet(strLabelStyle);
    pTimerLabel4->setStyleSheet(strLabelStyle);
    pTimerLabel5->setStyleSheet(strLabelStyle);
}

void cPreisleiter::startTimer()
{
    pCountdown->start();
}

void cPreisleiter::stopTimer()
{
    pCountdown->stop();
}

void cPreisleiter::setupTimer()
{
    if (oTimerSetupDialog.exec()) 
    {
        vecTimerSettings = oTimerSetupDialog.vecTimerSettings;
        emit(updateTimerSettings());
    }
}

void cPreisleiter::setupBackground()
{
    QString strFileName = QFileDialog::getOpenFileName(this, "Open Backgroung-Image", QDir::currentPath(), "Image Files (*.png *.jpg)");
    QString strStyleSheet = { "#Preisleiter_Widget { background-image: url(" + strFileName + "); }" };
    pCentralWidget->setStyleSheet(strStyleSheet);

    pDescription->deleteLater();
    initTimerLabels();
}

void cPreisleiter::setupTimerSettings()
{
    pTimerLabel1->setGeometry(vecTimerSettings.at(0).nXLocation, vecTimerSettings.at(0).nYLocation, 300, 75);
    pTimerLabel1->setText(vecTimerSettings.at(0).oTime.toString());
    oTime_1 = vecTimerSettings.at(0).oTime;
    pTimerLabel2->setGeometry(vecTimerSettings.at(1).nXLocation, vecTimerSettings.at(1).nYLocation, 300, 75);
    pTimerLabel2->setText(vecTimerSettings.at(1).oTime.toString());
    oTime_2 = vecTimerSettings.at(1).oTime;
    pTimerLabel3->setGeometry(vecTimerSettings.at(2).nXLocation, vecTimerSettings.at(2).nYLocation, 300, 75);
    pTimerLabel3->setText(vecTimerSettings.at(2).oTime.toString());
    oTime_3 = vecTimerSettings.at(2).oTime;
    pTimerLabel4->setGeometry(vecTimerSettings.at(3).nXLocation, vecTimerSettings.at(3).nYLocation, 300, 75);
    pTimerLabel4->setText(vecTimerSettings.at(3).oTime.toString());
    oTime_4 = vecTimerSettings.at(3).oTime;
    pTimerLabel5->setGeometry(vecTimerSettings.at(4).nXLocation, vecTimerSettings.at(4).nYLocation, 300, 75);
    pTimerLabel5->setText(vecTimerSettings.at(4).oTime.toString());
    oTime_5 = vecTimerSettings.at(4).oTime;
}

// makro for refreshing the shown time
#define Timerrunner(oTimer)\
    nTimerValue_##oTimer -= 1;\
    QTime tCounterTime_##oTimer = oTime_##oTimer.addSecs(nTimerValue_##oTimer);\
    pTimerLabel##oTimer->setText(tCounterTime_##oTimer.toString("h:mm:ss"));\
    if(!tCounterTime_##oTimer.toString("h:mm:ss").compare("0:05:00"))\
    {\
        pTimerLabel##oTimer->setStyleSheet("font: 40pt; color: rgb(255, 0, 0);");\
    }\
    if(!tCounterTime_##oTimer.toString("h:mm:ss").compare("0:00:00"))\
    {\
        pTimerLabel##oTimer->setStyleSheet("font: 40pt; color: rgb(0, 50, 255);");\
        bCountdown_##oTimer = true;\
    };



void cPreisleiter::refreshTimer()
{
    setupTimerSettings();

    if (bCountdown_1 == false)
    {
        Timerrunner(1)
    }
    else if (bCountdown_2 == false)
    {
        Timerrunner(2)
    }
    else if (bCountdown_3 == false)
    {
        Timerrunner(3)
    }
    else if (bCountdown_4 == false)
    {
        Timerrunner(4)
    }
    else if (bCountdown_5 == false)
    {
        Timerrunner(5)
    }

    else
    {
        pCountdown->stop();
    }
}