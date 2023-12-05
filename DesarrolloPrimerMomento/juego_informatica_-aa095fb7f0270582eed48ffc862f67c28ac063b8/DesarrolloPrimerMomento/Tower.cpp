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
    timer->start(3000);
    game->timers.append(timer);
    attack_dest = QPointF(200,0);

    fireTimer = new QTimer(this);
    connect(fireTimer, SIGNAL(timeout()), this, SLOT(fire2()));
    fireTimer->start(8000);


    health = 10;  // Inicializar la vida de la torre

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
void Tower::fire2()
{
    int n = 1;
    // Crea tres balas
    BulletT * bullet1 = new BulletT( n);
    BulletT * bullet2 = new BulletT( n);
    BulletT * bullet3 = new BulletT(n);

    int towerCenterX = x() + 200 / 2;
    int towerCenterY = y() + 100 / 2;

    // Ajusta la posición inicial de las balas para que sea el centro de la torre
    bullet1->setPos(towerCenterX - 50 / 2, towerCenterY - 50 / 2);
    bullet2->setPos(towerCenterX - 50 / 2, towerCenterY - 50 / 2);
    bullet3->setPos(towerCenterX - 50 / 2, towerCenterY - 50 / 2);

    // Configura los destinos de ataque para cada bala
    QPointF attack_dest1 = QPointF(game->scene->width() / 2, game->scene->height());
    QPointF attack_dest2 = QPointF(0, game->scene->height());
    QPointF attack_dest3 = QPointF(game->scene->width(), game->scene->height());

    // Configura el ángulo de cada bala para que se dirija a su destino de ataque
    QLineF ln1(QPointF(x()+40,y()+40), attack_dest1);
    QLineF ln2(QPointF(x()+40,y()+40), attack_dest2);
    QLineF ln3(QPointF(x()+40,y()+40), attack_dest3);
    int angle1 = -1 * ln1.angle();
    int angle2 = -1 * ln2.angle();
    int angle3 = -1 * ln3.angle();
    bullet1->setRotation(angle1);
    bullet2->setRotation(angle2);
    bullet3->setRotation(angle3);

    // Añade las balas a la escena
    game->scene->addItem(bullet1);
    game->scene->addItem(bullet2);
    game->scene->addItem(bullet3);
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
