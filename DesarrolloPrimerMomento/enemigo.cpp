#include "enemigo.h"
#include "qgraphicsscene.h"



Enemigo::Enemigo(): QObject(), QGraphicsRectItem()
{

    int x = rand() % 35;
    int y = rand() % 25;
    setPos(x * 30,y * 30);

    setRect(0,0,30,30);         //crear la 'Enemigo'

    setBrush(QBrush("#2E86C1"));        //color a la figura     Código del color, estilo del color
    setPen(QPen(Qt::black));
    QTimer * tiempo = new QTimer(this);
    connect(tiempo, SIGNAL(timeout()),this, SLOT(desplazamiento()));         //cada timeout tiempo, se va a a llamar mover

    tiempo->start(500);          //cada 500ms se moverá la bala



}



void Enemigo::desplazamiento()
{
    int i = rand() % 4;
    switch(i){
    case 0:
        if (y()>0)
        setPos(x(), y() - 30);
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
}







