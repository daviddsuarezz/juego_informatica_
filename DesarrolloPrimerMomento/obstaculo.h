#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsItem>


class Obstaculo: public QObject, public QGraphicsRectItem
{
public:
    Obstaculo();
};

#endif // OBSTACULO_H
