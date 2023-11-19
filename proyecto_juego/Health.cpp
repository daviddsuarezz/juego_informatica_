
#include "Health.h"
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <Game.h>
#include <QTimer>
#include <QProcess>
#include <QApplication>

extern Game * game;


Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicializar la vida en 3

    health = 3;
    // dibujar el texto
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::red); //color incil
    setFont(QFont("times", 16)); // fuente y tamaño
}

void Health::decrease()
{
    health--;
    // dibujar el texto
    setPlainText("Health: " + QString::number(health));
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
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, &QEventLoop::quit);
        loop.exec();

        // Cierra el juego y reinicia
        qApp->quit();
        QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
    }
}

int Health::getHealth()
{
    return health;
}
