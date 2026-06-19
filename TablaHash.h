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

    void insertar(Turno);
    Turno* buscar(const string&);
    bool eliminar(const string&);
    bool estaVacia();
};

#endif