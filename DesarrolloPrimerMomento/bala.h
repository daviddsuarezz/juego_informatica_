#ifndef BALA_H
#define BALA_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

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

#endif // BALA_H
