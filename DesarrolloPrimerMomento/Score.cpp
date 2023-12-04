
#include "Score.h"
#include <QFont>



Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    //inicializar el socre en 0

    score = 0;
    // dibujar el texto
    setPlainText("Your life: ");
    setDefaultTextColor(Qt::white); //color incil
    setFont(QFont("times", 16)); // fuente y tamaño
}

void Score::increase()
{
    score++;
    // dibujar el texto
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
