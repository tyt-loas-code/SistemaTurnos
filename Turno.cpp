/***********************************************************************
 * Module:  Turno.cpp
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 17:59:30
 * Purpose: Implementation of the class Turno
 ***********************************************************************/

#include "Turno.h"

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Turno::getCedula()
// Purpose:    Implementation of Turno::getCedula()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Turno::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::setCedula(string newCedula)
// Purpose:    Implementation of Turno::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Turno::setCedula(string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::getNombre()
// Purpose:    Implementation of Turno::getNombre()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Turno::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::setNombre(string newNombre)
// Purpose:    Implementation of Turno::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Turno::setNombre(string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::getApellido()
// Purpose:    Implementation of Turno::getApellido()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Turno::getApellido(void)
{
   return apellido;
}


////////////////////////////////////////////////////////////////////////
// Name:       Turno::setNombre(string newApellido)
// Purpose:    Implementation of Turno::setApellido()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Turno::setApellido(string newApellido)
{
   nombre = newApellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::getPlaca()
// Purpose:    Implementation of Turno::getPlaca()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Turno::getPlaca(void)
{
   return placa;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::setPlaca(string newPlaca)
// Purpose:    Implementation of Turno::setPlaca()
// Parameters:
// - newPlaca
// Return:     void
////////////////////////////////////////////////////////////////////////

void Turno::setPlaca(string newPlaca)
{
   placa = newPlaca;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::getHora()
// Purpose:    Implementation of Turno::getHora()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Turno::getHora(void)
{
   return hora;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::setHora(string newHora)
// Purpose:    Implementation of Turno::setHora()
// Parameters:
// - newHora
// Return:     void
////////////////////////////////////////////////////////////////////////

void Turno::setHora(string newHora)
{
   hora = newHora;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::getFecha()
// Purpose:    Implementation of Turno::getFecha()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Turno::getFecha(void)
{
   return fecha;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::setFecha(string newFecha)
// Purpose:    Implementation of Turno::setFecha()
// Parameters:
// - newFecha
// Return:     void
////////////////////////////////////////////////////////////////////////

void Turno::setFecha(string newFecha)
{
   fecha = newFecha;
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::Turno(string cedula, string nombre, string placa, string matricula, string hora, string fecha)
// Purpose:    Implementation of Turno::Turno()
// Parameters:
// - cedula
// - nombre
// - placa
// - matricula
// - hora
// - fecha
// Return:
////////////////////////////////////////////////////////////////////////

Turno::Turno(string cedula, string nombre, string apellido, string placa, string hora, string fecha)
{
   this -> cedula    = cedula;
   this -> nombre    = nombre;
   this -> apellido  = apellido;
   this -> placa     = placa;
   this -> hora      = hora;
   this -> fecha     = fecha;
}

Turno::Turno()
{
   this -> cedula    = "";
   this -> nombre    = "";
   this -> placa     = "";
   this -> hora      = "";
   this -> fecha     = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       Turno::~Turno()
// Purpose:    Implementation of Turno::~Turno()
// Return:
////////////////////////////////////////////////////////////////////////

Turno::~Turno()
{
   // TODO : implement
}
