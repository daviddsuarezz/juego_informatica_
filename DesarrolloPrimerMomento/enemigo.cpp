#include "enemigo.h"
#include "MiCaracter.h"
#include "qgraphicsscene.h"

#include <QDebug>





Enemigo::Enemigo(QList<QGraphicsItem *> _items)
{
    items = _items;
    distancia = 30;
    QGraphicsEllipseItem ::setRect(0,0,29,29);


    tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover
    tiempo->start((1 + rand() % 6)*100);

    tiempoDisparo = new QTimer(this);


}

Enemigo::~Enemigo()
{
    delete tiempo;
    delete tiempoDisparo;
}


void Enemigo::desplazamiento()
{
    int i = rand() % 4;
    switch(i){
    case 0:
        if (y()>0 )        //arriba
            tryMove(0, -distancia);
        else tryMove(0, distancia);
        break;
    case 1:
        if (y() < scene()->height() - 30 )
            tryMove(0, distancia);
        else tryMove(0, -distancia);
        break;
    case 2:
        if (x()>0 )
            tryMove(-distancia, 0);
        else tryMove(distancia, 0);
        break;
    case 3:
        if (x() < scene()->width() - 30 )
            tryMove(distancia, 0);
        else tryMove(-distancia, 0);
        break;
    default:
        break;
    }
}

void Enemigo::disparar()
{
    int direccion = rand() % 2;
    Bala * bala1 = new Bala(),* bala2 = new Bala();
    bala1->setPos(x(),y());
    bala2->setPos(x(),y());
}

void Enemigo::tryMove(qreal dx, qreal dy)
{
    // Obtener la posición actual del personaje
    QPointF posicionActual = pos();

    // Calcular la posición futura
    QPointF posicionFutura = posicionActual + QPointF(dx, dy);

    // Verificar colisiones con obstáculos
    QList<QGraphicsItem*> colisiones = scene()->items(posicionFutura.x(), posicionFutura.y(), 1, 1, Qt::IntersectsItemBoundingRect, Qt::SortOrder(Qt::AscendingOrder));

    foreach (QGraphicsItem *item, colisiones) {
        if (typeid(*item) == typeid(Obstaculo)) {
            // Hay un obstáculo en la posición futura, no mover al personaje
            return;
        }
        else if(typeid(*item) == typeid(Enemigo)){
            return;
        }
    }

    // No hay obstáculos en la posición futura, mover al personaje
    setPos(posicionFutura);
}







