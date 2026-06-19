#include "Validar.h"
#include "FechaUtils.h"
#include <regex>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

bool verificarExistenciaPlaca(string placa)
{
    ifstream archivo("C:/Programas/SistemaTurnos-main/turnos.txt");
    if (archivo.is_open()){
    } else {
        cout<<"No se encontro el archivo"<< endl;
        archivo.close();
        return false;
    }
    string nombre, ced, apellido, pla;
    while (archivo >> ced >> nombre >> apellido >> pla) {
      if (pla == placa){
         return true;
      }
    }
    archivo.close();
    return false;
}

bool Validar::verificarExistencia(string cedula)
{
    ifstream archivo("C:/Programas/SistemaTurnos-main/turnos.txt");
    if (archivo.is_open()){
    } else {
        archivo.close();
        return false;
    }
    string nombre, ced;
    while (archivo >> ced) {
      if (ced == cedula){
         cout << "Cedula con turno registrado" << endl;
         return true;
      }
    }
    archivo.close();
    return false;
}

bool codigoProvincia(string cod)
{
   ifstream archivo("C:/Programas/SistemaTurnos-main/Provincias.txt");
   if (!archivo.is_open())
   {
      cout<<"No se pudo abrir el arhivo"<<endl;
      return true;
   }
   string codigo;
   while (archivo >> codigo)
   {
      if (codigo == cod)
      {
         return true;
      }
   }
   return false;
}

auto validarCedulaCorrecta = [](std::string cedula) -> bool
{
   int suma = 0;

   for (int i = 0; i < 9; i++)
   {
      int num = *(cedula.c_str() + i) - '0';

      if (i % 2 == 0)
      {
         num *= 2;

         if (num > 9)
         {
            num -= 9;
         }
      }

      suma += num;
   }

   int digitoVerificador = 10 - (suma % 10);

   if (digitoVerificador == 10)
   {
      digitoVerificador = 0;
   }

   if (digitoVerificador != (*(cedula.c_str() + 9) - '0'))
   {
      std::cout << "Cedula incorrecta" << std::endl;
      return false;
   }
   return true;
};

int obtenerSize(string palabra)
{
   int size=0;
   const char *pal = palabra.c_str();
   while (*(pal + size) != '\0')
   {
      size++;
   }
   return size;
}

bool Validar::validarCedula(string cedula)
{
    regex patron("^[0-9]+$");
   if (!regex_match(cedula, patron)){
      cout<<"Ingrese cedula sin letras o caracteres especiales"<<endl;
      return false;
   }
   if (obtenerSize(cedula) != 10)
   {
      cout<<"Solo se permiten 10 digitos"<<endl;
      return false;
   }
   string codProvincia = cedula.substr(0,2);
   if(!codigoProvincia(codProvincia))
   {
      return false;
   }
   if (!validarCedulaCorrecta(cedula))
   {
      return false;
   }
   return true;
}

bool Validar::validarPalabra(string palabra)
{
   regex patron("^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$");
   if(!regex_match(palabra,patron))
      {
      cout<<"Nombre solo debe contener letras"<<endl;
      return false;
      }
      const char* cad = palabra.c_str();
   return true;
}

bool Validar::validarPlaca(string placa)
{
    regex patron("^[A-Z]{3}([0-9]{4})$");
    if (!regex_match(placa, patron))
    {
        cout<<"Placa invalida, ingrese una placa correcta"<<endl;
        return false;
    }
    if (verificarExistenciaPlaca(placa))
      {
      cout<<"Placa con turno registrado"<<endl;
      return false;
      }
    return true;
}

bool Validar::validarFecha(string fecha)
{
   regex patron(R"(^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4}$)");
   if (!regex_match(fecha, patron))
   {
      cout << "Formato de fecha invalido. Use DD/MM/AAAA" << endl;
      return false;
   }
   return true;
}

bool Validar::validarHora(string hora, string fecha)
{
   time_t t = time(nullptr);
   tm* hoy = localtime(&t);
   int horaActual = hoy ->tm_hour;

   regex patron("^([0-1][0-9]|2[0-3]):00$");
   if (!regex_match(hora, patron))
   {
      cout << "Formato de hora invalido. Use HH:00 en punto" << endl;
      return false;
   }

   int hh, mm, d, m, aa, horaCorrecta;
   extraerHoraMinutos(hora, hh, mm);
   extraerDiaMesAnio(fecha, d, m, aa);
   if(fechaExiste(d,m,aa))
   {
      horaCorrecta = 8;
   } else {
      horaCorrecta = horaActual;
   }

   if (hh >= horaCorrecta && hh <= 16)
   {
      return true;
   }
   cout << "Hora fuera del horario laboral (8:00 a 16:00, turnos de 1 hora)" << endl;
   return false;
}
