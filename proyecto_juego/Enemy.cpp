#include <QTimer>
#include "Enemy.h"
#include <QList>
#include <QGraphicsScene>
#include <stdlib.h> // random
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(){
    //poner una posicion random
    int random_number = rand() % 601 + 100;
    setPos(random_number, 0);


     // definicion del enemigo
    QPixmap pixmap(":/images/enemy.png");
    pixmap = pixmap.scaled(80, 80);
    setPixmap(pixmap);

    //conexion
    //creamos un temporizador
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(move())); // concedtamos el temporizador con el objeto bala y el slot de movimiento

    timer->start(50); // cada 50 milisengundos se emitirá la funcion para crear la bala, cada objeto bala tiene su propio timer
    game->timers.append(timer);
}

void Enemy::move()
{

    //movimiento de los enemigos
    setPos(x(),y()+10);
    //eliminar la bala cuado sale de la pantalla
    if(pos().y()< 0 ){
        scene()->removeItem(this);
        delete this;
    }
    else if(pos().y() > 600){
        //bajar vida si el enemigo sale de la pantalla
        if(game->health->getHealth() > 0 && game->bandera == true ){
        game->health->decrease();
        }
        scene()->removeItem(this);
        delete this;

    }
}
