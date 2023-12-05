#include "power.h"
#include <QList>
#include "Player.h"
#include "Health.h"
#include "Game.h"
#include <fstream>
extern Game * game;
Power::Power()
{
    setPixmap(QPixmap(":/images/metal.png"));
    radio = game->radio_;
    x = 300;
    y = 300;
    angle = 0;
    posx = x+(radio*cos(angle*3.14/180));
    posy = y-(radio*sin(angle*3.14/180));

    setPos(posx,posy);


    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Circular()));
    timer->start(17);
    game->timers.append(timer);
}

Power::Power(double amplitude_, double period_, double friction_)
{
    setPixmap(QPixmap(":/images/pendulum.png"));
    amplitude = amplitude_;
    period = period_;
    w = 2*M_PI/period;
    friction = friction_;
    time = 0;

    setPos(400,240);

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(MAS()));
    timer->start(20);
    game->timers.append(timer);
}

Power::~Power()
{
    delete timer;
}

void Power::Circular()
{
    angle ++;
    if(angle > 360) angle = 0;
    posx = x+(radio*cos(angle*3.14/180));
    posy = y-(radio*sin(angle*3.14/180));
    setPos(posx,posy);
    checkCollision();
}

void Power::MAS()
{
    time += 0.02;

    x = amplitude*exp(-friction*time)*cos(w*time);
    setRotation(x);
    checkCollision();
}
void Power::checkCollision()
{
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach(QGraphicsItem *item, collidingItems) {
        Player *player = dynamic_cast<Player *>(item);
        if (player && !player->isImmune()) {
            // El objeto Power ha colisionado con el jugador

            // Disminuye la vida del jugador
            if(game->health->getHealth() > 0 && game->bandera == true ){
                game->health->decrease();
            }
            // Activa la inmunidad del jugador durante 3 segundos
            player->activateImmunity(3000);

        }
    }
}
