#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "obstaculo.h"

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <stdlib.h>
#include <cstdlib>
#include<ctime>
#include <QRect>



class Enemigo: public QObject,  public QGraphicsRectItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
public:
    Enemigo(QList<QGraphicsItem *> items);
public slots:
    void desplazamiento();
    void disparar(){}
private:
    QRect enemigo;
    QList<QGraphicsItem *> items;
};

#endif // ENEMIGO_H
