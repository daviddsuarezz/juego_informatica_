#ifndef ESCENAINICIAL_H
#define ESCENAINICIAL_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "Button.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>


class EscenaInicial: public QGraphicsView
{
public:
    EscenaInicial(QWidget * parent=0);
    void displayMainMenu();
    QGraphicsScene *scene;
};



#endif // ESCENAINICIAL_H
