#include "FechaUtils.h"
#include <ctime>
#include <iostream>

using namespace std;

int stringToInt(string s)
{
    int resultado = 0;

    for ( char c : s )
    {
        if ( c >= '0' && c <= '9' )
        {
            resultado = resultado * 10 + (c - '0');
        }
    }
    return resultado;
}

string intToString(int n) {

    if (n == 0)
        return "0";

    string s;

    int temp = n;

    int divisor = 1;

    while (temp / divisor >= 10)
        divisor *= 10;

    while (divisor > 0)
    {
        int digito = n / divisor;

        s.push_back(char('0' + digito));

        n %= divisor;

        divisor /= 10;
    }
    return s;
}

void extraerDiaMesAnio(string fecha, int& dia, int& mes, int& anio)
{
    int valor = 0;
    int etapa = 0; // 0=d�a, 1=mes, 2=a�o

    dia = 0;
    mes = 0;
    anio = 0;

    for (char c : fecha)
    {
        if (c == '/')
        {
            if (etapa == 0)
            {
                dia = valor;

            } else if ( etapa == 1 )
            {
                mes = valor;
            }

            ++etapa;
            valor = 0;

        } else {

            valor = valor * 10 + (c - '0');

        }
    }

    anio = valor;
}

void extraerHoraMinutos(string hora, int& horas, int& minutos)
{
    int valor = 0;
    int etapa = 0; 
    horas = 0;
    minutos = 0;

    for ( char c : hora )
    {
        if ( c == ':')
        {

            horas = valor;
            ++etapa;
            valor = 0;

        } else  {
            valor = valor * 10 + ( c - '0');
        }
    }
    minutos = valor;
}

bool esBisiesto(int anio)
{
        if (anio % 4 != 0) {
            return false;
        }

        if (anio % 100 != 0) {
                return true;
        }


        if (anio % 400 == 0) {
            return true;
        }

    return false;
}

int diasEnMes(int mes, int anio)
{
    if (mes == 2)
    {
        if (esBisiesto(anio))
        {
            return 29;

        } else {

            return 28;
        }
    }

    if ( mes == 4 || mes == 6 || mes == 9 || mes == 11 ) {
        return 30;
    }

    return 31;
}

bool fechaExiste(int dia, int mes, int anio)
{
    time_t t = time(nullptr);
    tm* hoy = localtime(&t);

    int diaActual = hoy->tm_mday;
    int mesActual = hoy->tm_mon + 1;
    int anioActual = hoy->tm_year + 1900;
    int horaActual = hoy->tm_hour;
    if (dia < 1 || dia > diasEnMes(mes, anio))
        return false;

    if (anio < anioActual)
        return false;

    if (anio == anioActual && mes < mesActual)
        return false;

    if (anio == anioActual && mes == mesActual && dia < diaActual)
        return false;

    if (anio == anioActual && mes == mesActual && dia == diaActual && horaActual >= 16)
    {
        std::cout << "Mas de las 16:00. ";
        return false;
    }
    
        
    return true;
}

