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



    QList<QGraphicsItem *> colisiones = collidingItems(Qt::ContainsItemBoundingRect);
    for(int i = 0, n = colisiones.size(); i < n; i++){
        //if(typeid(*(colisiones[i])) == typeid(Obstaculo)){
        if(!(this->collidesWithItem(colisiones[i]), Qt::ContainsItemBoundingRect)){
            int i = rand() % 4;
            switch(i){
            case 0:
                if (y()>0 )
                    setPos(x(), y() - 30);
                else setPos(x(), y() + 30);
                break;
            case 1:
                if (pos().y() < scene()->height() - 30 )
                    setPos(x(), y() + 30);
                else  setPos(x(), y() - 30);
                break;
            case 2:
                if (x()>0 )
                    setPos(x()- 30, y());
                else  setPos(x() + 30, y());
                break;
            case 3:
                if (pos().x() < scene()->width() - 30 )
                    setPos(x()+ 30, y() );
                else setPos(x()- 30, y() );
                break;
            default:
                break;

            }}
        }


    //setPos(X,Y);

}






