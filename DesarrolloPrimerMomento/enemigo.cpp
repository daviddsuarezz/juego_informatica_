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
    QPointF newPos;
    int i = rand() % 4;
    switch(i){
    case 0:
        if (y()>0)
            newPos.setX(x()), newPos.setY(y()-30);
        else setPos(x(), y() + 30);
        break;
    case 1:
        if (pos().y() < scene()->height() - 30)
            setPos(x(), y() + 30);
        else setPos(x(), y() - 30);
        break;
    case 2:
        if (x()>0)
            setPos(x()- 30, y());
        else setPos(x() + 30, y());
        break;
    case 3:
        if (pos().x() < scene()->width() - 30)
            setPos(x()+ 30, y() );
        else setPos(x()- 30, y() );
        break;
    default:
        break;

    }

    QList<QGraphicsItem*> itemsEnColision = collidingItems(mapToScene());

    foreach (QGraphicsItem* item, itemsEnColision) {
        if (dynamic_cast<QGraphicsRectItem*>(item)) {
            // Hay un muro en la colisión, no te muevas
            return;
        }
    }

}






