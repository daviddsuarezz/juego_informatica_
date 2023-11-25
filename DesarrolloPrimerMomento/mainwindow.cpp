#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QDebug>



bool colisiona(QGraphicsItem *item, const QList<QGraphicsItem *> *items) {
    foreach (QGraphicsItem *other, *items) {
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






    jugador = new MiCaracter();            //crear objeto

    jugador->setFlag(QGraphicsItem::ItemIsFocusable);        //Habilito la posibilidad de enfocar el objeto para generar KeyPressEvent
    jugador->setFocus();         //enfoco el KeyPressEvent en el objeto
    jugador->setRect(0,0,29,29);     //x, y, ancho y alto
    jugador->setBrush(QBrush(QImage(":/Imagenes/MortyIzq.png")));
    escena->addItem(jugador);


    vista = new QGraphicsView();        //decirle a quién mirar, en un punto puede mirar una escena y en otro punto puede mirar otra escena
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setScene(escena);        //Decir a quién mirar
    vista->setFixedSize(1050,750);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,0,1050,750);             //tamaño de la escena desde el origen de la vista, tamaño





    QTime time = QTime::currentTime();
    srand((uint)time.msec());
    const int tamañoCuadricula = 25; // Tamaño de la cuadrícula     Forma vertical, capacidad de 25 bloques
    const int tamañoBloque = 30; // Tamaño de cada celda

    // Genera el obstáculos
    for (int i = 0; i < tamañoCuadricula; ++i) {
        for (int j = 0; j < (tamañoCuadricula + 10); ++j) {     //tamaño de forma horizontal (35 bloques)
            // Genera un obstáculo con cierta probabilidad
            if(rand() % 4 == 0 ){
                Obstaculo *obstaculo = new Obstaculo();
                obstaculo->setPos(j * tamañoBloque, i * tamañoBloque);
                obstaculo->setBrush(QBrush("#214F92"));     //set fondo de obstaculo
                obstaculo->setPen(QPen(Qt::lightGray));     //set contorno de obstaculo
                escena->addItem(obstaculo);
                items.push_back(obstaculo);

            }
        }
    }
    crearEnemigos();

    setMouseTracking(true);


    vista->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (QGraphicsItem *other, items){
        delete other;
    }
}



void MainWindow::crearEnemigos()
{
    Enemigo * enemigo1 = new Enemigo(items), * enemigo2 = new Enemigo(items),* enemigo3 = new Enemigo(items),* enemigo4 = new Enemigo(items),* enemigo5 = new Enemigo(items);           //Generar el disparo
    enemigos.push_back(enemigo1), enemigos.push_back(enemigo2), enemigos.push_back(enemigo3), enemigos.push_back(enemigo4), enemigos.push_back(enemigo5);

    foreach(QGraphicsRectItem * enemigo, enemigos){
        enemigo->setPos(x(),y());
        escena->addItem(enemigo);
        do{
            int x = rand() % 35;
            int y = rand() % 25;
            enemigo->setPos(x * 30, y * 30);
        }while(colisiona(enemigo, &items));
        enemigo->setBrush(QBrush(Qt::red));        //color a la figura     Código del color, estilo del color
        enemigo->setPen(QPen(Qt::black));
        escena->addItem(enemigo);
    }
}

void MainWindow::setCursor()
{
    if(!cursor){
        escena->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsRectItem();

}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    // Tomar la posición del clic


    Bala * bala = new Bala();
    bala->setPos(event->pos());
    escena->addItem(bala);

    QPointF mousePos = ui->graphicsView->mapToScene(event->pos());
}





