#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"
#include "enemigo.h"

class MiCaracter: public QGraphicsRectItem, public QObject
{
public:
    void keyPressEvent(QKeyEvent * event);      //evento de presionar tecla
public slots:
    void aparecer();
};

#endif // MICARACTER_H
