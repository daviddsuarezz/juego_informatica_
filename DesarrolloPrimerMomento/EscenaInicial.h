#ifndef ESCENAINICIAL_H
#define ESCENAINICIAL_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "Button.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>


#include "mainwindow.h"

class EscenaInicial: public QGraphicsView
{
    Q_OBJECT
public:
    EscenaInicial(char *argv[], QWidget * parent=0);
    void displayMainMenu();
    QGraphicsScene *scene;
    QGraphicsView *vist;
    int uno,dos,tres;
public slots:
    void start();
};



#endif // ESCENAINICIAL_H
