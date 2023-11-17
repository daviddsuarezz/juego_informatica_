#include "mainwindow.h"

#include "ui_mainwindow.h"






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





    QTime time = QTime::currentTime();
    srand((uint)time.msec());
    const int tamañoCuadricula = 25; // Tamaño de la cuadrícula     Forma vertical, capacidad de 25 bloques
    const int tamañoBloque = 30; // Tamaño de cada celda

    // Genera el obstáculos
    for (int i = 0; i < tamañoCuadricula; ++i) {
        for (int j = 0; j < (tamañoCuadricula + 10); ++j) {     //tamaño de forma horizontal (35 bloques)
            // Genera un obstáculo con cierta probabilidad
            if(rand() % 4 == 0 ){
                QGraphicsRectItem *obstaculo = new QGraphicsRectItem(j * tamañoBloque, i * tamañoBloque, tamañoBloque, tamañoBloque);
                obstaculo->setBrush(QBrush("#214F92"));     //set fondo de obstaculo
                obstaculo->setPen(QPen(Qt::lightGray));     //set contorno de obstaculo
                escena->addItem(obstaculo);
                items.insert(obstaculo);
            }
        }
    }

    Enemigo * enemigo = new Enemigo(&items);
    escena->addItem(enemigo);

    Enemigo * enemigo1 = new Enemigo(&items);
    escena->addItem(enemigo1);

    Enemigo * enemigo2 = new Enemigo(&items);
    escena->addItem(enemigo2);

    Enemigo * enemigo3 = new Enemigo(&items);
    escena->addItem(enemigo3);

    Enemigo * enemigo4 = new Enemigo(&items);
    escena->addItem(enemigo4);






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


void MainWindow::crearEnemigos()
{
    Enemigo * enemigo1 = new Enemigo(&items),*enemigo2 = new Enemigo(&items),* enemigo3 = new Enemigo(&items), * enemigo4 = new Enemigo(&items);


}
