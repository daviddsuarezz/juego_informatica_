#include "mainwindow.h"
#include <QApplication>


#include "GlobalVariable.h"

#include <QDebug>



int main(int argc, char *argv[])
{
    //int globalVariable = 0;
    QApplication a(argc, argv);
    qDebug()<< globalVariable;
    //if(globalVariable == 0){

        MainWindow w(argv);


    //}
    //cout << endl << "globalVariable";
    return a.exec();
}
