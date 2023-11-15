#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"

class MiCaracter: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event);      //evento de presionar tecla
};

#endif // MICARACTER_H
