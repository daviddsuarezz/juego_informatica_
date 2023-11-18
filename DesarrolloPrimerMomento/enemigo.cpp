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
    int X = 0, Y = 0;

    int i = rand() % 4;
    switch(i){
    case 0:
        if (y()>0)
            X = x() , Y = (y()- 30);
        else X = x(), Y = (y()+30);
        break;
    case 1:
        if (pos().y() < scene()->height() - 30)
            X = x(), Y = (y()+30);
        else X = x(), Y = (y()-30);
        break;
    case 2:
        if (x()>0)
            X = (x()- 30), Y = y();
        else X = (x()+ 30), Y = y();
        break;
    case 3:
        if (pos().x() < scene()->width() - 30)
            X = (x()+ 30), Y = y();
        else X = (x()- 30), Y = y();
        break;
    default:
        break;

    }
    QPointF direccion(30, 0); // Dirección hacia la derecha (puedes ajustar según tu caso)
    qreal velocidad = 30; // Ajusta la velocidad según tus necesidades
    QPointF newPos = pos() + direccion * velocidad;

    QList<QGraphicsItem*> itemsEnColision = collidingItems(mapToScene(newPos));

    foreach (QGraphicsItem* item, itemsEnColision) {
        if (dynamic_cast<Enemigo*>(item)) {
            // Hay un muro en la colisión, no te muevas
            return;
        }
    }
    setPos(X,Y);

}






