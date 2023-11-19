#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QUrl>
#include <QBrush>
#include <QtWidgets>
#include <QtGui>
#include <QtCore>
#include "Button.h"
#include "Tower.h"



Game::Game(QWidget *parent){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,800,600);

    setScene(scene);


}

void Game::displayMainMenu()
{
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Rick and morty"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::start()
{
      scene->clear();


    QImage image(":/images/bg.png");
    QImage scaledImage = image.scaled(1100, 800, Qt::KeepAspectRatio);
    setBackgroundBrush(QBrush(scaledImage));
    player = new Player;
    player->setPos(400,500);
    //construccion de la recta enfocada
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //añadimos el jugador a la escena
    scene ->addItem(player);

    //Creacion del puntaje
    score = new Score();
    scene->addItem(score);
    //creaccion vida
    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);


    // creacion de enemigos

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player,SLOT(spawn()));
    timer->start(2000); //cada 2000milisegunndos

    //declaracion objeto torre


    //crear la torre
    Tower *tower = new Tower(player);
    tower->setPos(300,10);

    //añadir la torre a la escena

    scene->addItem(tower);


}
