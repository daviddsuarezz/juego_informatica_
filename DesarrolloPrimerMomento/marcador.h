#ifndef MARCADOR_H
#define MARCADOR_H

#include <QGraphicsTextItem>


class Marcador: public QGraphicsTextItem
{
public:
    Marcador(QGraphicsItem * parent = 0);
    void aumentar();
    int getMarcador();
private:
    int marcador;
};

#endif // MARCADOR_H
