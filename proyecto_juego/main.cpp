
#include <QApplication>
#include "Game.h"


Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game(argv);
    game->show();
    game->displayMainMenu();


    return a.exec();
}
