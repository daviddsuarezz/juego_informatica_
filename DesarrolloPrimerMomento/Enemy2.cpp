#include "Enemy2.h"
#include <QDebug>
#include "Game2.h"
extern Game2 * game;

Enemy2::Enemy2(int posx,QObject *parent):QObject(parent)
{
    pixmap = new QPixmap(":/images/spider.png");

    col=0;
    w = 62.2;
    h = 43;

    setPos(posx,game->playerPos()-1150);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(100);

    timerM = new QTimer();
    connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
    timerM->start(50);

    health = 1;
}

Enemy2::~Enemy2()
{
    delete timerM;
    delete pixmap;
    delete timer;
}

QRectF Enemy2::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Enemy2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Enemy2::actualize()
{
    col += 62.2;
    if(col >= 622){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
}

void Enemy2::Move()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i))==typeid (Bullet)){
                 game->scene->removeItem(this);
                delete i;
                health --;
                if(health == 0){
                    //menu->level1->playerScore(2);
                    game->scene->removeItem(this);
                    delete this;
                    return;
                }
            }
        }
    }

    setPos(x(),y()+5);

    if(pos().y() > game->playerPos()+100){
        game->scene->removeItem(this);
        delete this;
        qDebug() << "Enemigo eliminado";
    }

}

