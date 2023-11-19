#include <QTimer>
#include "Enemy.h"
#include <QList>
#include <QGraphicsScene>
#include <stdlib.h> // random
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(){
    //poner una posicion random
    int random_number = rand() % 700;
    setPos(random_number, 0);


     // definicion del enemigo
    QPixmap pixmap(":/images/enemy.png");
    pixmap = pixmap.scaled(100, 120);
    setPixmap(pixmap);

    //conexion
    //creamos un temporizador
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(move())); // concedtamos el temporizador con el objeto bala y el slot de movimiento

    timer->start(50); // cada 50 milisengundos se emitirá la funcion para crear la bala, cada objeto bala tiene su propio timer

}

void Enemy::move()
{
    //movimiento de los enemigos
    setPos(x(),y()+5);
    //eliminar la bala cuado sale de la pantalla
    if(pos().y()< 0 ){
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().y() > 600){
        //bajar vida si el enemigo sale de la pantalla
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
