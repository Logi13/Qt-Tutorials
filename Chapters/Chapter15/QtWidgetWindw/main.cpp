#include "mainwindow.h"
#include <QApplication>
#include <QtGui>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Create the ui here
    MainWindow w;
    w.resize(320, 240);
    w.show();

    return a.exec(); //event loop
}
