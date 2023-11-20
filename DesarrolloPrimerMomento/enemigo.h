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



class Enemigo: public QObject, public QRect, public QGraphicsRectItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
public:
    Enemigo();
public slots:
    void desplazamiento();
};

#endif // ENEMIGO_H
