#include "MiCaracter.h"
#include "qgraphicsscene.h"



MiCaracter::MiCaracter(QList<QGraphicsItem *> *items_)
{
    setRect(0,0,29,29);     //x, y, ancho y alto
    setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));
    items = items_;
}



void MiCaracter::keyPressEvent(QKeyEvent *event)
{
    int cambioX = 0, cambioY = 0;
    QGraphicsItem *itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
    if (event->key() == Qt::Key_A){
        if (x()>0){
            cambioX = -30;
            itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
            if(!itemEnPosicion){
                setPos(x()+cambioX,y()+ cambioY);
            }
        }
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() < scene()->width() - 30){
            cambioX = 30;
            itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
            if(!itemEnPosicion){
                setPos(x()+cambioX,y()+ cambioY);
            }
        }
    }
    else if (event->key() == Qt::Key_S){
        if (pos().y() < scene()->height() - 30){
            cambioY = 30;
            itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
            if(!itemEnPosicion){
                setPos(x()+cambioX,y()+ cambioY);
            }
        }
    }
    else if (event->key() == Qt::Key_W){
        if (y()>0)
        {
            cambioY = -30;
            itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
            if(!itemEnPosicion){
                setPos(x()+cambioX,y()+ cambioY);
            }
        }
    }
    else if (event->key()== Qt::Key_Right){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        bala->setCambioX(10);
        scene()->addItem(bala);
    }
    else if (event->key() == Qt::Key_Left){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        bala->setCambioX(-10);
        scene()->addItem(bala);
    }
    else if (event->key() == Qt::Key_Up){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        bala->setCambioY(-10);
        scene()->addItem(bala);
    }
    else if (event->key() == Qt::Key_Down){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        bala->setCambioY(10);
        scene()->addItem(bala);
    }
    else if (event->key() == Qt::Key_Space){
        BalaEsp * bala = new BalaEsp();           //Generar el disparo
        bala->setPos(x(),y());
        bala->setCambioY(-10);
        scene()->addItem(bala);
    }
}







