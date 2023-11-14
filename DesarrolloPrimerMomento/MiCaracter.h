#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"

#include <QObject>

class MiCaracter: public QGraphicsRectItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);      //evento de presionar tecla
public slots:

};

#endif // MICARACTER_H
