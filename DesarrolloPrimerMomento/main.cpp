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
    /*try{
        MainWindow w(argv);
    }catch(int num){
        if (num == 1){
            qDebug() << "Salí por tangente";
        }
        else qDebug() << "Salí por x";
    }
*/
    //}

    return a.exec();
}
