#ifndef MICARACTER_H
#define MICARACTER_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QKeyEvent> // Captura de teclas

#include "balaesp.h"
#include <QObject>

class MiCaracter: public QObject, public QGraphicsRectItem
{Q_OBJECT

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
