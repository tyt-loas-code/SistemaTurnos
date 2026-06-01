#include "NodoFeriadoBase.h"



NodoFeriadoBase::NodoFeriadoBase( int dia, int mes, bool inamovible, NodoFeriadoBase* siguiente )
{
    this -> dia        = dia;
    this -> mes        = mes;
    this -> inamovible = inamovible;
    this -> siguiente  = siguiente;
}

NodoFeriadoBase::NodoFeriadoBase()
{
    this -> dia = 0;
    this -> mes = 0;

    this -> inamovible = false;
    this -> siguiente  = nullptr;
}
