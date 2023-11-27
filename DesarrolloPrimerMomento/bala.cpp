#include "bala.h"
#include "qgraphicsscene.h"

Bala::Bala()
{
    setRect(0,0,15,15);         //crear la 'bala'
    setBrush(QBrush(QColor(238, 103, 9)));
    cambioX = 0;
    cambioY = 0;
    tiempo = new QTimer();


    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(25);          //cada 50ms se moverá la bala

}

void Bala::setCambioX(int cambio){
    cambioX = cambio;
}
void Bala::setCambioY(int cambio){
    cambioY = cambio;
}



void Bala::desplazamiento()
{

    QList<QGraphicsItem *> colisiones = collidingItems(Qt::IntersectsItemShape);        //lista de punteros a otros QGraphicsItems con los que se está colisionando

    for(int i = 0, n = colisiones.size(); i < n; i++){
        if(typeid(*(colisiones[i])) == typeid(Enemigo)){
            scene()->removeItem(colisiones[i]);
            scene()->removeItem(this);
            delete colisiones[i];
            delete this;
            return;
        }
        else if (typeid(*(colisiones[i])) == typeid(Obstaculo)){
            scene()->removeItem(this);
            delete this;
            return;
        }
    }setPos(x()+cambioX, y()+cambioY);


    if (y() < 0){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
    else if(x()<0){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
    else if(x() > scene()->width() - 15){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
    else if(y() > scene()->height() - 15){
        scene()->removeItem(this);              //referencia a una escena
        delete this;
    }
}





Bala::~Bala()
{
    delete tiempo;
}
