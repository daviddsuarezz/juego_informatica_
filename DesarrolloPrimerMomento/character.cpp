#include "character.h"
#include <QTimer>
#include <QPixmap>
#include <QDebug>
#include "obstacle.h"
#include "obstacle2.h"
#include "Game2.h"

extern Game2 * game;

Character::Character(bool boss,QObject *parent):QObject(parent)
{

       pixmap = new QPixmap(":/images/player.png");
        col=0;
        w = 100;
        h = 80;
        last = 110;

        health = 5;
        speed = 7.5;

        min = 210;
        max = 600;

        timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
        timer->start(250);

        timerM = new QTimer();
        connect(timerM,SIGNAL(timeout()),this,SLOT(Move()));
        timerM->start(20);

        timerMove = new QTimer();
        connect(timerMove,SIGNAL(timeout()),this,SLOT(Slow()));


    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(Shoot()));
    timerS->start(500);

}



Character::~Character()
{
    delete timer;
    delete timerS;
    delete timerM;

}

void Character::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A and x()>min){
        setPos(x()-speed-5,y());
    }
    else if(event->key() == Qt::Key_D and x()<max){
        setPos(x()+speed+5,y());
    }
}

QRectF Character::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}




double Character::getHealth() const
{
    return health;
}

void Character::stopMove()
{
    timerM->stop();
    timerS->stop();
}

void Character::continueMove()
{
    timerM->start();
    timerS->start();
}

void Character::actualize()
{
    col += w;
    if(col >= last){
        col = 0;
    }
    this->update(-w/2,-h/2,w,h);
}

void Character::Move()
{
    //colisiones
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i)) == typeid (Enemy2)){
                 game->scene->removeItem(i);
                delete i;
                health -= 1;
                if(health <= 0){
                    game->scene->removeItem(this);
                    delete this;

                    return;
                }
            }

            else if(typeid (*(i)) == typeid (EnemyBullet)){
                game->scene->removeItem(i);
                delete i;
                health -= 1;
                if(health <= 0){
                    game->scene->removeItem(this);
                    delete this;

                    return;
                }
            }

            else if(typeid (*(i)) == typeid (EnemyShoots)){
                game->scene->removeItem(i);
                delete i;
                health -= 1;

                if(health <= 0){
                   game->scene->removeItem(this);
                    delete this;
                    //poner volver al menu principal
                    return;
                }
            }
            if(typeid (*(i)) == typeid (Obstacle)){
                qDebug() << game->getObstacle();
                game->scene->removeItem(i);
                delete i;
                health -= 1;
                if(health <= 0){
                    game->scene->removeItem(this);
                    delete this;
                    return;
                }
            }

            else if(typeid (*(i)) == typeid (Obstacle2)){
                speed = 2;
                timerMove->start(30);
                timerS->stop();
            }
        }
    }
    //actualizar vida

    //menu->level1->playerHealth();

    //mover el auto
    setPos(x(),y()-speed);

    game->FocusPlayer();
    if(y() < 0){
        qDebug() << "final"; //final
    }
}


void Character::Shoot()
{
    Bullet *bullet = new Bullet();
    bullet->setPos(x(),y());
    scene()->addItem(bullet);
}


void Character::Slow()
{
    speed = 7.5;
    timerMove->stop();
    timerS->start(500);
}



void Character::End()
{
    //colisiones
    QList<QGraphicsItem *> collisions = collidingItems();
    for(QGraphicsItem *i : collisions){
        if(i->collidesWithItem(this)){
            if(typeid(*(i)) == typeid (EnemyBullet)){
                game->scene->removeItem(i);
                delete i;
                health -= 1;
                //menu->level1->playerHealth();
                if(health <= 0){
                    game->scene->removeItem(this);
                    delete this;
                    return;
                }
            }


        }
    }
}
