#include "portal.h"
#include "Game.h"

extern Game *game;
Portal::Portal(QObject *parent):QObject(parent)
{
    pixmap = new QPixmap(":/images/portal.png");
    col = 0;
    w = 203;
    h = 150;
    speed = 40;
    give = -3;

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualize()));
    timer->start(350);
    timerS = new QTimer();
    connect(timerS,SIGNAL(timeout()),this,SLOT(shoot()));
    timerS->start(2000);
     game->timers.append(timer);
     game->timers.append(timerS);
}

Portal::~Portal()
{
    delete pixmap;
    delete timerS;
    delete timer;
}

QRectF Portal::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Portal::actualize()
{
    col += w;
    if(col >= 1200){
        col = 0;
    }

    this->update(-w/2,-h/2,w,h);
}

void Portal::shoot()
{
    bullet = new CanonBullet(speed,50,450);
    scene()->addItem(bullet);
    speed += give;
    if(speed > 70){
        scene()->removeItem(this);
        delete this;
    }
    if(speed < 0){
        give = 5;
        speed = 30;
    }
}
