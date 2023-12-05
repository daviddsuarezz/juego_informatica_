#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include "character.h"
#include "obstacle.h"
#include "obstacle2.h"
#include "enemyshoots.h"
#include <QGraphicsScene>
#include <QObject>

class Game2:public QGraphicsView{
      Q_OBJECT
public:
    // member functions
    Game2();
    /*
    //void mousePressEvent(QMouseEvent *event);
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent *event);
    // member attributes
*/
    /*
    QGraphicsPixmapItem * cursor;
    void mousePressEvent(QMouseEvent *event);
*/

    /**
     * @brief FocusPlayer, enfocar a player.
     */
    void FocusPlayer();
    /**
     * @brief playerPos
     * @return retorna un double que es la posición en y() de player.
     */
    double playerPos();
    /**
     * @brief playerPosX
     * @return retorna un double que es la posición en x() de player.
     */
    double playerPosX();

     int getObstacle();


     /**
     * @brief Final, se pasa al jefe final, en esta parte se cambia de la vista
     cenital a la vista horizontal.
     */
     void Final(); //mirar esta funcion



    QGraphicsScene *scene;
    /**
     * @brief player, instacia de la clase Character.
     */
    Character *player;
    /**
     * @brief enemy, instacia de la clase Enemy.
     */
    Enemy2 *enemy;
    /**
     * @brief obs, instacia de la clase Obstacle.
     */
    Obstacle *obs;
    /**
     * @brief enemy2, instacia de la clase EnemyShoots.
     */
    EnemyShoots *enemy2;
    /**
     * @brief obs2, instacia de la clase Obstacle2.
     */
    Obstacle2 *obs2;
    /**
     * @brief bonus, instacia de la clase Bonus.
     */
     /**
    * @brief timerE, se utiliza para generar instancias de las clases
                        Enemy, EnemyShoots, Obstacle y Obstacle2.
                             */
    QTimer *timerE;
    /**
     * @brief posx, posicion en x donde se generan los enemigos y obstaculos de la clase level1.h.
     */
    int posx;

public slots:
    /**
     * @brief makeEnemies, genera una insancia de la clase Eemy.
     */
    void makeEnemies();
    /**
     * @brief makeObstacles, genera una instancia de la clase Obstacle.
     */
    void makeObstacles();
    /**
     * @brief makeEnemies2, genera una instancia de la clase EnemyShoots.
     */
    void makeEnemies2();
    /**
     * @brief makeObstacles2, genera una instancia de la clase Obstacle2.
     */
    void makeObstacles2();
};

#endif // GAME_H
