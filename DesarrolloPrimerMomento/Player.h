#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QTimer>
// sera la clase del objeto para que detectre el mocimiento de por el teclasdo

class Player :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT //MACRO
public:
    Player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
    QPointF getPosition();
    void activateImmunity(int milliseconds);
    void setImmunity(bool value) { immune = value; }
    bool isImmune() const { return immune; }
public slots: //poder recibir señales de tiempo
    void spawn();
    void allowShooting();
    void endImmunity() {
        this->setImmunity(false);
        immunityTimer->stop();
    }
    // ...
private:
    QMediaPlayer * bulletsound;
    bool canShoot;
    QTimer *immunityTimer;
    bool immune;
};




#endif // PLAYER_H
