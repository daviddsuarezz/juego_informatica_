#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsRectItem>

class Health: public QGraphicsRectItem{

public:
    Health(QGraphicsItem * parent= 0);
    void decrease();
    int getHealth();

private:
    int health;
    QGraphicsRectItem *healthBar;


};

#endif // HEALTH_H
