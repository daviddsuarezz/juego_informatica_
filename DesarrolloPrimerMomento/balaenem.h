#ifndef BALAENEM_H
#define BALAENEM_H

#include "bala.h"
#include <QGraphicsScene>
#include "MiCaracter.h"
//#include "mainwindow.h"

//extern MainWindow * mainWindow;

class BalaEnem: public Bala
{
    Q_OBJECT
public:
    BalaEnem();
public slots:
    void desplazamiento() override;
};

#endif // BALAENEM_H
