#ifndef BALAENEM_H
#define BALAENEM_H

#include "bala.h"
#include <QGraphicsScene>
#include "MiCaracter.h"


class BalaEnem: public Bala
{
    Q_OBJECT
public:
    BalaEnem(int *vida);
public slots:
    void desplazamiento() override;
private:
    int *vidas;
};

#endif // BALAENEM_H
