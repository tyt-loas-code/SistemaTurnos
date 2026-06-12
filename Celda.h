#ifndef CELDA_H
#define CELDA_H

#include <iomanip>
#include "Turno.h"

class Celda
{
private:
public:
    Turno dato;
    Celda* siguiente;
    size_t n;
    
    explicit Celda(const Turno& t) : dato(t), siguiente(nullptr){}
};

#endif
