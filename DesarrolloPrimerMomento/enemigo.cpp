#include "enemigo.h"
#include "qgraphicsscene.h"



Enemigo::Enemigo()
{
    unsigned seed = time(0);
    srand(seed);

    int randX = rand() % 1001;
    setPos(randX,0);

    setRect(0,0,50,50);         //crear la 'bala'
    tiempo = new QTimer();

    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(50);          //cada 50ms se moverá la bala



}


void Enemigo::desplazamiento()
{
    setPos(x(),y()+5);             //Mover bala hacia arriba
    if (pos().y() + rect().height() < 0){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
}






Enemigo::~Enemigo()
{
    delete tiempo;
}
