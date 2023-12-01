#include "marcador.h"
#include "qfont.h"


Marcador::Marcador(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    marcador = 0;
    setPlainText(QString("Enemigos\nRestantes:\n") + QString::number(marcador));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 16));
}

void Marcador::aumentar()
{
    marcador++;
}

int Marcador::getMarcador()
{
    return marcador;
}
