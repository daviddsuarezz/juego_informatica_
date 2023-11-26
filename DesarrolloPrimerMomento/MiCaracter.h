#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"


class MiCaracter: public QGraphicsRectItem, public QObject
{
public:
    void keyPressEvent(QKeyEvent * event) override;      //evento de presionar tecla
public slots:
};

#endif // MICARACTER_H
