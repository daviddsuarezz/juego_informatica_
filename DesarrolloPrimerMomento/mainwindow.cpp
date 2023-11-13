#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);      //Configurar la escena

    escena  =  new QGraphicsScene();    //Definir Escena para montar la "obra"

    elipse = new MiElipse();            //crear objeto

    elipse->setFlag(QGraphicsItem::ItemIsFocusable);        //Habilito la posibilidad de enfocar el objeto para generar KeyPressEvent
    elipse->setFocus();         //enfoco el KeyPressEvent en el objeto


    elipse->setRect(0,0,50,50);     //x, y, ancho y alto
    elipse->setStartAngle(90*16);       //cada ángulo tiene 16 porciones, set una porción de la figura
    elipse->setSpanAngle(270*16);       //cada ángulo tiene 16 porciones, set una porción de la figura
    QPen lapiz(Qt::darkRed, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);        //contorno de objeto -> color, grosor, propiedades de contorno
    elipse->setPen(lapiz);      //asignarle el contorno a la elipse
    QBrush fondo("#2E86C1", Qt::SolidPattern);          //color a la figura     Código del color, estilo del color
    elipse->setBrush(fondo);        //asignar color a la figura

    escena->addItem(elipse);


    vista = new QGraphicsView();        //decirle a quién mirar, en un punto puede mirar una escena y en otro punto puede mirar otra escena
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setScene(escena);

    vista->show();              //mostrar la vista


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
    elipse->setPos(10+contador, 10);        //mover elipse (únicamente en x en este caso)
    contador += 5;
}

