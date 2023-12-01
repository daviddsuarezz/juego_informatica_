#ifndef MARCADOR_H
#define MARCADOR_H

#include <QGraphicsTextItem>
#include <QRectF>

class Marcador: public QGraphicsTextItem
{
public:
    Marcador(QGraphicsItem * parent = 0);
    QRectF boundingRect() const override {
        return QGraphicsTextItem::boundingRect().adjusted(0, 0, 0, 0);
    }
    void aumentar();
    int getMarcador();
private:
    int marcador;
};

#endif // MARCADOR_H
