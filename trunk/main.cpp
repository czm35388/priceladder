#include "preisleiter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Preisleiter w;
    //w.setStyleSheet("background-image:url(/Users/Michael/Documents/Programmierung/Git_Repos/priceladder/src/Factory_Preisleiter_Präsentation.jpg)");
    w.show();

    return a.exec();
}
