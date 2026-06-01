#ifndef NODOFERIADOBASE_H
#define NODOFERIADOBASE_H

class NodoFeriadoBase
{
public:

    int dia;
    int mes;

    bool inamovible;

    NodoFeriadoBase* siguiente;

    NodoFeriadoBase( int dia, int mes, bool inamovible, NodoFeriadoBase* siguiente );

    NodoFeriadoBase();

};

#endif
