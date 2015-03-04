#include <QtGui/QApplication>
#include "mainwindow.h"

/** Default class. Needed for the GUI to show*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
