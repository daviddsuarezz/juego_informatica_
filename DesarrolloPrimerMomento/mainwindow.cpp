#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);      //Configurar la escena

    escena  =  new QGraphicsScene();    //Definir Escena para montar la "obra"

    //escena->setForegroundBrush(QBrush(Qt::blue,Qt::Dense2Pattern));       //Set fondo



    jugador = new MiCaracter();            //crear objeto
    jugador->setFlag(QGraphicsItem::ItemIsFocusable);        //Habilito la posibilidad de enfocar el objeto para generar KeyPressEvent
    jugador->setFocus();         //enfoco el KeyPressEvent en el objeto


    jugador->setRect(0,0,15,15);     //x, y, ancho y alto

    jugador->setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));


    escena->addItem(jugador);


    vista = new QGraphicsView();        //decirle a quién mirar, en un punto puede mirar una escena y en otro punto puede mirar otra escena



    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setScene(escena);
    vista->show();              //mostrar la vista
    vista->setFixedSize(1050,650);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,0,1050,650);             //tamaño de la escena desde el origen de la vista, tamaño
    escena->setBackgroundBrush(QBrush(QImage(":/Imagenes/Laberinto Fondo.png")));
    Enemigo * enemigo = new Enemigo(20,10);
    escena->addItem(enemigo);



    QTimer * time = new QTimer();
    connect(time,SIGNAL(timeout()),this,SLOT(aparecerEnemigos()));
    time->start(2000);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moverObjeto()
{
    static int contador = 0;
    jugador->setPos(10+contador, 10);        //mover elipse (únicamente en x en este caso)
    contador += 5;
}


void MainWindow::aparecerEnemigos()
{
    Enemigo * enemigo = new Enemigo(20,10);
    escena->addItem(enemigo);
}
