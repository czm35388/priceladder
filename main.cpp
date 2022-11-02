#include "preisleiter.h"
#include <QApplication>
#include <QWidget>
#include <QDesktopWidget>
//#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Preisleiter w;

    // before starting identify the size of the current screen
    w.setGeometry(a.desktop()->screenGeometry());
    w.show();

    return a.exec();
}
