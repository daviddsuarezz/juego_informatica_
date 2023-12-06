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
#include <QString>
#include <QTime>
#include <QMessageBox>
#include "portal.h"
#include "power.h"
#include "GamerOverDialog.h"


Game::Game(int uno, int dos, QWidget *parent){

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,800,600);




    bandera = true;
    setScene(scene);


    radio_ = uno;
    amplitud_ = dos;




}

void Game::changePower()
{
    scene->removeItem(power);
    delete power;
    power = new Power(amplitud_,5,0.03);
    scene->addItem(power);
}




void Game::start()
{



    scene->clear();
    bandera = true;
    QImage image(":/images/bg.png");
    QImage scaledImage = image.scaled(1100, 800, Qt::KeepAspectRatio);
    setBackgroundBrush(QBrush(scaledImage));
    player = new Player;
    player->setPos(400,500);
    //construccion de la recta enfocada
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    //añadimos el jugador a la escena
    scene ->addItem(player);

    player->setFocus();



    //creaccion vida
    health = new Health();
    scene->addItem(health);

    score = new Score();
    scene->addItem(score);

    // creacion de enemigos

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player,SLOT(spawn()));
    timer->start(4000); //cada 2000 milisegunndos
    timers.append(timer);
    //declaracion objeto torre

    clockTimer = new QTimer(this);
    time = new QTime(0, 0);
    timers.append(clockTimer);


    timerText = new QGraphicsTextItem();
    timerText->setDefaultTextColor(Qt::white);
    timerText->setPos(750, 0);  // Ajusta la posición del temporizador
    scene->addItem(timerText);
    // Iniciar el temporizador
    connect(clockTimer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    clockTimer->start(1000);  // Actualizar el temporizador cada segundo

}

void Game::Gameover(bool win ){
    QTime* timeCopy = new QTime(*time);
    scene->removeItem(score);
    scene->removeItem(timerText);
    scene->removeItem(health);
    // ...

    // Eliminar los objetos
    delete score;
    delete timerText;
    delete clockTimer;
    delete time;
    delete health;

    if (win == true) {

        // create the title text
        QGraphicsTextItem* titleTexts = new QGraphicsTextItem(QString("You Win"));
        QFont titleFont("comic sans",50);
        titleTexts->setFont(titleFont);
        titleTexts->setDefaultTextColor(Qt::white);
        int txPos = this->width()/2 - titleTexts->boundingRect().width()/2;
        int tyPos = 100;
        titleTexts->setPos(txPos,tyPos);
        scene->addItem(titleTexts);

        QGraphicsTextItem* titleTexttime = new QGraphicsTextItem(QString("Time:"));
        QFont titleFont2("comic sans",25);
        titleTexttime->setFont(titleFont2);
        int txPos2 = this->width()/2 - titleTexttime->boundingRect().width()/2;
        int tyPos2 = 220;
        titleTexttime->setPos(txPos2,tyPos2);
        scene->addItem(titleTexttime);

        // Agregar el tiempo
        QGraphicsTextItem* timeText = new QGraphicsTextItem(QString(timeCopy->toString("mm:ss")));
        QFont timeFont3("comic sans",16);
        timeText->setFont(timeFont3);
        timeText->setDefaultTextColor(Qt::red);
        int timeXPos = this->width()/2 - timeText->boundingRect().width()/2;
        int timeYPos = 275;
        timeText->setPos(timeXPos,timeYPos);
        scene->addItem(timeText);

        // create the play button
        Button* playButton = new Button(QString("Reinciar"));
        int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
        int byPos = 350;
        playButton->setPos(bxPos,byPos);
        connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
        scene->addItem(playButton);

        // create the quit button
        Button* quitButton = new Button(QString("Quit"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 425;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
        delete timeCopy;

    } else {

        // create the title text
        QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Game Over"));
        QFont titleFont("comic sans",50);
        titleText->setFont(titleFont);
        int txPos = this->width()/2 - titleText->boundingRect().width()/2;
        int tyPos = 150;
        titleText->setPos(txPos,tyPos);
        scene->addItem(titleText);

        // create the play button
        Button* playButton = new Button(QString("Reiniciar"));
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


}

void Game::updateTimer()
{
    *time = time->addSecs(1);
    timerText->setPlainText(time->toString("mm:ss"));

    if (time->minute() == 0 && time->second() == 20) {
        // Agregar la torre a la escena después de 30 segundos
        // Crear el texto del Boss
        QGraphicsTextItem* bossText = new QGraphicsTextItem(QString("Boss"));
        QFont bossFont("times", 30);
        bossText->setDefaultTextColor(Qt::red);
        bossText->setFont(bossFont);
        int bxPos = scene->width() / 2 - bossText->boundingRect().width() / 2;
        int byPos =  scene->height() / 2 - bossText->boundingRect().height() ;
        bossText->setPos(bxPos,byPos);
        scene->addItem(bossText);

        // Crear un QTimer para eliminar el texto después de 2 segundos
        QTimer::singleShot(1000, [=] {
            scene->removeItem(bossText);
            delete bossText;
        });



        Tower *tower = new Tower(player);
        tower->setPos(300,10);
        scene->addItem(tower);


    }else if(time->minute() == 0 && time->second() == 35) {
        portal = new Portal;
        portal->setPos(50,150);
        scene->addItem(portal);
    }
    else if(time->minute() == 0 && time->second() == 50) {
        scene->removeItem(portal);
        delete portal;
        power = new Power;
        scene->addItem(power);

    }
    else if(time->minute() == 1 && time->second() == 5) {
        changePower();
    }
    else if (time->minute() == 1 && time->second() == 30){
        scene->removeItem(power);
        delete power;
        power = new Power;
        scene->addItem(power);
        portal = new Portal;
        portal->setPos(50,150);
        scene->addItem(portal);
    }

}
