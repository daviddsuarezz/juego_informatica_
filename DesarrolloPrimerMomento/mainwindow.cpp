#include "mainwindow.h"


#include <QDebug>

#include <string>

#include <QPen>
#include "Game.h"

Game * game;

bool colisiona(QGraphicsItem *item, const QList<QGraphicsItem *> *items) {
    foreach (QGraphicsItem *other, *items) {
        if (item->collidesWithItem(other))
            return true;
    }
    return false;
}


juego::juego(int uno_, int dos_, int tres_,QGraphicsView *vist,QGraphicsScene *scen, QWidget *parent)

{
    qDebug()<< 15;

    enemigosRestantes = uno_;
    escena  =  scen;
    escena->clear();

    vista = vist;
    vista->setScene(escena);
    vista->setFixedSize(1050,810);
    escena->setSceneRect(0,-15,1050,780);


    /*    escena = new QGraphicsScene(this);
    vista = new QGraphicsView(escena);
    vista->setFixedSize(1050,810);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,-15,1050,780);
*/
    //vista->fitInView(escena->sceneRect(), Qt::KeepAspectRatio);

    jugador = new MiCaracter(&items);            //crear objeto

    Caracter = 1;





    escena->setBackgroundBrush(QBrush("#DEC561"));       //Set fondo

    texto = new QGraphicsTextItem();
    vidas = 1;
    uno = dos_;
    dos = tres_;
    escena->addItem(jugador);








    //vista->setFixedSize(1050,810);                  //tamaño de la vista (ventana)
                 //tamaño de la escena desde el origen de la vista, tamaño
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
    cambioTimer->start(1000); // Cambiar el texto después de 10000 milisegundos (10 segundos)




    crearObstaculos();
    crearEnemigos(uno_);



    gameOverTimer = new QTimer(this);
    connect(gameOverTimer, &QTimer::timeout, this, &juego::checkGameOver);
    gameOverTimer->start(100);


    QTimer *timerAparecerJugado = new QTimer(this);
    connect(timerAparecerJugado, &QTimer::timeout, this, &juego::aparecerJugado);
    timerAparecerJugado->start(100);

    vista->show();qDebug()<< 25;
}


juego::~juego()
{
    foreach (QGraphicsItem *other, items){
        delete other;
    }
}

void juego::crearObstaculos(){
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
                }
            }
        }
    }
}

void juego::crearEnemigos(int cantEnem)
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

void juego::reducirVidas()
{
    vidas--;
}

void juego::checkGameOver()
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
    }
    else if (vidas <0){
        gameOverTimer->stop();
        delete vista;
        game = new Game(uno,dos);
        game->show();
        close();
        qDebug() << "Se debe cerrar 1";

    }
}

void juego::cambiarTexto()
{
    actualizarTexto();

}

void juego::actualizarTexto()
{
    // Actualizar el texto continuamente después del cambio
    texto->setPlainText("Vidas restantes: " + QString::number(vidas)+ "\tEnemigos Restantes: " + QString::number(enemigosRestantes));
}

void juego::verificarColision()
{
    reducirVidas();
}

void juego::aparecerJugado(){
    qDebug() << "hols";
    if(vidas == 0){

        jugador = new MiCaracter(&items);
        escena->addItem(jugador);
    }
}

