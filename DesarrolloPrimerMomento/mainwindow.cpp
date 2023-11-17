#include "mainwindow.h"
#include "obstaculos.h"
#include "ui_mainwindow.h"



bool collidesWithOthers(QGraphicsItem *item, const QSet<QGraphicsItem *> &items) {
    foreach (QGraphicsItem *other, items) {
        if (item->collidesWithItem(other))
            return true;
    }
    return false;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);      //Configurar la escena

    escena  =  new QGraphicsScene();    //Definir Escena para montar la "obra"
    escena->setBackgroundBrush(QBrush("#DEC561"));       //Set fondo

    QSet<QGraphicsItem *> items;




    jugador = new MiCaracter();            //crear objeto

    jugador->setFlag(QGraphicsItem::ItemIsFocusable);        //Habilito la posibilidad de enfocar el objeto para generar KeyPressEvent
    jugador->setFocus();         //enfoco el KeyPressEvent en el objeto
    jugador->setRect(0,0,30,30);     //x, y, ancho y alto
    jugador->setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));
    escena->addItem(jugador);


    vista = new QGraphicsView();        //decirle a quién mirar, en un punto puede mirar una escena y en otro punto puede mirar otra escena
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setScene(escena);        //Decir a quién mirar
    vista->setFixedSize(1050,750);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,0,1050,750);             //tamaño de la escena desde el origen de la vista, tamaño

    Enemigo * enemigo = new Enemigo();
    escena->addItem(enemigo);

    Enemigo * enemigo1 = new Enemigo();
    escena->addItem(enemigo1);

    Enemigo * enemigo2 = new Enemigo();
    escena->addItem(enemigo2);

    Enemigo * enemigo3 = new Enemigo();
    escena->addItem(enemigo3);

    Enemigo * enemigo4 = new Enemigo();
    escena->addItem(enemigo4);




    Obstaculos * obstaculo = new Obstaculos(items) ;







    vista->show();



}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (QGraphicsItem *other, items){
        delete other;
    }
}

void MainWindow::moverObjeto()
{
    static int contador = 0;
    jugador->setPos(10+contador, 10);        //mover elipse (únicamente en x en este caso)
    contador += 5;
}


void MainWindow::aparecerEnemigos()
{
    Enemigo * enemigo1 = new Enemigo(),*enemigo2 = new Enemigo(),* enemigo3 = new Enemigo(), * enemigo4 = new Enemigo();
    items.insert(enemigo1),items.insert(enemigo2),items.insert(enemigo3),items.insert(enemigo4);

}
