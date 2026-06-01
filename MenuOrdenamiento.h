#ifndef MENUORDENAMIENTO_H
#define MENUORDENAMIENTO_H

#include <string>
#include "Lista.h"

using namespace std;

class MenuOrdenamiento
{
private:
public:
    void ordenarPorNombre(Turno*, int);
    void ordenarPorApellido(Turno*, int);
    void ordenarPorCedula(Turno*, int);
    void ordenarPorFecha(Turno*, int);
    void ordenarPorPlaca(Turno*, int);
    void seleccionarTipoOrden();
    MenuOrdenamiento();
    ~MenuOrdenamiento();
};

template <typename T,typename Comparador>
void shellSort(T* inicio, int tam, int salto, Comparador comparar)
{
    if (salto <= 0)
    {
        return;
    }
    for (int i = salto; i < tam; i++)
    {
        T temp = *(inicio + i);
        T* j = inicio + i;
        while (j >= inicio + salto && comparar(temp, *(j - salto)))
        {
            *j = *(j - salto);
            j -= salto;
        }
    *j = temp;
    }
    shellSort(inicio, tam, salto / 2, comparar);
}

#endif