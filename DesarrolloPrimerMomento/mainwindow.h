#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "MiCaracter.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>           //reloj para dar movimiento automático
#include <QObject>
#include "enemigo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void aparecer();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    MiCaracter *jugador;
    QGraphicsView *vista;
    QTimer *tiempo;


};
#endif // MAINWINDOW_H
