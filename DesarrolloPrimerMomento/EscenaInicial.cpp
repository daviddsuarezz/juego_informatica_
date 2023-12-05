#include "EscenaInicial.h"


EscenaInicial::EscenaInicial(char *argv[], QWidget *parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    scene = new QGraphicsScene();
    scene ->setSceneRect(0,0,800,600);
    setScene(scene);
    if(isdigit(*argv[1]))
        uno = std::stoi(argv[1]);
    else
        uno = 8;
    if(isdigit(*argv[2]))
        dos = std::stoi(argv[2]);
    else
        dos = 200;
    if(isdigit(*argv[3]))
        tres = std::stoi(argv[3]);
    else
        tres = 90;

}

void EscenaInicial::displayMainMenu()
{
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Rick and morty"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);


    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);


}

void EscenaInicial::start()
{
    MainWindow w(uno,dos,tres);
}

