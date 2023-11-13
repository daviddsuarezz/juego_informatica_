#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "elemento.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>           //reloj para dar movimiento automático


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
    void moverObjeto();             //evento por el timer


private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    MiElipse *elipse;
    QGraphicsView *vista;
    QTimer *tiempo;


};
#endif // MAINWINDOW_H
