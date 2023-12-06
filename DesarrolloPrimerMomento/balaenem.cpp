#include "balaenem.h"
#include "obstaculo.h"




BalaEnem::BalaEnem(int *vida):Bala()
{
    setBrush(QBrush(QColor(250, 8, 8)));
    tiempo->start(50);
    vidas = vida;
}

void BalaEnem::desplazamiento()
{
    QList<QGraphicsItem *> colisiones = collidingItems(Qt::IntersectsItemShape);        //lista de punteros a otros QGraphicsItems con los que se está colisionando

    for(int i = 0, n = colisiones.size(); i < n; i++){
        if(typeid(*(colisiones[i])) == typeid(Obstaculo)){
            delete this;
            return;
        }
        else if(typeid(*(colisiones[i])) == typeid(MiCaracter)){
            (*vidas)--;
            scene()->removeItem(colisiones[i]);
            delete colisiones[i];
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

