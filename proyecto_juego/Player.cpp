#include "Player.h"
#include "Bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Enemy.h"

Player::Player(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    /*
    bulletsound = new QMediaPlayer();
    bulletsound->setSource(QUrl("qrc:/sounds/bullet.mp3"));
*/
    //visualizacion del enemigo
    QPixmap pixmap(":/images/player.png");
    pixmap = pixmap.scaled(200, 100);
    setPixmap(pixmap);

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

        Bullet *bullet = new Bullet();//para que aparezca la bala cuando le de a la tecla espaciadora
         bullet->setPos(x()+83, y());
        scene()->addItem(bullet); // bola agregada a la escena

    /*     //revisar lo de musica
         if (bulletsound->playbackState() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
         }
         else if (bulletsound->playbackState() == QMediaPlayer::StoppedState){
        bulletsound->play();
         }
*/
    }


}

void Player::spawn()
{
 //Creaacion  del enemigo
    Enemy * enemy = new Enemy;
    scene()->addItem(enemy);


}

QPointF Player::getPosition() {
    return pos();
}
