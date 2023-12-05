#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Enemy(QGraphicsItem * parent=0);
    // señal y slots

public slots:
    void move();



};
#endif // ENEMY_H
