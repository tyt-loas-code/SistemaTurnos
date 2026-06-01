#ifndef LISTAFERIADOSBASE_H
#define LISTAFERIADOSBASE_H

#include <string>
#include "NodoFeriadoBase.h"

class ListaFeriadosBase
{
private:

    NodoFeriadoBase* cabeza;

public:

    ListaFeriadosBase();

    ~ListaFeriadosBase();

    void agregar(int dia, int mes, bool inamovible);

    void limpiar();

    bool cargarDesdeArchivo(std::string nombreArchivo);

    NodoFeriadoBase* getCabeza();


};

#endif
