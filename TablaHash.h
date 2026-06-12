#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "Celda.h"
#include "Turno.h"

class TablaHash
{
private:
    Celda** tabla;
    int capacidad;

    int hash(const string&);
public:
    TablaHash(int);
    ~TablaHash();

    void insertar(const Turno&);
    Turno* buscar(int numero);

};

#endif