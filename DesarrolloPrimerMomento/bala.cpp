#include "bala.h"
#include "qgraphicsscene.h"

Bala::Bala()
{
    setRect(0,0,15,15);         //crear la 'bala'
    tiempo = new QTimer();

    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(50);          //cada 50ms se moverá la bala



}


void Bala::desplazamiento()
{
    QList<QGraphicsItem *> colisiones = collidingItems();        //lista de punteros a otros QGraphicsItems con los que se está colisionando

    for(int i = 0, n = colisiones.size(); i < n; i++){
        if(typeid(*(colisiones[i]))== typeid(Enemigo)){
            scene()->removeItem(colisiones[i]);
            scene()->removeItem(this);
            delete colisiones[i];
            delete this;
            return;
        }
    }




    setPos(x(),y()-10);             //Mover bala hacia arriba
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
}






Bala::~Bala()
{
    delete tiempo;
}
