#ifndef BALA_H
#define BALA_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <QList>
#include "enemigo.h"

#include <QMouseEvent>
#include <QWidget>
#include <QPainter>
#include <QTimer>
class Bala: public QObject, public QGraphicsRectItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
private:
    QTimer *tiempo;
public:
    Bala();
    ~Bala();
public slots:
    void desplazamiento();
};

/*
class BulletWidget : public QWidget
{
    Q_OBJECT

public:
    BulletWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        // Configura la bala en una posición inicial
        bullet = new Bala();

        // Conecta la señal de posición cambiada de la bala al slot correspondiente
        connect(bullet, &Bala::positionChanged, this, &BulletWidget::updateBulletPosition);
    }

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        // Maneja el evento de clic del ratón
        if (event->button() == Qt::LeftButton)
        {
            // Calcula la dirección desde la posición actual hasta la posición del clic
            int dx = event->x() - bullet->x();
            int dy = event->y() - bullet->y();

            // Normaliza la dirección para que la bala se mueva a una velocidad constante
            double length = qSqrt(dx * dx + dy * dy);
            bullet->setPos(dx / length, dy / length);
        }
    }

    void paintEvent(QPaintEvent *event) override
    {
        // Pinta la bala en su posición actual
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.drawEllipse(bullet->x(), bullet->y(), 10, 10);
    }

private slots:
    void updateBulletPosition(int x, int y)
    {
        // Maneja la señal de posición cambiada de la bala
        Q_UNUSED(x);
        Q_UNUSED(y);
        update(); // Vuelve a pintar el widget
    }

private:
    Bala *bullet;
};
*/

#endif // BALA_H
