#include "timer_setup_dialog.h"
#include <iostream>

cTimerSetupDialog::cTimerSetupDialog(QWidget* parent) 
    : QDialog(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;

    okButton = new QPushButton{ "OK" };
    cancelButton = new QPushButton{ "Cancel" };
    nTimer = { 5 };
    
    for (int i = 1; i <= nTimer; i++)
    {
        vecGroupBoxList.push_back(createTimerGroupBox(i));
        vecTimerSettings.push_back({ QTime{0,0,0}, {0}, {0} });
    }

    QHBoxLayout* buttonLayout = new QHBoxLayout{};
    QSpacerItem* pSpacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    buttonLayout->addSpacerItem(pSpacerItem);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    
    for (const auto pGroupBox : vecGroupBoxList)
    {
        mainLayout->addWidget(pGroupBox);
    }
    mainLayout->addLayout(buttonLayout);
    setLayout(mainLayout);

    connect(this, &cTimerSetupDialog::setTimerSettings, this, &QDialog::accept);
    connect(okButton, &QAbstractButton::clicked, this, &cTimerSetupDialog::getTimerSettings);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle("Timer Settings");
    setMinimumWidth(400);
}

cTimerSetupDialog::~cTimerSetupDialog()
{

}

QGroupBox* cTimerSetupDialog::createTimerGroupBox(int nTimerIncrement)
{
    QGroupBox* pTimerGroupBox = new QGroupBox{ this };
    QString strObjectName = { "Timer " + QString::number(nTimerIncrement)};
    pTimerGroupBox->setTitle(strObjectName);
    pTimerGroupBox->setObjectName(strObjectName);

    QHBoxLayout* durationLayout = new QHBoxLayout{ };
    durationLayout->addWidget(new QLabel{ "Duration [H:mm:ss]" });
    QTimeEdit* pTimeEdit = new QTimeEdit{ QTime(0,0,0) };
    pTimeEdit->setObjectName("timeEdit");
    pTimeEdit->setDisplayFormat("H:mm:ss");
    durationLayout->addWidget(pTimeEdit);

    QHBoxLayout* xLocationLayout = new QHBoxLayout{ };
    xLocationLayout->setObjectName("xLocationLayout");
    xLocationLayout->addWidget(new QLabel{ "X-Location [int]" });
    QSpinBox* oXSpinBox = new QSpinBox{};
    oXSpinBox->setObjectName("xSpinBox");
    oXSpinBox->setMaximum(5000);
    xLocationLayout->addWidget(oXSpinBox);

    QHBoxLayout* yLocationLayout = new QHBoxLayout{ };
    yLocationLayout->setObjectName("yLocationLayout");
    yLocationLayout->addWidget(new QLabel{ "Y-Location [int]" });
    QSpinBox* oYSpinBox = new QSpinBox{};
    oYSpinBox->setObjectName("ySpinBox");
    oYSpinBox->setMaximum(5000);
    yLocationLayout->addWidget(oYSpinBox);

    QVBoxLayout* timerLayout = new QVBoxLayout;
    timerLayout->addLayout(durationLayout);
    timerLayout->addLayout(xLocationLayout);
    timerLayout->addLayout(yLocationLayout);

    pTimerGroupBox->setLayout(timerLayout);

    return pTimerGroupBox;
}

void cTimerSetupDialog::getTimerSettings()
{
    for (int i = 0; i < nTimer; i++)
    {
        QGroupBox* oGroupBoxItem = vecGroupBoxList.at(i);

        auto oChilds = oGroupBoxItem->children();
        for (const auto oChild : oChilds)
        {
            QString strObjectName = oChild->objectName();

            if (!strObjectName.compare("timeEdit"))
            {
                QTimeEdit* oTime = static_cast<QTimeEdit*>(oChild);
                vecTimerSettings.at(i).oTime = oTime->time();
            }
            else if (!strObjectName.compare("xSpinBox"))
            {
                QSpinBox* oXSpinBox = static_cast<QSpinBox*>(oChild);
                vecTimerSettings.at(i).nXLocation = oXSpinBox->value();
            }
            else if (!strObjectName.compare("ySpinBox"))
            {
                QSpinBox* oYSpinBox = static_cast<QSpinBox*>(oChild);
                vecTimerSettings.at(i).nYLocation = oYSpinBox->value();
            }
        }
    }
    emit(setTimerSettings());
}