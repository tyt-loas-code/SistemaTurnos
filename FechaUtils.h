#ifndef FECHAUTILS_H
#define FECHAUTILS_H

#include <string>
#include"ListaFeriadoBase.h"

using namespace std;



    void extraerDiaMesAnio(string fecha, int& dia, int& mes, int& anio);

    void extraerHoraMinutos(string hora, int& horas, int& minutos);

    bool esBisiesto(int anio);

    bool fechaExiste(int dia, int mes, int anio);

    bool esFeriado(int dia, int mes, int anio, ListaFeriadosBase& feriadosBase);

    int diasEnMes(int mes, int anio);

    int stringToInt(string s);

    string intToString(int n);

    int zeller(int dia, int mes, int anio);

    void calcularViernesSanto(int anio, int& dia, int& mes);

    void calcularMartesCarnaval(int anio, int& dia, int& mes);

    string restarUnDia(string fecha);

    string sumarUnDia(std::string fecha);

    string siguienteLaborable(std::string fecha, ListaFeriadosBase& feriadosBase);

#endif
