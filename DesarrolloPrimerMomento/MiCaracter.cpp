#include "MiCaracter.h"
#include "qgraphicsscene.h"




void MiCaracter::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_A){
        if (x()>0)
            setPos(x()-10,y());      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_D){
        if (x()<1000)
            setPos(x()+10,y());      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_S){
        if (y()<600)
        setPos(x(),y()+10);      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_W){
        if (y()>0)
            setPos(x(),y()-10);      //Cantidad de distancia que me moveré
    }

    else if (event->key() == Qt::Key_Space){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        scene()->addItem(bala);
    }

}







