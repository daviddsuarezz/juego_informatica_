#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MiCaracter.h"
#include "enemigo.h"
#include "obstaculo.h"


#include <QMainWindow>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QTimer>           //reloj para dar movimiento automático


#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>
#include <QImage>

#include <QTime>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(char *argv[], QWidget *parent = nullptr);
    ~MainWindow();
    void crearEnemigos(int cantEnem);

public slots:
    void checkGameOver(); // Función para verificar el fin del juego.

private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    MiCaracter *jugador;
    QGraphicsView *vista;
    QList<QGraphicsItem *> items;
    int enemigosRestantes;

    QGraphicsRectItem *emptyRect; // Rectángulo vacío
    QList<QGraphicsRectItem*> enemies;
    //Marcador * score;


};
#endif // MAINWINDOW_H
