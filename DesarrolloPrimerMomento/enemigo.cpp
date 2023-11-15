#include "enemigo.h"
#include "qgraphicsscene.h"



Enemigo::Enemigo(int x, int y)
{
    setRect(0,0,15,15);         //crear la 'Enemigo'
    setPos(x,y);


    tiempo = new QTimer();

    //connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(50);          //cada 50ms se moverá la bala



}


void Enemigo::desplazamiento()
{
    setPos(x(),y()+5);             //Mover bala hacia arriba
    if (pos().y() + rect().height() > 600){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
}






Enemigo::~Enemigo()
{
    delete tiempo;
}