int zeller( int dia, int mes, int anio )
{
        if ( mes == 1 || mes == 2 )
        {
            mes = mes + 12;
            anio = anio - 1;
        }

        int K = anio % 100; 
        int J = anio / 100;

        int h = ( dia + (13 * (mes + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
        if (h == 0) 
        {
            return 6;
        }

        if (h == 1)
        {
            return 0;
        }

    return h - 1; 
}


void calcularViernesSanto(int anio, int& dia, int& mes)
{
    int a = anio % 19;

    int b = anio / 100;

    int c = anio % 100;

    int d = b / 4;

    int e = b % 4;

    int f = (b + 8) / 25;

    int g = (b - f + 1) / 3;

    int h = (19 * a + b - d - g + 15) % 30;

    int i = c / 4;

    int k = c % 4;

    int l = (32 + 2 * e + 2 * i - h - k) % 7;

    int m = (a + 11 * h + 22 * l) / 451;

    int mesPascua = (h + l - 7 * m + 114) / 31;

    int diaPascua = ((h + l - 7 * m + 114) % 31) + 1;


    if (diaPascua > 2)
    {
        dia = diaPascua - 2;
        mes = mesPascua;

    } else {
        if ( mesPascua == 3 )
        {
            mes = 2;

            int diasFebrero = diasEnMes(2, anio);

            dia = diasFebrero - (2 - diaPascua);

        } else if ( mesPascua == 4 )
        {

            mes = 3;
            dia = 31 - (2 - diaPascua);

        } else {
            mes = 3;
            dia = 31;
        }
    }
}

void calcularMartesCarnaval(int anio, int& dia, int& mes)
{
    int a = anio % 19;

    int b = anio / 100;

    int c = anio % 100;

    int d = b / 4;

    int e = b % 4;

    int f = (b + 8) / 25;

    int g = (b - f + 1) / 3;

    int h = (19 * a + b - d - g + 15) % 30;

    int i = c / 4;

    int k = c % 4;

    int l = (32 + 2 * e + 2 * i - h - k) % 7;

    int m = (a + 11 * h + 22 * l) / 451;

    int mesPascua = (h + l - 7 * m + 114) / 31;

    int diaPascua = ((h + l - 7 * m + 114) % 31) + 1;

    string fechaPascua = "";

    if (diaPascua < 10)
      {
          fechaPascua = "0";
      }

    fechaPascua = fechaPascua + intToString( diaPascua ) + "/";

    if (mesPascua < 10)
    {
        fechaPascua = fechaPascua + "0";
    }

    fechaPascua = fechaPascua + intToString(mesPascua) + "/" + intToString(anio);

    for (int i = 0; i < 47; ++i)
    {
        fechaPascua = restarUnDia(fechaPascua);
    }

    extraerDiaMesAnio( fechaPascua, dia, mes, anio );
}

string sumarUnDia(string fecha)
{
    int dia, mes, anio;
    extraerDiaMesAnio(fecha, dia, mes, anio);
    dia++;
    if (dia > diasEnMes(mes, anio)) {
        dia = 1;
        mes++;
        if (mes > 12) {
            mes = 1;
            anio++;
        }
    }
    string resultado;
    if (dia < 10) resultado = "0";
    resultado = resultado + intToString(dia) + "/";
    if (mes < 10) resultado = resultado + "0";
    resultado = resultado + intToString(mes) + "/" + intToString(anio);
    return resultado;
}

string restarUnDia(string fecha)
{
    int dia, mes, anio;
    string resultado;

    extraerDiaMesAnio(fecha, dia, mes, anio);

    dia = dia - 1;
    if (dia < 1)
    {
        mes = mes - 1;

        if (mes < 1)
        {
            mes = 12;
            anio = anio - 1;
        }

        dia = diasEnMes(mes, anio);
    }

    if (dia < 10)
        {
           resultado = "0";
        }

    resultado = resultado + intToString(dia) + "/";

    if (mes < 10)
    {
        resultado = resultado + "0";
    }

    resultado = resultado + intToString(mes) + "/" + intToString(anio);

    return resultado;
}

void desplazarFecha( int diaBase, int mesBase, int anio, int desplazamiento, int& diaRes, int& mesRes, int& anioRes ) {

    string fechaStr = "";

    if (diaBase < 10)
        fechaStr = "0";

    fechaStr = fechaStr + intToString(diaBase) + "/";

    if (mesBase < 10)
        fechaStr = fechaStr + "0";

    fechaStr = fechaStr + intToString(mesBase) + "/" + intToString(anio);

    if (desplazamiento >= 0)
    {
        for (int i = 0; i < desplazamiento; ++i)
        {
            fechaStr = sumarUnDia(fechaStr);
        }

    } else {
        for (int i = 0; i < -desplazamiento; ++i)
        {
            fechaStr = restarUnDia(fechaStr);
        }
    }

    extraerDiaMesAnio(fechaStr, diaRes, mesRes, anioRes);
}

bool esFeriado(int dia, int mes, int anio, ListaFeriadosBase& feriadosBase)
{
    int diaVS, mesVS;

    calcularViernesSanto(anio, diaVS, mesVS);

    if (dia == diaVS && mes == mesVS)
        return true;

    int diaCarn, mesCarn;

    calcularMartesCarnaval(anio, diaCarn, mesCarn);

    if (dia == diaCarn && mes == mesCarn)
        return true;

    NodoFeriadoBase* actual = feriadosBase.getCabeza();

    while (actual != nullptr)
    {
        int diaBase     = actual ->dia;
        int mesBase     = actual ->mes;
        bool inamovible = actual ->inamovible;

        if (inamovible)
        {

            if (dia == diaBase && mes == mesBase)
                return true;

        } else {
            int diaSem = zeller(diaBase, mesBase, anio);

            int desplazamiento = 0;

            if ( diaSem == 2)
                {
                desplazamiento = -1;
                }
            else if ( diaSem == 3 )
            {
            }

            else if ( diaSem == 4 )
            {
                desplazamiento = 1;
            }
            else if ( diaSem == 6 )
            {
                desplazamiento = -1;
            }
            else if ( diaSem == 0 )
            {
                desplazamiento = 1;
            }

            if ( desplazamiento != 0 )
            {
                int diaReal, mesReal, anioReal;

                desplazarFecha( diaBase, mesBase, anio, desplazamiento, diaReal, mesReal, anioReal );

                if ( dia == diaReal && mes == mesReal )
                    return true;
            } else {
                if ( dia == diaBase && mes == mesBase )
                    return true;
            }
        }
        actual = actual -> siguiente;
    }
    return false;
}

string siguienteLaborable(std::string fecha, ListaFeriadosBase& feriadosBase) {
    int dia, mes, anio;
    extraerDiaMesAnio(fecha, dia, mes, anio);

    while (zeller(dia, mes, anio) == 0 || zeller(dia, mes, anio) == 6 || esFeriado(dia, mes, anio, feriadosBase)) {
        fecha = sumarUnDia(fecha);
        extraerDiaMesAnio(fecha, dia, mes, anio);
    }
    return fecha;
}
