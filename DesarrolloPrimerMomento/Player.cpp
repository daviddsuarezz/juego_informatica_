#include "Player.h"
#include "Bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Enemy.h"
#include <QTimer>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include "Game.h"
extern Game * game;

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), immune(false)
{


    //visualizacion del enemigo
    QPixmap pixmap(":/images/player.png");
    pixmap = pixmap.scaled(200, 100);
    setPixmap(pixmap);
    immunityTimer = new QTimer(this);
    connect(immunityTimer, SIGNAL(timeout()), this, SLOT(endImmunity()));
    game->timers.append(immunityTimer);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){//condicionales para que myrect se mueva almacenado en la varibale event
        if(pos().x() > 0){
            setPos(x()-10, y());

        }
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() + 170 < 800){ //modificar esto para hacerlo de una forma general
            setPos(x()+10, y());

        }
    }
    else if (event->key() == Qt::Key_Space){
        //creamos la bola

        if (canShoot) {
            //creamos la bola
            Bullet *bullet = new Bullet();//para que aparezca la bala cuando le de a la tecla espaciadora
            bullet->setPos(x()+83, y());
            scene()->addItem(bullet); // bola agregada a la escena
            ;


            // No permitir disparar de nuevo hasta después de un retraso
            canShoot = false;
            QTimer::singleShot(200, this, SLOT(allowShooting()));  // Permitir disparar de nuevo después de 1 segundo
        }


    }


}

void Player::activateImmunity(int milliseconds) {
    setImmunity(true);
    connect(immunityTimer, &QTimer::timeout, this, &Player::endImmunity);
    immunityTimer->start(milliseconds);
}

void Player::spawn()
{
    //Creaacion  del enemigo
    Enemy * enemy = new Enemy;
    scene()->addItem(enemy);


}

void Player::allowShooting()
{

    canShoot = true;

}

QPointF Player::getPosition() {
    return pos();
}
