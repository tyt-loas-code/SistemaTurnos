/***********************************************************************
 * Module:  Lista.cpp
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 19:07:16
 * Purpose: Implementation of the class Lista
 ***********************************************************************/

#include "Lista.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Lista::Lista()
// Purpose:    Implementation of Lista::Lista()
// Return:
////////////////////////////////////////////////////////////////////////

Lista::Lista()
{
   this -> cabeza = nullptr;
   this -> cola = nullptr;
}

////////////////////////////////////////////////////////////////////////
// Name:       Lista::~Lista()
// Purpose:    Implementation of Lista::~Lista()
// Return:
////////////////////////////////////////////////////////////////////////

Lista::~Lista()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Lista::getCabeza()
// Purpose:    Implementation of Lista::getCabeza()
// Return:     Nodo
////////////////////////////////////////////////////////////////////////

Nodo* Lista::getCabeza()
{
   return this->cabeza;
}

////////////////////////////////////////////////////////////////////////
// Name:       Lista::setCabeza(Nodo newCabeza)
// Purpose:    Implementation of Lista::setCabeza()
// Parameters:
// - newCabeza
// Return:     void
////////////////////////////////////////////////////////////////////////

void Lista::setCabeza(Nodo* newCabeza)
{
   this->cabeza = newCabeza;
}

////////////////////////////////////////////////////////////////////////
// Name:       Lista::getCola()
// Purpose:    Implementation of Lista::getCola()
// Return:     Nodo
////////////////////////////////////////////////////////////////////////

Nodo* Lista::getCola()
{
   return this->cola;
}

////////////////////////////////////////////////////////////////////////
// Name:       Lista::setCola(Nodo newCola)
// Purpose:    Implementation of Lista::setCola()
// Parameters:
// - newCola
// Return:     void
////////////////////////////////////////////////////////////////////////

void Lista::setCola(Nodo* newCola)
{
   this->cola = newCola;
}

void Lista::insertar(string cedula, string nombre, string apellido, string placa, string matricula, string hora, string fecha)\
{
    Nodo* nuevo = new Nodo(Turno(cedula, nombre, apellido, placa, matricula, hora, fecha), nullptr, nullptr);

    if (cabeza == nullptr)
    {
        cabeza = nuevo;
        cola   = nuevo;
        cabeza -> setSiguiente(cabeza);
        cabeza -> setAnterior(cabeza);
    } else
    {
        nuevo  -> setSiguiente(cabeza);
        nuevo  -> setAnterior(cola);
        cabeza -> setAnterior(nuevo);
        cola   -> setSiguiente(nuevo);
        cabeza = nuevo;
    }
}

void Lista::eliminar(string cedula)
{
   if (cabeza==nullptr)
   {
      return;
   }
   Nodo* actual = cabeza;
   Nodo* anterior = cola;
   do
   {
      if (actual->getTurno().getCedula() == cedula)
      {
         if(actual == cabeza && actual == cola){
            delete actual;
            cabeza = nullptr;
            cola = nullptr;
            return;
         } else {
            if (actual == cabeza)
            {
               cabeza = cabeza->getSiguiente();
               cola->setSiguiente(cabeza);
            } else if (actual == cola)
            {
               cola = anterior;
               cola->setSiguiente(cabeza);
            } else {
               anterior->setSiguiente(actual->getSiguiente());
            }
            delete actual;
            eliminarLineaArchivo(cedula);
            return;
         }
      }
      anterior = actual;
      actual = actual->getSiguiente();
   } while (actual != cabeza);
   cout<<"Turno no registrado con la cedula"<<endl;
}

Nodo* Lista::buscarTurno( string cedula )
{
   Nodo* actual = cabeza;

   do
   {
      if ( actual -> getTurno().getCedula() == cedula )
      {
         return actual;
      }

      actual = actual -> getSiguiente();

   } while ( actual -> getSiguiente() != cabeza );

   return nullptr;
}

bool Lista::existeTurno(string fecha, string hora) {
    if (cabeza == nullptr) return false;
    Nodo* actual = cabeza;
    do {
        Turno t = actual->getTurno();
        if (t.getFecha() == fecha && t.getHora() == hora) {
            return true;
        }
        actual = actual->getSiguiente();
    } while (actual != cabeza);
    return false;
}

void Lista::eliminarLineaArchivo(string cedula)
{
    ifstream archivo("Turnos.txt");
    ofstream temporal("Temporal.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    string linea;
    while (getline(archivo, linea))
    {
        stringstream ss(linea);
        string cedulaArchivo;
        getline(ss, cedulaArchivo, ',');
        if (cedulaArchivo != cedula)
        {
            temporal << linea << endl;
        }
    }
    archivo.close();
    temporal.close();
    remove("Turnos.txt");
    rename("Temporal.txt", "Turnos.txt");
}
