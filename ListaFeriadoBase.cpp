#include "ListaFeriadoBase.h"
#include "FechaUtils.h"
#include <fstream>
#include <iostream>

using namespace std;

ListaFeriadosBase::ListaFeriadosBase()
{
    this -> cabeza = nullptr;
}

ListaFeriadosBase::~ListaFeriadosBase()
{
    this -> limpiar();
}

void ListaFeriadosBase::agregar( int dia, int mes, bool inamovible )
{

    NodoFeriadoBase* nuevo = new NodoFeriadoBase( dia, mes, inamovible, this -> cabeza );
    this -> cabeza         = nuevo;

}

bool ListaFeriadosBase::cargarDesdeArchivo(string nombreArchivo)
{
    ifstream archivo("C:/Programas/Proyecto-Turnos-main/feriados.txt");

    if ( !archivo.is_open() )
    {
        cout << "No se pudo abrir " << nombreArchivo << endl;
        return false;
    }

    string linea;

    while (getline(archivo, linea))
    {
        if (linea.empty())
        {
            continue;
        }

        int posEspacio = -1;
        int idx = 0;

        for ( char c : linea )
        {
            if (c == ' ')
            {
                posEspacio = idx;
                break;
            }

            ++idx;
        }

        if (posEspacio == -1)
        {
            continue;
        }

        string fechaStr = "";
        int cont = 0;

        for ( char c : linea )
        {

            if (cont == posEspacio)
            {
                break;
            }

            fechaStr = fechaStr + c;
            ++cont;
        }

        string flagStr = "";
        int cont2 = 0;

        for ( char c : linea )
        {
            if ( cont2 > posEspacio )
            {
                flagStr = flagStr + c;
            }

            ++cont2;
        }

        int dia, mes, anioIgn;

        extraerDiaMesAnio( fechaStr, dia, mes, anioIgn );

        int flag = stringToInt( flagStr );

        bool inamovible = ( flag == 1 );

        this -> agregar( dia, mes, inamovible );
    }

    archivo.close();

    return true;
}

NodoFeriadoBase* ListaFeriadosBase::getCabeza()
{
    return this -> cabeza;
}

void ListaFeriadosBase::limpiar()
{
    NodoFeriadoBase* actual = this -> cabeza;

    while ( actual != nullptr )
    {
        NodoFeriadoBase* temp = actual;
        actual                = actual -> siguiente;

        delete temp;

    }

    this -> cabeza = nullptr;
}
