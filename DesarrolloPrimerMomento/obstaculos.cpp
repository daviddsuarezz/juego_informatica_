#include "obstaculos.h"
#include "qgraphicsscene.h"

Obstaculos::Obstaculos(QSet<QGraphicsItem *> items)
{
    QTime time = QTime::currentTime();
    srand((uint)time.msec());
    const int tamañoCuadricula = 25; // Tamaño de la cuadrícula     Forma vertical, capacidad de 25 bloques
    const int tamañoBloque = 30; // Tamaño de cada celda

    // Genera el obstáculos
    for (int i = 0; i < tamañoCuadricula; ++i) {
        for (int j = 0; j < (tamañoCuadricula + 10); ++j) {     //tamaño de forma horizontal (35 bloques)
            // Genera un obstáculo con cierta probabilidad
            if(rand() % 4 == 0 ){
                QGraphicsRectItem *obstaculo = new QGraphicsRectItem(j * tamañoBloque, i * tamañoBloque, tamañoBloque, tamañoBloque);
                obstaculo->setBrush(QBrush("#214F92"));     //set fondo de obstaculo
                obstaculo->setPen(QPen(Qt::lightGray));     //set contorno de obstaculo
                scene()->addItem(obstaculo);
                items.insert(obstaculo);
            }
        }
    }
}
