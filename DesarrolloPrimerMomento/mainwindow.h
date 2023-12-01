#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MiCaracter.h"
#include "enemigo.h"
#include "obstaculo.h"
#include "marcador.h"

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
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>


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
    /*
    void destruirEnemigo() {
        if (enemigosRestantes > 0) {
            enemigosRestantes--;
            labelEnemigos->setText("Enemigos restantes: " + QString::number(enemigosRestantes));
        }
    }*/



private:
    Ui::MainWindow *ui;
    QGraphicsRectItem * cursor;
    QGraphicsScene *escena;
    MiCaracter *jugador;
    QGraphicsView *vista;
    QList<QGraphicsItem *> items;
    QVBoxLayout *layout;
    QLabel *labelEnemigos;
    int enemigosRestantes;



    Marcador * score;


};
#endif // MAINWINDOW_H
