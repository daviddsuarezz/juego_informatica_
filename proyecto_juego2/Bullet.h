#ifndef BULLET_H
#define BULLET_H


#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Bullet, Constructor por defecto de la clase bullet.h.
     */
    Bullet();
    /**
      * @brief ~Bullet, Destructor de la clase bullet.h.
      */
    ~Bullet();

public slots:
    /**
     * @brief move, mover la clase Bullet 5 pixeles hacia arriba
     * atraves de la instancia de la clase QGraphicsScene *Scene,
     si la clase Bullet sale de la escena visible es eliminada de la
     memoria.
     */
    void move();

protected:
    /**
     * @brief timer, se conecta con el metodo move de la clase bullet.h.
     */
    QTimer *timer;
};


#endif // BULLET_H
