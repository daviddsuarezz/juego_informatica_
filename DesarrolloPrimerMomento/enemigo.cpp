#include "enemigo.h"

Enemigo::Enemigo()
{
    int xAleatoria = rand() % 1001;
    setPos(xAleatoria, 0);      //Aparición en posición aleatoria

    setRect(0,0,50,50);         //crear enemigo
    tiempo = new QTimer();

    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(50);



}


void Enemigo::desplazamiento()
{       //Mover Enemigo hacia abajo
    setPos(x(),y()+5);
    if (pos().y() + rect().height() > 601){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
}
