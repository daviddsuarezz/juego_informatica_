#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <stdlib.h>
#include <cstdlib>
#include<ctime>

class Enemigo: public QObject, public QGraphicsRectItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
private:
    QTimer *tiempo;
public:
    Enemigo();
    ~Enemigo();
public slots:
    void desplazamiento();
};

#endif // ENEMIGO_H
