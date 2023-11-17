#include "enemigo.h"
#include "qgraphicsscene.h"



Enemigo::Enemigo(): QObject(), QGraphicsRectItem()
{

    int x = rand() % 1019;
    int y = rand() % 719;
    setPos(x,y);

    setRect(0,0,30,30);         //crear la 'Enemigo'

    QBrush fondo("#2E86C1", Qt::SolidPattern);          //color a la figura     Código del color, estilo del color
    setBrush(fondo);

    QTimer * tiempo = new QTimer(this);

    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(500);          //cada 50ms se moverá la bala



}



void Enemigo::desplazamiento()
{
    int i = rand() % 4;
    switch(i){
    case 0:
        if (y()>0)
        setPos(x(), y() - 10);
        else setPos(x(), y() + 10);
        break;
    case 1:
        if (pos().y() < scene()->height() - 30)
        setPos(x(), y() + 10);
        else setPos(x(), y() - 10);
        break;
    case 2:
        if (x()>0)
        setPos(x()- 10, y());
        else setPos(x() + 10, y());
        break;
    case 3:
        if (pos().x() < scene()->width() - 30)
        setPos(x()+ 10, y() );
        else setPos(x()- 10, y() );
        break;
    default:
        break;

    }
}







