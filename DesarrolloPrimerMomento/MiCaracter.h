#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas
#include "bala.h"
#include "balaesp.h"

class MiCaracter: public QGraphicsRectItem, public QObject
{
public:
    MiCaracter(QList<QGraphicsItem *> *items);
    void keyPressEvent(QKeyEvent * event) override;      //evento de presionar tecla
public slots:
    void permitirNormal();
    void permitirEspecial();
private:
    bool disparoNormal;
    bool disparoEsp;
    qreal distancia;
    int balaOpc;
    QList<QGraphicsItem *> *items;

    void tryMove(qreal dx, qreal dy);
};

#endif // MICARACTER_H
