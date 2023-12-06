#include "enemigo.h"


#include "balaenem.h"



Enemigo::Enemigo(QList<QGraphicsItem *> _items, int * vida)
{
    vidas = vida;
    items = _items;
    distancia = 30;
    disparo = 10;
    QGraphicsEllipseItem ::setRect(0,0,29,29);


    tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover
    tiempo->start((3 + rand() % 3)*100);

    tiempoDisparo = new QTimer(this);
    connect(tiempoDisparo, SIGNAL(timeout()),this, SLOT(disparar()));
    tiempoDisparo->start(700);



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

    int direccionX = rand() % 2;
    BalaEnem * bala1 = new BalaEnem(vidas),* bala2 = new BalaEnem(vidas);
    bala1->setPos(x(),y());
    bala2->setPos(x(),y());
    if(direccionX == 0){
        bala1->setCambioY(disparo);bala2->setCambioY(-disparo);
        scene()->addItem(bala1);scene()->addItem(bala2);
    }
    else{
        bala1->setCambioX(disparo);bala2->setCambioX(-disparo);
        scene()->addItem(bala1);scene()->addItem(bala2);
    }
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



