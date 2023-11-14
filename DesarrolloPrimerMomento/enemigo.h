#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <QGraphicsScene>
#include <stdlib.h>

class Enemigo:public QObject, public QGraphicsRectItem
{
private:
    QTimer *tiempo;
public:
    Enemigo();
public slots:
    void desplazamiento();
};

#endif // ENEMIGO_H
