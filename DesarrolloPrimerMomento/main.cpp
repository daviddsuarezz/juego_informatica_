//#include "mainwindow.h"
#include <QApplication>



#include <QDebug>

#include <QGraphicsScene>

#include "EscenaInicial.h"




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    EscenaInicial escena(argv);
    //escena = new EscenaInicial(argv);
    //escena->show();
    //escena->displayMainMenu();


    //MainWindow w(argv);



    return a.exec();
}
