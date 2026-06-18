/***********************************************************************
 * Module:  Validaciones.h
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 20:23:24
 * Purpose: Declaration of the class Validaciones
 ***********************************************************************/

#if !defined(__ProyetoEstructura_Validaciones_h)
#define __ProyetoEstructura_Validaciones_h
#include <string>

using namespace std;

class Validaciones
{
public:

   virtual bool validarCedula(string)    = 0;

   virtual bool validarPalabra(string)   = 0;

   virtual bool validarPlaca(string)     = 0;

   virtual bool validarHora(string)      = 0;

   virtual bool validarFecha(string)     = 0;

protected:
private:

};

#endif
