#include "MiCaracter.h"
#include "qgraphicsscene.h"



MiCaracter::MiCaracter(QList<QGraphicsItem *> *items_)
{
    setRect(0,0,29,29);     //x, y, ancho y alto
    setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));
    items = items_;
    balaOpc = 0;
    distancia = 30;
}



void MiCaracter::keyPressEvent(QKeyEvent *event)
{



    if (event->key() == Qt::Key_A){
        if (x()>0){
        tryMove(-distancia, 0);
        }
    }
    else if (event->key() == Qt::Key_D){
        if (pos().x() < scene()->width() - 30){
            tryMove(distancia, 0);
        }
    }
    else if (event->key() == Qt::Key_S){
        if (pos().y() < scene()->height() - 30){
            tryMove(0, distancia);
        }
    }
    else if (event->key() == Qt::Key_W){
        if (y()>0)
        {
            tryMove(0, -distancia);
        }
    }



    else if (event->key()== Qt::Key_Right){
        if(balaOpc == 0){
            Bala * bala = new Bala();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioX(10);
            scene()->addItem(bala);
        }
        else{
            BalaEsp * bala = new BalaEsp();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioX(10);
            scene()->addItem(bala);
        }
    }
    else if (event->key() == Qt::Key_Left){
        if(balaOpc == 0){
            Bala * bala = new Bala();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioX(-10);
            scene()->addItem(bala);
        }
        else{
            BalaEsp * bala = new BalaEsp();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioX(-10);
            scene()->addItem(bala);
        }
    }
    else if (event->key() == Qt::Key_Up){
        if(balaOpc == 0){
            Bala * bala = new Bala();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioY(-10);
            scene()->addItem(bala);
        }
        else{
            BalaEsp * bala = new BalaEsp();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioY(-10);
            scene()->addItem(bala);
        }

    }
    else if (event->key() == Qt::Key_Down){
        if(balaOpc == 0){
            Bala * bala = new Bala();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioY(10);
            scene()->addItem(bala);
        }
        else{
            BalaEsp * bala = new BalaEsp();           //Generar el disparo
            bala->setPos(x(),y());
            bala->setCambioY(10);
            scene()->addItem(bala);
        }
    }
    else if (event->key() == Qt::Key_R){
        balaOpc = (balaOpc == 0)? 1 : 0;
    }
}







