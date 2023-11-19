#include <QTimer>
#include "Bullet.h"
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "Tower.h"


extern Game * game; // acceder de manera global

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
//dibujar la bala
    QPixmap pixmap(":/images/bullet.png");
    pixmap = pixmap.scaled(25, 25);
    setPixmap(pixmap);

//conexion
 //creamos un temporizador
 QTimer * timer = new QTimer(this);
 connect(timer,SIGNAL(timeout()), this, SLOT(move())); // concedtamos el temporizador con el objeto bala y el slot de movimiento

 timer->start(50); // cada 50 milisengundos se emitirá la funcion para crear la bala, cada objeto bala tiene su propio timer

}

void Bullet::move()
{
 //si la bala toca al enemy, este se destruye
 QList<QGraphicsItem *> colliding_items = collidingItems(); // lista de objetos graficos
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
     } else if (typeid(*(colliding_items[i])) == typeid(Tower)) {
         // La bala ha colisionado con una torre
         Tower *tower = dynamic_cast<Tower *>(colliding_items[i]);

         // Disminuye la vida de la torre
         tower->health--;

         // Actualiza la barra de vida de la torre
        tower->healthBar->setRect(300, 2, 200 * ((double)tower->health / 5), 7);
         game->scene->addItem(tower->healthBar);
         // Si la vida de la torre llega a cero, elimina la torre de la escena
         if (tower->health <= 0) {
            game->scene->removeItem(tower->healthBar);
            game->scene->removeItem(tower);
            delete tower->healthBar;
            delete tower;
         }

         // Elimina la bala de la escena
         game->scene->removeItem(this);
         delete this;
         return;
     }

 }


//movimiento de las balas
 setPos(x(),y()-10);
 //eliminar la bala cuado sale de la pantalla
 if(pos().y() < 0 ){
     scene()->removeItem(this);
     delete this;
 }
}

