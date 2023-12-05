#ifndef JUEGO_H
#define JUEGO_H

#include "Button.h"



#include "MiCaracter.h"
#include "enemigo.h"
#include "obstaculo.h"

#include <QGraphicsScene>

#include <QGraphicsView>
#include <QTimer>           //reloj para dar movimiento automático


#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>
#include <QImage>

#include <QTime>

#include <QWidget>


class Juego:public QGraphicsView
{
    Q_OBJECT
public:
    Juego(int uno, int dos, int tres,QGraphicsScene *scen, QWidget *parent = 0);
    ~Juego();
    void crearEnemigos(int cantEnem);
    void crearObstaculos();

public slots:
    void checkGameOver(); // Función para verificar el fin del juego.
    void aparecerJugado();
    void cambiarTexto();
    void reducirVidas();
    void actualizarTexto();

private slots:

    void verificarColision();
private:


    QGraphicsScene * escena;
    MiCaracter *jugador;
    QGraphicsView *vista;
    QList<QGraphicsItem *> items;
    int enemigosRestantes;
    int vidas;
    int Caracter;

    QGraphicsRectItem *emptyRect; // Rectángulo vacío
    QGraphicsTextItem *texto;

    QTimer *gameOverTimer;

    int uno, dos;
};

#endif // JUEGO_H
