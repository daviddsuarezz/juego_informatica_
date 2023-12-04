#include "Health.h"
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <Game.h>
#include <QTimer>
#include <QProcess>
#include <QApplication>

extern Game * game;


Health::Health(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    //inicializar la vida en 3
    health = 3;

    // dibujar el rectángulo
    healthBar = new QGraphicsRectItem(this);
    healthBar->setRect(5, 30, health * 50, 20);
    healthBar->setBrush(QBrush(Qt::red));
}

void Health::decrease()
{
    health--;
    // actualizar el rectángulo
    healthBar->setRect(5, 30, health * 50, 20);
    if (health <= 0) {
        // Muestra una pantalla de "Game Over"

        QGraphicsTextItem *gameOverText = new QGraphicsTextItem("Game Over");
        gameOverText->setFont(QFont("times", 16));
        gameOverText->setDefaultTextColor(Qt::red);
        scene()->addItem(gameOverText);

        // Centra el texto de "Game Over" en la escena
        gameOverText->setPos(scene()->width() / 2 - gameOverText->boundingRect().width() / 2,
                             scene()->height() / 2 - gameOverText->boundingRect().height() / 2);


        // Agrega un retraso antes de cerrar la aplicación
        /*
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec();
*/


        game->Gameover(false);


        /*
        // Cierra el juego y reinicia
        qApp->quit();

        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
*/
    }
}

int Health::getHealth()
{
    return health;
}
