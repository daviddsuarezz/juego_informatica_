#include "mainwindow.h"
#include <QApplication>




#include <QDebug>






int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w(argv);
    qDebug()<< 26;

    return a.exec();
}
