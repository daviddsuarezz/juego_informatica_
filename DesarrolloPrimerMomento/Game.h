#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include <QGraphicsTextItem>
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include "portal.h"
#include "power.h"
#include <QStackedWidget>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(int uno, int dos,QWidget * parent=0);
    QGraphicsScene * scene;
    Player * player;
    Portal * portal;
    Score * score;
    Health * health;
    Power *power;
    void displayMainMenu();
    QGraphicsTextItem * timerText;  // Temporizador
    QTimer * clockTimer;  // Temporizador para agregar la torre
    QTime * time;  // Tiempo transcurrido
    void changePower();
    int radio_;
    double amplitud_;
    int tower_healt;
    void Gameover(bool win);
    bool bandera = true;
    QList<QTimer*> timers;

public slots:
    void start();
    void updateTimer();

private:
    QStackedWidget* stackedWidget;



};
#endif // GAME_H
