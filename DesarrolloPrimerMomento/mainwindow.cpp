#include "mainwindow.h"
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
    items.insert(jugador);
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

    Enemigo * enemigo = new Enemigo();
    escena->addItem(enemigo);
    items.insert(enemigo);



    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    const int numRectangles = 10;

    const int gridSize = 20; // Tamaño de la cuadrícula
    const int cellSize = 30; // Tamaño de cada celda

    // Genera el laberinto
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            // Genera un obstáculo con cierta probabilidad
            if (rand() % 5 == 0) {
                QGraphicsRectItem *obstacle = new QGraphicsRectItem(j * cellSize, i * cellSize, cellSize, cellSize);
                obstacle->setBrush(Qt::darkGray);
                escena->addItem(obstacle);
            }
        }
    }




/*
    for (int i = 0; i < numRectangles; ++i) {
        int ancho = 200;
        int alto = 60;
        QGraphicsRectItem *rect = nullptr;
        do {
            int x = rand() % 1050-ancho;
            int y = rand() % 650-alto;

            rect = new QGraphicsRectItem(x, y, ancho, alto);
        }while (collidesWithOthers(rect, items));
        rect->setBrush(QBrush("#214F92"));
        escena->addItem(rect);
        items.insert(rect);

    }
    for (int i = 0; i < numRectangles; ++i) {
        int ancho = 60;
        int alto = 200;
        QGraphicsRectItem *rect = nullptr;
        do {
            int x = rand() % 1050-ancho;
            int y = rand() % 650-alto;

            rect = new QGraphicsRectItem(x, y, ancho, alto);
        }while (collidesWithOthers(rect, items));
        rect->setBrush(QBrush("#214F92"));
        escena->addItem(rect);
        items.insert(rect);

    }


*/

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
