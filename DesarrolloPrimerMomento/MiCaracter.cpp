#include "MiCaracter.h"
#include "qgraphicsscene.h"



MiCaracter::MiCaracter(QList<QGraphicsItem *> *items_)
{
    setRect(0,0,29,29);     //x, y, ancho y alto
    setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));
    items = items_;
    balaOpc = 0;
    distancia = 30;
    disparoEsp = true;
    disparoNormal = true;
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
            if (disparoNormal){
                Bala * bala = new Bala();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioX(10);
                scene()->addItem(bala);


                disparoNormal = false;
                QTimer::singleShot(200, this, SLOT(permitirNormal()));
            }
        }
        else{
            if(disparoEsp){
                BalaEsp * bala = new BalaEsp();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioX(10);
                scene()->addItem(bala);

                disparoEsp = false;
                QTimer::singleShot(2000, this, SLOT(permitirEspecial()));
            }
        }
    }
    else if (event->key() == Qt::Key_Left){
        if(balaOpc == 0){
            if(disparoNormal){
                Bala * bala = new Bala();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioX(-10);
                scene()->addItem(bala);

                disparoNormal = false;
                QTimer::singleShot(200, this, SLOT(permitirNormal()));
            }
        }
        else{
            if(disparoEsp){
                BalaEsp * bala = new BalaEsp();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioX(-10);
                scene()->addItem(bala);

                disparoEsp = false;
                QTimer::singleShot(2000, this, SLOT(permitirEspecial()));
            }
        }
    }
    else if (event->key() == Qt::Key_Up){
        if(balaOpc == 0){
            if(disparoNormal){
                Bala * bala = new Bala();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioY(-10);
                scene()->addItem(bala);

                disparoNormal = false;
                QTimer::singleShot(200, this, SLOT(permitirNormal()));
            }
        }
        else{
            if(disparoEsp){
                BalaEsp * bala = new BalaEsp();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioY(-10);
                scene()->addItem(bala);

                disparoEsp = false;
                QTimer::singleShot(2000, this, SLOT(permitirEspecial()));
            }
        }
    }
    else if (event->key() == Qt::Key_Down){
        if(balaOpc == 0){
            if(disparoNormal){
                Bala * bala = new Bala();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioY(10);
                scene()->addItem(bala);

                disparoNormal = false;
                QTimer::singleShot(200, this, SLOT(permitirNormal()));
            }
        }
        else{
            if(disparoEsp){
                BalaEsp * bala = new BalaEsp();           //Generar el disparo
                bala->setPos(x(),y());
                bala->setCambioY(10);
                scene()->addItem(bala);

                disparoEsp = false;
                QTimer::singleShot(2000, this, SLOT(permitirEspecial()));
            }
        }
    }
    else if (event->key() == Qt::Key_R){
        balaOpc = (balaOpc == 0)? 1 : 0;
    }
}


void MiCaracter::tryMove(qreal dx, qreal dy)
{
        // Obtener la posición actual del personaje
        QPointF posicionActual = pos();

        // Calcular la posición futura
        QPointF posicionFutura = posicionActual + QPointF(dx, dy);

        // Verificar colisiones con obstáculos
        QList<QGraphicsItem*> colisiones = scene()->items(posicionFutura.x(), posicionFutura.y(), 1, 1, Qt::IntersectsItemBoundingRect, Qt::SortOrder(Qt::AscendingOrder));

        foreach (QGraphicsItem *item, colisiones) {
            if (typeid(*item) == typeid(Obstaculo)) {
                // Hay un obstáculo en la posición futura, no mover al personaje
                return;
            }
            else if(typeid(*item) == typeid(Enemigo)){
                return;
            }
        }

        // No hay obstáculos en la posición futura, mover al personaje
        setPos(posicionFutura);
}


void MiCaracter::permitirNormal()
{
        disparoNormal=true;
}
void MiCaracter::permitirEspecial()
{
        disparoEsp=true;
}





