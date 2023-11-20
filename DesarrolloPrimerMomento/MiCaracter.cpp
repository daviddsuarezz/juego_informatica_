#include "MiCaracter.h"
#include "qgraphicsscene.h"



void MiCaracter::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_A){
        if (x()>0)
            setPos(x()-30,y());      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() < scene()->width() - 30)
            setPos(x()+30,y());      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_S){
        if (pos().y() < scene()->height() - 30)
        setPos(x(),y()+30);      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_W){
        if (y()>0)
            setPos(x(),y()-30);      //Cantidad de distancia que me moveré
    }
    else if (event->key() == Qt::Key_Space){
        Bala * bala = new Bala();           //Generar el disparo
        bala->setPos(x(),y());
        scene()->addItem(bala);
    }
}







