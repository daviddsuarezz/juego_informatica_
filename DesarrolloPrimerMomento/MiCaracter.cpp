#include "MiCaracter.h"
#include "qgraphicsscene.h"



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
        if (pos().x() < scene()->width() - 29){
            cambioX = 30;
            itemEnPosicion = scene()->itemAt(x()+cambioX,y()+ cambioY, QTransform());
            if(!itemEnPosicion){
                setPos(x()+cambioX,y()+ cambioY);
            }
        }
    }
    else if (event->key() == Qt::Key_S){
        if (pos().y() < scene()->height() - 29){
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

    /*else if (event->key() == Qt::Key_Space){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        scene()->addItem(bala);
    }*/
}







