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
#include <QApplication>
#include <QProcess>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(char *argv[], QWidget *parent = 0);
    ~MainWindow();
    void crearEnemigos(int cantEnem);

public slots:
    void checkGameOver(); // Función para verificar el fin del juego.
    void aparecerJugador();
    void cambiarTexto();
    void reducirVidas();
    void actualizarTexto();

private slots:

    void verificarColision();
private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    MiCaracter *jugador;
    QGraphicsView *vista;
    QList<QGraphicsItem *> items;
    int enemigosRestantes;
    int vidas;
    int Caracter;

    QGraphicsRectItem *emptyRect; // Rectángulo vacío
    QGraphicsTextItem *texto;

    QTimer *cambioTimer;
    QTimer *timerAparecerJugador;
    QTimer *gameOverTimer;

    int uno, dos;
};
#endif // MAINWINDOW_H
