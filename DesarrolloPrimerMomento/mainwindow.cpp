#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QSet>

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

    //escena->setForegroundBrush(QBrush(Qt::blue,Qt::Dense2Pattern));       //Set fondo



    jugador = new MiCaracter();            //crear objeto
    jugador->setFlag(QGraphicsItem::ItemIsFocusable);        //Habilito la posibilidad de enfocar el objeto para generar KeyPressEvent
    jugador->setFocus();         //enfoco el KeyPressEvent en el objeto
    jugador->setRect(0,0,30,30);     //x, y, ancho y alto
    jugador->setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));
    escena->addItem(jugador);


    vista = new QGraphicsView();        //decirle a quién mirar, en un punto puede mirar una escena y en otro punto puede mirar otra escena
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setScene(escena);        //Decir a quién mirar
    vista->setFixedSize(1050,650);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,0,1050,650);             //tamaño de la escena desde el origen de la vista, tamaño

    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    const int numRectangles = 5;
    QSet<QGraphicsItem *> items;

    for (int i = 0; i < numRectangles; ++i) {
        int ancho = 100 + rand() % 100;
        int alto = 150 + rand() % 50;
        QGraphicsRectItem *rect = nullptr;
        do {
            int x = rand() % 1050-ancho;
            int y = rand() % 650-alto;

            rect = new QGraphicsRectItem(x, y, ancho, alto);
        }while (collidesWithOthers(rect, items));
        rect->setBrush(Qt::red);
        escena->addItem(rect);
        items.insert(rect);

    }




/*
    QTimer * tiemp = new QTimer();
    QObject::connect(tiemp,SIGNAL(timeout()), this, SLOT(aparecerEnemigos()));
    tiemp->start(2000);
*/
    vista->show();



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
    Enemigo * enemigo = new Enemigo();
    escena->addItem(enemigo);
}
