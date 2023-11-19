#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QPointF>
#include <QObject>
#include "Player.h"
#include "Game.h"

class Tower:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Tower(Player * player);
    double distanceTo(QGraphicsItem * item);
    void fire();
    int health;
    QGraphicsRectItem * healthBar;
public slots:

    void aquire_target();
private:
    QGraphicsPolygonItem * attack_area;
    QPointF attack_dest;
    Player * player;

};

#endif // TOWER_H
