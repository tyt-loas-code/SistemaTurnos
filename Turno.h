/***********************************************************************
 * Module:  Turno.h
 * Author:  sacoe
 * Modified: martes, 12 de mayo de 2026 17:59:30
 * Purpose: Declaration of the class Turno
 ***********************************************************************/

#if !defined(__ProyetoEstructura_Turno_h)
#define __ProyetoEstructura_Turno_h
#include <string>

using namespace std;

class Turno
{
public:

   string getCedula(void);

   void setCedula(string newCedula);

   string getNombre(void);

   void setNombre(string newNombre);

   string getApellido(void);

   void setApellido(string newAppelido);

   string getPlaca(void);

   void setPlaca(string newPlaca);

   string getHora(void);

   void setHora(string newHora);

   string getFecha(void);

   void setFecha(string newFecha);

   Turno(string cedula, string nombre, string apellido, string placa, string hora, string fecha);

   Turno();
   ~Turno();

protected:
private:

   string cedula;
   string nombre;
   string apellido;
   string placa;
   string hora;
   string fecha;


};

#endif
