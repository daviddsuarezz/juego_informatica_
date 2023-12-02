#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"
#include "balaesp.h"

class MiCaracter: public QGraphicsRectItem, public QObject
{
public:
    MiCaracter(QList<QGraphicsItem *> *items);
    void keyPressEvent(QKeyEvent * event) override;      //evento de presionar tecla
private:
    int balaOpc;
    QList<QGraphicsItem *> *items;
};

#endif // MICARACTER_H
