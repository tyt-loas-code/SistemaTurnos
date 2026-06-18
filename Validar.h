#include "Validaciones.h"

using namespace std;

class Validar : public Validaciones
{
    public:

        bool validarCedula   ( string cedula ) override;

        bool validarPalabra  ( string palabra ) override;

        bool verificarExistencia ( string cedula ) override;

        bool validarPlaca    ( string placa ) override;

        bool validarHora     ( string hora ) override;

        bool validarFecha    ( string fecha ) override;

        int calcularDigitoVerificador(string& cedula);

};
