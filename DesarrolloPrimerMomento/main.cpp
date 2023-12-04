#include "mainwindow.h"
#include <QApplication>
#include <iostream>

//#include "GlobalVariable.h"

using namespace std;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //while(bandera == 0){
        MainWindow w(argv);
    //}
    cout << endl << "Salí";
    return a.exec();
}
