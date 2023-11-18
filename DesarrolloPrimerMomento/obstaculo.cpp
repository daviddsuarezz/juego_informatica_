#include "obstaculo.h"

Obstaculo::Obstaculo()
{
    setRect(0,0,30,30);
}

Obstaculo::Obstaculo(int X, int Y, int tamañoBloque)
{
    setRect(X * tamañoBloque, Y * tamañoBloque, tamañoBloque, tamañoBloque);
}
