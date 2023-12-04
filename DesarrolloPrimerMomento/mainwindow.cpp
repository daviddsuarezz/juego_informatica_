#include "mainwindow.h"

#include "ui_mainwindow.h"
#include <QDebug>

#include <string>

#include <QPen>

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
    enemigosRestantes = 0;
    escena  =  new QGraphicsScene(this);    //Definir Escena para montar la "obra"
    escena->setBackgroundBrush(QBrush("#DEC561"));       //Set fondo
    jugador = new MiCaracter(&items);            //cr|ear objeto
    Caracter = 1;
    vista = new QGraphicsView(escena);
    texto = new QGraphicsTextItem();
    vidas = 1;
    //globalVariable = 0;

    escena->addItem(jugador);






    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    vista->setFixedSize(1050,810);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,-15,1050,780);             //tamaño de la escena desde el origen de la vista, tamaño
    QGraphicsRectItem* rectang = new QGraphicsRectItem(0,-30,1050,29);
    rectang->setBrush(QBrush(Qt::black));
    escena->addItem(rectang);

    texto->setPlainText("Para moverte, usa 'A', 'W', 'S' y 'D'. Presiona 'R' para cambiar el modo de disparo. Utiliza las flechas para disparar.");
    texto->setFont(QFont("Arial",15));
    texto->setDefaultTextColor(QColor(149, 205, 198));
    texto->setPos(0,-30);
    escena->addItem(texto);

    QTimer *cambioTimer = new QTimer(this);
    connect(cambioTimer, SIGNAL(timeout()), this, SLOT(cambiarTexto()));
    cambioTimer->start(10000); // Cambiar el texto después de 10000 milisegundos (10 segundos)




    QTime time = QTime::currentTime();
    srand((uint)time.msec());
    const int tamañoCuadricula = 26; // Tamaño de la cuadrícula     Forma vertical, capacidad de 25 bloques
    const int tamañoBloque = 30; // Tamaño de cada celda

    // Genera el obstáculos
    for (int vertical = 0; vertical < tamañoCuadricula; ++vertical) {
        for (int horizontal = 0; horizontal < (tamañoCuadricula + 9); ++horizontal) {     //tamaño de forma horizontal (35 bloques)
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


    QTimer *gameOverTimer = new QTimer(this);   
    connect(gameOverTimer, &QTimer::timeout, this, &MainWindow::checkGameOver);
    gameOverTimer->start(100);

    QTimer *timerAparecerJugador = new QTimer(this);
    connect(timerAparecerJugador, &QTimer::timeout, this, &MainWindow::aparecerJugador);
    timerAparecerJugador->start(100);

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
        Enemigo * enemigo = new Enemigo(items, &vidas);
        enemigo->setPos(x(),y());
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

void MainWindow::reducirVidas()
{
    vidas--;
}

void MainWindow::checkGameOver()
{
    int cantidadDeEnemigos = 0;

    // Iterar sobre todos los elementos de la escena.
    foreach (QGraphicsItem* item, escena->items()) {
        // Utilizar qgraphicsitem_cast para verificar si es un Enemigo.
        if (Enemigo* enemigo = qgraphicsitem_cast<Enemigo*>(item)) {
                // Incrementar el contador de Enemigos.
            cantidadDeEnemigos++;
        }
    }
    enemigosRestantes = cantidadDeEnemigos;
    // Verificar si no hay más enemigos
    if (enemigosRestantes == 0)
    {
        close();
        qDebug() << "Se debe cerrar 1";

    }
    else if (vidas <0){
        //delete escena;
        //delete vista;
        //bandera = 1;
        //globalVariable = 1;
    /*    QTimer timer;
        timer.setSingleShot(true);  // The timer will only time out once
        QObject::connect(&timer, &QTimer::timeout, this() {    this->close();  // Close the widget when the timer times out
        });*/
        //this->close();
        Button* quitButton = new Button(QString("Quit"));
        int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
        int qyPos = 350;
        quitButton->setPos(qxPos,qyPos);
        connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(quitButton);
        qDebug() << globalVariable;
    }
}

void MainWindow::cambiarTexto()
{
    // Cambiar el texto después de cierto tiempo
    QTimer *actualizacionTimer = new QTimer(this);
    // Iniciar el temporizador para actualizar el texto continuamente
    connect(actualizacionTimer, SIGNAL(timeout()), this, SLOT(actualizarTexto()));
    actualizacionTimer->start(50); // Actualizar el texto cada 50 milisegundos
}

void MainWindow::actualizarTexto()
{
    // Actualizar el texto continuamente después del cambio
    texto->setPlainText("Vidas restantes: " + QString::number(vidas)+ "\tEnemigos Restantes: " + QString::number(enemigosRestantes));
}

void MainWindow::verificarColision()
{
    reducirVidas();
}

void MainWindow::aparecerJugador(){
    if(vidas == 0){
        jugador = new MiCaracter(&items);
        escena->addItem(jugador);
    }
}

