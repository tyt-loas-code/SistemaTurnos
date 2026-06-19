#include "Utilidades.h"

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