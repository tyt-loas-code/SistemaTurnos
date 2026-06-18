#include <string>
#include "MenuOrdenamiento.h"

string invertirFecha(string fecha)
{
    string dia, mes, year;
    int parte = 0;
    for (char c : fecha)
    {
        if (c == '/')
        {
            parte++;
        }
        if (parte == 0)
        {
            dia += c;
        } else if (parte == 2) {
            mes += c;
        } else {
            year += c;
        }
    }
    return year + "/" + mes + "/" + dia;
}

MenuOrdenamiento::MenuOrdenamiento()
{
}

MenuOrdenamiento::~MenuOrdenamiento()
{
}

void MenuOrdenamiento::ordenarPorCedula(Turno* arregloTurno, int tam)
{
    shellSort(arregloTurno,tam,tam/2,[](Turno& a, Turno& b)
    {
        return a.getCedula() < b.getCedula();
    });
}

void MenuOrdenamiento::ordenarPorNombre(Turno* arregloTurno, int tam)
{
    shellSort(arregloTurno,tam,tam/2,[](Turno& a, Turno& b)
    {
        return a.getNombre() < b.getNombre();
    });
}

void MenuOrdenamiento::ordenarPorApellido(Turno* arregloTurno, int tam)
{
    shellSort(arregloTurno,tam,tam/2,[](Turno& a, Turno& b)
    {
        return a.getApellido() < b.getApellido();
    });
}

void MenuOrdenamiento::ordenarPorPlaca(Turno* arregloTurno, int tam)
{
    shellSort(arregloTurno,tam,tam/2,[](Turno& a, Turno& b)
    {
        return a.getPlaca() < b.getPlaca();
    });
}

void MenuOrdenamiento::ordenarPorFecha(Turno* arregloTurno, int tam)
{
    shellSort(arregloTurno,tam,tam/2,[](Turno& a, Turno& b)
{
    return invertirFecha(a.getFecha()) < invertirFecha(b.getFecha());
});
}