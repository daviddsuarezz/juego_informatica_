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
private:
    qreal distancia;
    int balaOpc;
    QList<QGraphicsItem *> *items;

    void tryMove(qreal dx, qreal dy) {
        // Obtener la posición actual del personaje
        QPointF posicionActual = pos();

        // Calcular la posición futura
        QPointF posicionFutura = posicionActual + QPointF(dx, dy);

        // Verificar colisiones con obstáculos
        QList<QGraphicsItem*> colisiones = scene()->items(posicionFutura.x(), posicionFutura.y(), 1, 1, Qt::IntersectsItemBoundingRect, Qt::SortOrder(Qt::AscendingOrder));

        foreach (QGraphicsItem *item, colisiones) {
            if (typeid(*item) == typeid(Obstaculo)) {
                // Hay un obstáculo en la posición futura, no mover al personaje
                return;
            }
            else if(typeid(*item) == typeid(Enemigo)){
                return;
            }
        }

        // No hay obstáculos en la posición futura, mover al personaje
        setPos(posicionFutura);
    }
};

#endif // MICARACTER_H
