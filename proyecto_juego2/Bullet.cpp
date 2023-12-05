
#include "Bullet.h"
#include <QPixmap>
#include <QTimer>
#include <QPixmap>
#include "Game.h"
#include <QDebug>

extern Game * game;

Bullet::Bullet()
{
    setPixmap(QPixmap(":/images/bullet.png").scaled(10,20));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

Bullet::~Bullet()
{
    delete timer;
}

void Bullet::move()
{
    //mover la bala hacia arriba
    setPos(x(),y()-7);
    //eliminar la bala
    if(pos().y() < game->playerPos()-720){
            scene()->removeItem(this);
            qDebug() << "Bala eliminada";
            delete this;
        }

}
