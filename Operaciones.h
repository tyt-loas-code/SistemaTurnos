/***********************************************************************
 * Module:  Operaciones.h
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 19:19:11
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined(__ProyetoEstructura_Operaciones_h)
#define __ProyetoEstructura_Operaciones_h

#include "Nodo.h"

using namespace std;

class Operaciones
{
public:

   virtual void insertar( string, string, string, string, string, string ) = 0;

   virtual Nodo* buscar() = 0;

   virtual void eliminar(string) = 0;

   virtual void imprimir() = 0;

protected:
private:

};

#endif
