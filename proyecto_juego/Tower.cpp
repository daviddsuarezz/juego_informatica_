#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsItem>
#include <QtGui>
#include "BulletT.h"
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "Enemy.h"
#include "Player.h"


extern Game * game;


Tower::Tower(Player * player):QObject(), QGraphicsPixmapItem(), player(player)
{
    // Cargar y escalar la imagen
    QPixmap pixmap(":/images/tower.png");
    pixmap = pixmap.scaled(200, 100);
    setPixmap(pixmap);
    //conectar el timer con el ataque
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aquire_target()));
    timer->start(5000);
    attack_dest = QPointF(200,0);


    health = 5;  // Inicializar la vida de la torre

    // Inicializar la barra de vida
    healthBar = new QGraphicsRectItem(this);
    // Inicializar la barra de vida
    healthBar = new QGraphicsRectItem(300,2, 200, 7, this);  // Ajusta el   // Ajusta el tamaño y la posición de la barra de vida
    healthBar->setBrush(Qt::green);  // Color de la barra de vida
    healthBar->setPen(QPen(Qt::black));  // Color del borde de la barra de vida
     game->scene->addItem(healthBar);
}

double Tower::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(), item->pos());
    return ln.length();
}

void Tower::fire()
{
    BulletT * bullet = new BulletT();
    int towerCenterX = x() + 200 / 2;
    int towerCenterY = y() + 100 / 2;

    // Ajusta la posición inicial de la bala para que sea el centro de la torre
    bullet->setPos(towerCenterX - 50 / 2, towerCenterY - 50 / 2);

    QLineF ln(QPointF(x()+40,y()+40),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}


void Tower::aquire_target(){
    // No necesitas verificar si el jugador está en el área de ataque
    // Simplemente obtén la posición del jugador y úsala como destino del ataque
    int playerCenterX = player->x() + 200 / 2;
    int playerCenterY = player->y() + 100 / 2;

    // Ajusta el destino del ataque para que sea el centro de la posición del jugador
    attack_dest = QPointF(playerCenterX, playerCenterY);


    fire();
}
