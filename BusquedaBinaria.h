#include <string>
#include "Turno.h"

class BusquedaBinaria
{
private:
public:
    int buscquedaCedula(Turno*,int, std::string);
    int buscquedaFechaIgualOMayor(Turno*,int, std::string);
    int buscarPlaca(Turno*,int, std::string);
    BusquedaBinaria();
    ~BusquedaBinaria();
};
