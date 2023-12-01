#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QDebug>

#include <string>



#include <QGraphicsWidget>
#include <QGraphicsTextItem>

bool colisiona(QGraphicsItem *item, const QList<QGraphicsItem *> *items) {
    foreach (QGraphicsItem *other, *items) {
        if (item->collidesWithItem(other))
            return true;
    }
    return false;
}



MainWindow::MainWindow(char *argv[], QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);      //Configurar la escena

    escena  =  new QGraphicsScene();    //Definir Escena para montar la "obra"
    escena->setBackgroundBrush(QBrush("#DEC561"));       //Set fondo






    jugador = new MiCaracter(&items);            //cr|ear objeto

    jugador->setFlag(QGraphicsItem::ItemIsFocusable);        //Habilito la posibilidad de enfocar el objeto para generar KeyPressEvent
    jugador->setFocus();         //enfoco el KeyPressEvent en el objeto

    escena->addItem(jugador);

    //score = new Marcador;
    //escena->addItem(score);


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
    for (int vertical = 0; vertical < tamañoCuadricula; ++vertical) {
        for (int horizontal = 0; horizontal < (tamañoCuadricula + 10); ++horizontal) {     //tamaño de forma horizontal (35 bloques)
            // Genera un obstáculo con cierta probabilidad

            if((!((vertical == horizontal)&& ((vertical == 0)||(vertical == 1))))&&!(vertical == 0 && horizontal == 1)&&!(vertical == 1 && horizontal == 0)&&!(horizontal == 2 && (vertical == 0 || vertical == 1))){
                if(rand() % 4 == 0 ){
                    Obstaculo *obstaculo = new Obstaculo();
                    obstaculo->setPos(horizontal * tamañoBloque,vertical * tamañoBloque );
                    obstaculo->setBrush(QBrush("#214F92"));     //set fondo de obstaculo
                    obstaculo->setPen(QPen(Qt::lightGray));     //set contorno de obstaculo
                    escena->addItem(obstaculo);
                    items.push_back(obstaculo);
                }
            }
        }
    }

    if (isdigit(*argv[1])){
        crearEnemigos(std::stoi(argv[1]));
        enemigosRestantes = std::stoi(argv[1]);
    }

    else{
        crearEnemigos(8);
        enemigosRestantes = 8;
    }

    Marcador *marcador = new Marcador();
    marcador->setPos(100,100);
    escena->addItem(marcador);
    /*
    QGraphicsTextItem *textItem = new QGraphicsTextItem();

    textItem->setPlainText(QString("Enemigos\nRestantes:\n") + QString::number(enemigosRestantes));
    textItem->setDefaultTextColor(Qt::white);
    textItem->setFont(QFont("times", 16));

    textItem->setPos(100, 100); // Establece la posición del texto en la escena

    // Agrega el widget de texto a la escena
    escena->addItem(textItem);
*/
    vista->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    foreach (QGraphicsItem *other, items){
        delete other;
    }
}



void MainWindow::crearEnemigos(int cantEnem)
{
    for (int i = 0; i < cantEnem; i++){
        Enemigo * enemigo = new Enemigo(items);
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




