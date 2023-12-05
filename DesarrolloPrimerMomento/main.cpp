//#include "mainwindow.h"
#include <QApplication>



#include <QDebug>

#include <QGraphicsScene>

#include "EscenaInicial.h"


EscenaInicial * escena;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    escena = new EscenaInicial(argv);
    escena->show();
    escena->displayMainMenu();


    //MainWindow w(argv);



    return a.exec();
}
