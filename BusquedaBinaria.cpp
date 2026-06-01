#include "BusquedaBinaria.h"

int BusquedaBinaria::buscquedaCedula(Turno* arr, int n, std::string cedulaBuscada) {
    int izq = 0;
    int der = n - 1;

    while (izq <= der) {
        int medio = (izq + der) / 2;

        if (arr[medio].getCedula() == cedulaBuscada)
            return medio;

        if (arr[medio].getCedula() < cedulaBuscada)
            izq = medio + 1;
        else
            der = medio - 1;
    }

    return -1;
}

int BusquedaBinaria::buscquedaNombre(Turno* arr, int n, std::string nombre) {
    int izq = 0;
    int der = n - 1;

    while (izq <= der) {
        int medio = (izq + der) / 2;

        if (arr[medio].getNombre() == nombre)
            return medio;

        if (arr[medio].getNombre() < nombre)
            izq = medio + 1;
        else
            der = medio - 1;
    }

    return -1;
}

int BusquedaBinaria::buscarPlaca(Turno* arr, int n, std::string cedulaBuscada) {
    int izq = 0;
    int der = n - 1;

    while (izq <= der) {
        int medio = (izq + der) / 2;

        if (arr[medio].getPlaca() == cedulaBuscada)
            return medio;

        if (arr[medio].getPlaca() < cedulaBuscada)
            izq = medio + 1;
        else
            der = medio - 1;
    }

    return -1;
}

BusquedaBinaria::BusquedaBinaria()
{
}

BusquedaBinaria::~BusquedaBinaria()
{
}