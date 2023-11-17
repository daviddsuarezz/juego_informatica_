#include "enemigo.h"
#include "qgraphicsscene.h"



Enemigo::Enemigo(): QObject(), QGraphicsRectItem()
{

    int x = rand() % 1011;
    int y = rand() % 609;
    setPos(x,y);

    setRect(0,0,40,40);         //crear la 'Enemigo'

    QBrush fondo("#2E86C1", Qt::SolidPattern);          //color a la figura     Código del color, estilo del color
    setBrush(fondo);

    QTimer * tiempo = new QTimer(this);

    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(50);          //cada 50ms se moverá la bala



}


void Enemigo::desplazamiento()
{
    setPos(x(),y()+5);             //Mover bala hacia arriba
    if (pos().y() + rect().height() > 609){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
}







