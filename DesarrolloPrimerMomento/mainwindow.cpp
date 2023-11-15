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


    jugador->setRect(0,0,50,50);     //x, y, ancho y alto
    QPen lapiz(Qt::darkRed, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);        //contorno de objeto -> color, grosor, propiedades de contorno
    jugador->setPen(lapiz);      //asignarle el contorno a la elipse
    QBrush fondo("#2E86C1", Qt::SolidPattern);          //color a la figura     Código del color, estilo del color
    jugador->setBrush(fondo);        //asignar color a la figura

    escena->addItem(jugador);


    vista = new QGraphicsView();        //decirle a quién mirar, en un punto puede mirar una escena y en otro punto puede mirar otra escena



    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    MiCaracter *enemigo = new MiCaracter;
    enemigo->setRect(1000,600,50,50);
    QPen colorEnemigo(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    enemigo->setPen(colorEnemigo);
    QBrush fondoEnemigo("#85929E", Qt::SolidPattern);          //color a la figura     Código del color, estilo del color
    enemigo->setBrush(fondoEnemigo);
    escena->addItem(enemigo);

    vista->setScene(escena);

    vista->show();              //mostrar la vista

    vista->setFixedSize(1050,650);                  //tamaño de la vista (ventana)
    escena->setSceneRect(0,0,1050,650);             //tamaño de la escena desde el origen de la vista, tamaño

    jugador->setPos(vista->width()/2,vista->height()- jugador->rect().height());        //posición de un objeto (ancho de la vista / 2, alto de la vista - la altura del objeto)

    Enemigo * oponente = new Enemigo();

    escena->addItem(oponente);
    vista->setScene(escena);




    /*


    escena->addItem(elipse);            //agregar elemento a la escena

    ui->Grafica->setScene(escena);     //agregar la escena a la vista gráfica
*/
    tiempo = new QTimer();
    //connect(tiempo, SIGNAL(timeout()), this, SLOT(moverObjeto()));       //slot: cons|ecuencia después de haber activado el timer
    tiempo->start(50);     //cada 100 ms me va a llamar mover objeto)



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
