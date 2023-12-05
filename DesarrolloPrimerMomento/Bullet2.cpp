
#include "Bullet2.h"
#include <QPixmap>
#include <QTimer>
#include <QPixmap>
#include "Game2.h"
#include <QDebug>

extern Game2 * game;

Bullet2::Bullet2()
{
    setPixmap(QPixmap(":/images/bullet2.png").scaled(10,20));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(10);
}

Bullet2::~Bullet2()
{
    delete timer;
}

void Bullet2::move()
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
