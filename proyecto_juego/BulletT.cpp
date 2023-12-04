
#include "BulletT.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h> // qSin, qCos, qTan
#include "Game.h"
#include "Player.h"
#include "Health.h"

extern Game * game;

BulletT::BulletT(QGraphicsItem * parent) : QObject(),QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/images/bullet.png");
    pixmap = pixmap.scaled(50, 50);
    setPixmap(pixmap);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(100);
    game->timers.append(move_timer);

}


BulletT::BulletT(int n, QGraphicsItem * parent) : QObject(),QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/images/bullet_2.png");
    pixmap = pixmap.scaled(30, 30);
    setPixmap(pixmap);

    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(100);
    game->timers.append(move_timer);

}


void  BulletT::move(){
    int STEP_SIZE = 5;
    int theta = rotation(); // angulo

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);


    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach(QGraphicsItem *item, collidingItems) {
        Player *player = dynamic_cast<Player *>(item);
        if (player) {
            // La bala ha colisionado con el jugador

            // Disminuye la vida del jugador
            if(game->health->getHealth() > 0 && game->bandera == true ){
            game->health->decrease();
            }
            // Elimina la bala de la escena
            game->scene->removeItem(this);
            delete this;


            return;

        }
    }
    if(pos().y() > 600 ){
        scene()->removeItem(this);
        delete this;
    }



}
