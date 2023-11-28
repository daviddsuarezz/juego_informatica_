#include "enemigo.h"
#include "MiCaracter.h"
#include "qgraphicsscene.h"

#include <QDebug>


bool colisiona1(QGraphicsItem *item, const QList<QGraphicsItem *> *items) {
    foreach (QGraphicsItem *other, *items) {
        if (item->collidesWithItem(other))
            return true;
    }
    return false;
}



Enemigo::Enemigo(QList<QGraphicsItem *> _items)
{
    items = _items;

    QGraphicsRectItem::setRect(0,0,29,29);


    QTimer * tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start((1 + rand() % 6)*100);          //cada 500ms se moverá la bala



}


void Enemigo::desplazamiento()
{
    int i = rand() % 4, cambioX = 0, cambioY = 0;
    switch(i){
    case 0:
        if (y()>0 )
            cambioY = - 30;
        else cambioY = 30;
        break;
    case 1:
        if (y() < scene()->height() - 30 )
            cambioY = 30;
        else  cambioY = -30;
        break;
    case 2:
        if (x()>0 )
            cambioX = -30;
        else  cambioX = 30;
        break;
    case 3:
        if (x() < scene()->width() - 30 )
            cambioX = 30;
        else cambioX = -30;
        break;
    default:
        break;
    }


    QList<QGraphicsItem *> colisiones = collidingItems(Qt::IntersectsItemShape);
    for(int i = 0, n = colisiones.size(); i < n; i++){
        if(typeid(*(colisiones[i])) == typeid(MiCaracter)){
            delete colisiones[i];
            return;
        }
        /*
        else if(typeid(*(colisiones[i])) == typeid(Obstaculo)){

        }*/

    }
    QGraphicsItem *itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
    if(!itemEnPosicion){
        setPos(x()+cambioX,y()+ cambioY);
    }
    //setPos(x()+cambioX, y()+cambioY);


/*
    QGraphicsItem *itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
    if(!itemEnPosicion){
        setPos(x()+cambioX,y()+ cambioY);
    }   */

}






