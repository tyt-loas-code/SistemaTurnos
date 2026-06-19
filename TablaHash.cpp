#include "TablaHash.h"

int TablaHash::hash(const string& cedula)
{
    int suma = 0;
    for (char c : cedula)
    {
        suma += c;
    }
    return suma % capacidad;
}

TablaHash::TablaHash(int capacidad)
{
    this -> capacidad = capacidad;
    tabla = new Celda*[capacidad];

    for(int i = 0; i < capacidad; i++)
    {
        *(tabla + i) = nullptr;
    }
}

TablaHash::~TablaHash()
{
    for (int i = 0; i < capacidad; i++)
    {
        Celda* actual = *(tabla + i);

        while (actual)
        {
            Celda* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    delete []tabla;
}

void TablaHash::insertar(Turno turno)
{
    int pos = hash(turno.getCedula());

    Celda* nuevo = new Celda(turno);

    nuevo->siguiente = *(tabla + pos);
    *(tabla + pos) = nuevo;
}

Turno* TablaHash::buscar(const string& cedula)
{
    int pos = hash(cedula);

    Celda* actual = *(tabla + pos);
    while (actual)
    {
        if (actual->dato.getCedula() == cedula)
        {
            return &(actual->dato);
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}

bool TablaHash::eliminar(const string& cedula)
{
    int pos = hash(cedula);
    Celda* actual = tabla[pos];
    Celda* anterior = nullptr;
    while(actual != nullptr)
    {
        if(actual->dato.getCedula() == cedula)
        {
            if(anterior == nullptr)
            {
                *(tabla + pos) = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }

            delete actual;
            return true;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    return false;
}

bool TablaHash::estaVacia()
{
    for (int i = 0; i < capacidad; i++)
    {
        if (*(tabla + i) != nullptr)
            return false;
    }
    return true;
}