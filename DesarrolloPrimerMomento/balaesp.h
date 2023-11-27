#ifndef BALAESP_H
#define BALAESP_H

#include "bala.h"
#include <QGraphicsScene>
class BalaEsp: public Bala
{
    Q_OBJECT
public:
    BalaEsp();  // Heredar el constructor de ClaseBase
public slots:
    void desplazamiento() override;
};

#endif // BALAESP_H
