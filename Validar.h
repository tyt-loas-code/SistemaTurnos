#include "Validaciones.h"

using namespace std;

class Validar : public Validaciones
{
    public:

        bool validarCedula   ( string cedula ) override;

        bool validarPalabra  ( string palabra ) override;

        bool validarPlaca    ( string placa ) override;

        bool validarMatricula( string matricula ) override;

        bool validarHora     ( string hora ) override;

        bool validarFecha    ( string fecha ) override;

        int calcularDigitoVerificador(string& cedula);

};
