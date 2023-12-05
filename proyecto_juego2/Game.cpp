#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"
#include "Enemy.h"
#include <QTimer>

Game::Game()
{
    posx = 0;


    //view
   setFixedSize(800,600-20);


    //scene = new QGraphicsScene();
    //scene->setBackgroundBrush(QPixmap(":/images/level1.1.jpg"));

    scene = new QGraphicsScene();
    QPixmap background(":/images/level1.4.png");
    background = background.scaled(800, 600, Qt::IgnoreAspectRatio);

    scene->setBackgroundBrush(background);
    setScene(scene);
    setSceneRect(0,0,width(),10800);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    player = new Character(false);
    scene->addItem(player);
    player->setPos(400,10800);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //generar enemigos
    timerE = new QTimer();
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(2000);


}



void Game::FocusPlayer()
{
    centerOn(player->x(),player->y()-200);
}

double Game::playerPos()
{
    return player->y();
}

double Game::playerPosX()
{
    return player->x();
}

int Game::getObstacle()
{
    return obs->getType_obs();
}

void Game::makeEnemies()
{
    int random;
    do{
        random = 210 +rand() % (550-210);
    }while(abs(posx-random) < 80);
    posx = random;

    enemy = new Enemy(posx);
    scene->addItem(enemy);

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    timerE->start(2000);
}

void Game::makeObstacles()
{
    int random;
    do{
        random = 210 +rand() % (550-210);
    }while(abs(posx-random) < 80);
    posx = random;

    obs = new Obstacle(posx);
    scene->addItem(obs);

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies2()));
    timerE->start(2000);
}

void Game::makeEnemies2()
{
    int random;
    do{
        random = 210 +rand() % (550-210);
    }while(abs(posx-random) < 80);
    posx = random;

    enemy2 = new EnemyShoots(posx);
    scene->addItem(enemy2);
    timerE->stop();

    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    timerE->start(2000);
}

void Game::makeObstacles2()
{
    int random;
    do{
        random = 210 +rand() % (550-210);
    }while(abs(posx-random) < 80);
    posx = random;

    obs2 = new Obstacle2(posx);
    scene->addItem(obs2);

    timerE->stop();
    disconnect(timerE,SIGNAL(timeout()),this,SLOT(makeObstacles2()));
    connect(timerE,SIGNAL(timeout()),this,SLOT(makeEnemies()));
    timerE->start(2000);
}
