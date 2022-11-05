#include <QApplication>
#include "preisleiter.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    cPreisleiter w;

    w.show();

    return a.exec();
}