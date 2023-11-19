#include "enemigo.h"
#include "qgraphicsscene.h"






Enemigo::Enemigo()
{
    setRect(0,0,30,30);



    QTimer * tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(500);          //cada 500ms se moverá la bala



}



void Enemigo::desplazamiento()
{
    bool bandera = true;


    QList<QGraphicsItem *> colisiones = collidingItems(Qt::IntersectsItemBoundingRect);
    for(int i = 0, n = colisiones.size(); i < n; i++){
        if(typeid(*(colisiones[i])) == typeid(Obstaculo)){
            bandera = false;
        }
    }


    int i = rand() % 4;
    switch(i){
    case 0:
        if (y()>0 && bandera == true)
            setPos(x(), y() - 30);
        else if (bandera == true) setPos(x(), y() + 30);
        break;
    case 1:
        if (pos().y() < scene()->height() - 30 && bandera == true)
            setPos(x(), y() + 30);
        else if (bandera == true) setPos(x(), y() - 30);
        break;
    case 2:
        if (x()>0 && bandera == true)
            setPos(x()- 30, y());
        else if (bandera == true) setPos(x() + 30, y());
        break;
    case 3:
        if (pos().x() < scene()->width() - 30 && bandera == true)
            setPos(x()+ 30, y() );
        else if (bandera == true) setPos(x()- 30, y() );
        break;
    default:
        break;

    }
    bandera = true;
    //setPos(X,Y);

}






