#include "enemigo.h"
#include "qgraphicsscene.h"






Enemigo::Enemigo()
{
    QGraphicsRectItem::setRect(0,0,30,30);



    QTimer * tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(500);          //cada 500ms se moverá la bala



}



void Enemigo::desplazamiento()
{

    int i = rand() % 4, cambioX = 0, cambioY = 0;
    switch(i){
    case 0:
        if (QRect::y()>0 )
            cambioY = -30;
            //setPos(x(), y() - 30);
        else cambioY = 30;
            //setPos(x(), y() + 30);
        break;
    case 1:
        if (QRect::y() < scene()->height() - 30 )
            cambioY = 30;
        //setPos(x(), y() + 30);
        else  cambioY = -30;//setPos(x(), y() - 30);
        break;
    case 2:
        if (QRect::x()>0 )
            cambioX = -30;
        //setPos(x()- 30, y());
        else  cambioX = 30;//setPos(x() + 30, y());
        break;
    case 3:
        if (QRect::x() < scene()->width() - 30 )
            cambioX = 30;//setPos(x()+ 30, y() );
        else cambioX = -30;//setPos(x()- 30, y() );
        break;
    default:
        break;
    }


    QList<QGraphicsItem *> colisiones = this->collidingItems();
    foreach(QGraphicsItem *colisona, colisiones){
            QRect enemigo ;
            if (!enemigo.translated(cambioX, cambioY).intersects(colisona->boundingRect().toRect())) {

        this->moveBy(cambioX, cambioY);
    }
    }



    /*
    QList<QGraphicsItem *> colisiones = this->collidingItems(Qt::ContainsItemBoundingRect);
    foreach(QGraphicsItem *colisona, colisiones){
        Obstaculo *obs = dynamic_cast<Obstaculo *>(colisona);
        if(obs){
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
        }
        }}

    for(int i = 0, n = colisiones.size(); i < n; i++){
        //if(typeid(*(colisiones[i])) == typeid(Obstaculo)){
        if(!(this->collidesWithItem(colisiones[i]), Qt::ContainsItemBoundingRect)){
            ;

            }}


*/
    //setPos(X,Y);

}






