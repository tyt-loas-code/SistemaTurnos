#include "BusquedaBinaria.h"
#include "Utilidades.h"

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

int BusquedaBinaria::buscquedaFechaIgualOMayor(Turno* arr, int n, string fecha)
{
    int izq = 0;
    int der = n - 1;
    int respuesta = -1;

    while (izq <= der)
    {
        int medio = (izq + der) / 2;

        if (invertirFecha((arr + medio)->getFecha()) >= invertirFecha(fecha))
        {
            respuesta = medio;
            der = medio - 1;
        } else {
            izq = medio + 1;
        }
    }
    
    return respuesta;
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