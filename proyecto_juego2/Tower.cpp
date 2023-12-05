#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include <QtGui>
#include "bullet.h"
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "Enemy.h"


extern Game * game;


Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    // Cargar y escalar la imagen
    QPixmap pixmap(":/images/tower.png");
    pixmap = pixmap.scaled(200, 100);
    setPixmap(pixmap);

    // Crear el polígono con los puntos dados
    QPolygonF polygon;
    polygon << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
            << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    // Escalar los puntos del polígono
    int SCALE_FACTOR = 80; // Aumenta este valor para hacer el polígono más grande
    for(int i =0, n = polygon.size(); i < n; i++){
        polygon[i] *= SCALE_FACTOR;
    }

    // Crear el item del polígono
    attack_area = new QGraphicsPolygonItem(QPolygonF(polygon), this);

    // Calcular el centro de la imagen
    QPointF image_center = boundingRect().center();

    // Calcular el centro del polígono
    QPointF polygon_center = attack_area->boundingRect().center();

    // Calcular la distancia entre los centros
    QPointF diff = image_center - polygon_center;

    // Mover el polígono al mismo centro que la imagen
    attack_area->setPos(diff);
    //conectar el timer con el ataque
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(1000);

    // set attack_dest
    attack_dest = QPointF(200,0);
}

double Tower::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(), item->pos());
    return ln.length();
}

void Tower::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+25,y()+25);

    QLineF ln(QPointF(x()+25,y()+25),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::aquire_target(){
    //lista de objetos que chocan con el area de ataque
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems() ;


    has_target = false;

    double closest_dist = 300;
    QPointF closest_pt = QPointF(0,0);
    for (size_t i = 0, n = colliding_items.size(); i < n; i++) {
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if(enemy){
            double this_dist = distanceTo(colliding_items[i]);
            if(this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = colliding_items[i]->pos();
                has_target = true;
            }
        }
    }
    if (has_target){
        attack_dest = closest_pt;
        fire();
    }

}
