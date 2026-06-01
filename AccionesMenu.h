#include "Lista.h"
#include "Turno.h"
#include "Validar.h"
#include "ListaFeriadoBase.h"
#include "MenuOrdenamiento.h"
#include "BusquedaBinaria.h"

class AccionesMenu
{
private:
public:

    void cargarDatos( Lista* );

    void guardarDatos(Lista* milista);

    void ingresarTurno( Lista*, ListaFeriadosBase& );

    void eliminarTurno( Lista* );

    void imprimirTurno( Lista* );

    void ordenarTurnos(Lista*);

    void busquedaBinaria(Lista*);

    void generarCorreos( Lista* );


    AccionesMenu();

    ~AccionesMenu();
};

