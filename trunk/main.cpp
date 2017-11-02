#include "preisleiter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Preisleiter w;
    w.show();

    return a.exec();
}
