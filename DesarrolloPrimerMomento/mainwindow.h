#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include "Button.h"



#include "MiCaracter.h"
#include "enemigo.h"
#include "obstaculo.h"


#include <QMainWindow>
#include <QGraphicsScene>

#include <QGraphicsView>
#include <QTimer>           //reloj para dar movimiento automático


#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>
#include <QImage>

#include <QTime>

#include <QWidget>

#include <QGraphicsTextItem>

#include <QObject>

class juego : public QGraphicsView
{
    Q_OBJECT

public:
    juego(int uno, int dos, int tres,QGraphicsView *vist,QGraphicsScene *scen, QWidget *parent = 0);
    ~juego();
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
#endif // MAINWINDOW_H
