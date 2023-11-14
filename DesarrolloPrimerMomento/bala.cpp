#include "bala.h"

Bala::Bala()
{
    setRect(0,0,15,15);         //crear la 'bala'
    tiempo = new QTimer();

    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(50);          //cada 50ms se moverá la bala



}


void Bala::desplazamiento()
{
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
