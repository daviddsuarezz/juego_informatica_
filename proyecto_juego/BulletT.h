#ifndef BULLETT_H
#define BULLETT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class BulletT: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BulletT(QGraphicsItem * parent=0);

public slots:
    void move();

};

#endif // BULLETT_H
