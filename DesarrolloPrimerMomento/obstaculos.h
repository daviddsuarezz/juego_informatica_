#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QTime>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QObject>
#include <QSet>


class Obstaculos: public QObject, public QGraphicsRectItem
{
public:
    Obstaculos(QSet<QGraphicsItem *> items);
};

#endif // OBSTACULOS_H
