#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
//debe ser derivada de object dpara poder utilizar ranuras
class Bullet:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Bullet(QGraphicsItem * parent=0);
    // señal y slots

public slots:
    void move();



};

#endif // BULLET_H
