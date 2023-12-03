#ifndef BALA_H
#define BALA_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>
#include <QList>


#include <QWidget>
#include <QPainter>
#include <QTimer>

class Bala: public QObject, public QGraphicsRectItem
{
    Q_OBJECT            //Macro     necesario para hacer uso de slots
protected:
    QTimer *tiempo;
    int cambioX;
    int cambioY;
public:
    Bala();
    void setCambioX(int cambio);
    void setCambioY(int cambio);
    ~Bala();

public slots:
    virtual void desplazamiento();


};



#endif // BALA_H
