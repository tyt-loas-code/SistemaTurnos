/***********************************************************************
 * Module:  Lista.h
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 19:07:16
 * Purpose: Declaration of the class Lista
 ***********************************************************************/

#if !defined(__ProyetoEstructura_Lista_h)
#define __ProyetoEstructura_Lista_h

#include "Nodo.h"
#include "Operaciones.h"

using namespace std;

class Lista
{
public:

   Lista();
   ~Lista();

   Nodo* getCabeza();

   void setCabeza( Nodo* );

   Nodo* getCola();

   void setCola( Nodo* );

   void insertar(string cedula, string nombre, string apellido, string placa, string hora, string fecha);

   void eliminar(string);

   Nodo* buscarTurno(string);

   bool existeTurno(string fecha, string hora);

   void eliminarLineaArchivo(string);

protected:
private:

   Nodo* cabeza;
   Nodo* cola;


};

#endif
