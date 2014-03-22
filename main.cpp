#include "robotika.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Robotika w;
    w.show();
    //w.showFullScreen();
    return a.exec();
}
