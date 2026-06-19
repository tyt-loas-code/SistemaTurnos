#include "Lista.h"
#include "Turno.h"
#include "Validar.h"
#include "ListaFeriadoBase.h"
#include "MenuOrdenamiento.h"
#include "BusquedaBinaria.h"
#include "TablaHash.h"

class AccionesMenu
{
private:
public:

    bool cargarDatos(Lista*, TablaHash*);

    void guardarDatos(Lista* milista);

    void ingresarTurno( Lista*, ListaFeriadosBase&, TablaHash*);

    void eliminarTurno( Lista* );

    void imprimirTurno( Lista* );

    void buscarTurno(TablaHash*);

    int ordenarTurnos(Lista*);

    void busquedaBinaria(Lista*, int);

    void generarCorreos( Lista* );


    AccionesMenu();

    ~AccionesMenu();
};

