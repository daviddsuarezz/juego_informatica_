#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
// sera la clase del objeto para que detectre el mocimiento de por el teclasdo

class Player :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT //MACRO
public:
    Player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
    QPointF getPosition();
public slots: //poder recibir señales de tiempo
    void spawn();
private:
    QMediaPlayer * bulletsound;
};




#endif // PLAYER_H
