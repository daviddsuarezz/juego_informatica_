#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "obstaculo.h"

#include <QGraphicsEllipseItem>
#include <QTimer>
#include <QObject>
#include <stdlib.h>
#include <cstdlib>
#include<ctime>




class Enemigo: public QObject,  public QGraphicsEllipseItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
public:
    Enemigo(QList<QGraphicsItem *> items);
public slots:
    void desplazamiento();
    void disparar(){}
private:
    //QRect enemigo;
    QList<QGraphicsItem *> items;
};

#endif // ENEMIGO_H
