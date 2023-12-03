#ifndef BALAENEM_H
#define BALAENEM_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <QList>

#include <QWidget>
#include <QPainter>
#include <QTimer>

#include "obstaculo.h"
#include "MiCaracter.h"

class BalaEnem: public QObject, public QGraphicsRectItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
protected:
    QTimer *tiempo;
    int cambioX;
    int cambioY;
public:
    BalaEnem();
    void setCambioX(int cambio);
    void setCambioY(int cambio);
    ~BalaEnem();

public slots:
    virtual void desplazamiento();
signals:
    void colisionConPersonaje();

};


#endif // BALAENEM_H
