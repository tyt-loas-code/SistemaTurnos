/***********************************************************************
 * Module:  Nodo.h
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 18:39:21
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__ProyetoEstructura_Nodo_h)
#define __ProyetoEstructura_Nodo_h

#include "Turno.h"

class Nodo
{
public:


   Nodo(Turno, Nodo* );

   Nodo(Turno turno, Nodo* sig, Nodo* ant);

   Nodo();

   ~Nodo();

   Nodo* getAnterior();

   void setAnterior(Nodo* newAnterior);

   Turno getTurno();

   void setTurno( Turno );

    Nodo* getSiguiente();

   void setSiguiente( Nodo* newSiguiente );


protected:
private:

   Turno turno;
   Nodo* siguiente;
   Nodo* anterior;

};

#endif
