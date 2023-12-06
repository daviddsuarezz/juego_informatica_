#include "canonbullet.h"
#include "Player.h"
#include "Game.h"
#include "Health.h"
#include "Enemy.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include <fstream>
extern Game * game;

CanonBullet::CanonBullet(double Vo_,double Xo_,double Yo_)
{
    setPixmap(QPixmap(":/images/canonbullet.png").scaled(30, 30));

    angle = 45;
    g = 9.8;
    Vo = Vo_;
    Xo = Xo_;
    Yo = Yo_;
    posx = Xo;
    posy = game->scene->height() - Yo;
    time = 0;
    setPos(posx,posy);
    qDebug() << posx << ", " << posy;




    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Move()));
    timer->start(10);
    game->timers.append(timer);



}

CanonBullet::~CanonBullet()
{
    delete timer;
}

void CanonBullet::Move()
{
    time += 0.05;
    double Vx,Vy;
    qDebug() << time;
    Vx = Vo * cos(angle*3.14/180);
    Vy = Vo * sin(angle*3.14/180);
    posx = Xo + Vx * time;//En X funciona como un MRU
    posy = game->scene->height() - (Yo + Vy * time - (0.5*g*time*time));//En Y funciona como un MRUA
    qDebug() << (Yo + Vy * time - (0.5*g*time*time));
    qDebug() << posx << ", " << posy;
    setPos(posx,posy);
    if(posy > game->scene->height()){
        game->scene->removeItem(this);
        delete this;
        return;
    }

    QList<QGraphicsItem *> colliding_Items1 = scene()->collidingItems(this);
    foreach(QGraphicsItem *item, colliding_Items1) {
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

    QList<QGraphicsItem *> colliding_items = collidingItems(Qt::IntersectsItemShape); // lista de objetos graficos
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i]))== typeid(Enemy)){ //recorremos y comparamos la olision por medio de los id
            //incremento del score
            game->score->increase();

            //eliminacion en de los objetos de la colision
            scene()->removeItem(colliding_items[i]);//enemigo de la colision
            scene()->removeItem(this);//la bala de la colision
            //eliminacion de en la memoria
            delete colliding_items[i];
            delete this;
        }
    }

}
