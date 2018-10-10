#include "preisleiter.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Preisleiter w;

    QRect oRect = a.desktop()->screenGeometry();
    w.setGeometry(oRect);

    w.show();

    return a.exec();
}
