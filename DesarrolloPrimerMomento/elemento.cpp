#include "elemento.h"
#include "qgraphicsscene.h"




void MiCaracter::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        setPos(x()-10,y());      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_D){
        setPos(x()+10,y());      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_S){
        setPos(x(),y()+10);      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_W){
        setPos(x(),y()-10);      //Cantidad de distancia que me moveré
    }

    else if (event->key() == Qt::Key_Space){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        scene()->addItem(bala);
    }

}
