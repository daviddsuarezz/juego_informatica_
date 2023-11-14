#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"

class MiCaracter: public QGraphicsRectItem
{
public:
    void keyPressEvent(QKeyEvent * event);      //evento de presionar tecla
};

#endif // ELEMENTO_H
