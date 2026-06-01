#include "AccionesMenu.h"
#include "FechaUtils.h"
#include <iostream>
#include <regex>
#include <fstream>
#include <conio.h>

using namespace std;

AccionesMenu::AccionesMenu()
{
}

AccionesMenu::~AccionesMenu()
{
}

void actualizarLista(Lista* lista, Turno* arreglo, int tam)
{
    Nodo* actual = lista->getCabeza();
    int i = 0;
    do
    {
        actual->setTurno(*(arreglo +i));
        i++;
        actual = actual->getSiguiente();

    } while(actual != lista->getCabeza());
}

void AccionesMenu::cargarDatos(Lista* milista)
{
    ifstream archivo( "C:/Programas/Proyecto-Turnos-main/turnos.txt" );
    if ( !archivo.is_open() )
    {
        cout << "No se encontro el archivo" << endl;
        return;
    }
    string c, n, a, p, m, h, f;
    while ( archivo >> c >> n >> a >> p >> m >> h >> f )
    {
        milista -> insertar( c , n , a , p , m , h , f );
    }
    cout<<"Archivos cargados" <<endl;
    archivo.close();
}

void AccionesMenu::ingresarTurno(Lista* milista, ListaFeriadosBase& feriadosBase)
{
    Validar v;
    cout << "INGRESAR UN TURNO" << endl;
    string cedula, nombre, apellido, placa, matricula, hora, fecha;
    while (true) {
        cout << "Ingrese la cedula (10 digitos): ";
        cin >> cedula;
        if (v.validarCedula(cedula)) break;
    }
    
    while (true) {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        if (v.validarPalabra(nombre)) break;
    }

    while (true) {
        cout << "Ingrese el apellido: ";
        cin >> apellido;
        if (v.validarPalabra(apellido)) break;
    }

    while (true) {
        cout << "Ingrese la placa (formato AAA1234): ";
        cin >> placa;
        if (v.validarPlaca(placa)) break;
    }

    cout << "Ingrese la matricula: ";
    cin >> matricula;

    while (true)
    {
        cout << "Ingrese la fecha (dd/mm/aaaa): ";
        cin >> fecha;
        if (v.validarFecha(fecha))
        {
            int d, m, a;
            extraerDiaMesAnio(fecha, d, m, a);
            if (fechaExiste(d, m, a)) break;
            else cout << "Fecha no valida" << endl;
        }
    }

    string fechaLaborable = siguienteLaborable(fecha, feriadosBase);
    if (fechaLaborable != fecha)
    {
        cout << "La fecha ingresada cae en fin de semana o feriado. Se asigna: " << fechaLaborable << endl;
    }

    while (true)
    {
        cout << "Ingrese la hora (HH:MM, de 08:00 a 16:00): ";
        cin >> hora;

        if (!v.validarHora(hora))
            continue;

        bool ocupado = false;
        Nodo* actual = milista -> getCabeza();

        if (actual != nullptr)
        {
            do {
                Turno t = actual->getTurno();
                if (t.getFecha() == fechaLaborable && t.getHora() == hora)
                {
                    ocupado = true;
                    break;
                }

                actual = actual -> getSiguiente();
            } while (actual != milista -> getCabeza());
        }

        if (ocupado)
        {
            cout << "Hora ocupada en esa fecha. Elija otra hora." << endl;
        } else {
            break;
        }
    }

    milista->insertar(cedula, nombre, apellido, placa, matricula, hora, fechaLaborable);
    cout << "Turno registrado exitosamente." << endl;

    guardarDatos(milista);
    cin.ignore();
    cin.get();
}

void AccionesMenu::eliminarTurno(Lista* miLista)
{
    string cedula;
    cout << "ELIMINAR TURNO" << endl;
    cout << "Ingrese la cedula del turno que desea eliminar: ";
    cin >> cedula;
    miLista -> eliminar(cedula);
    cout << "Turno eliminado (si existia)." << endl;
    guardarDatos(miLista);
    cin.ignore();
    cin.get();
}

void AccionesMenu::guardarDatos(Lista* milista)
{
    ofstream archivo("turnos.txt");
    if (!archivo.is_open())
    {
        cout << "No se pudo guardar el archivo" << endl;
        return;
    }
    Nodo* actual = milista->getCabeza();
    if (actual != nullptr)
    {
        do
        {
            Turno t = actual->getTurno();
            archivo << t.getCedula()    << " "
                    << t.getNombre()    << " "
                    << t.getApellido()  << " "
                    << t.getPlaca()     << " "
                    << t.getMatricula() << " "
                    << t.getHora()      << " "
                    << t.getFecha()     << endl;
            actual = actual->getSiguiente();
        } while ( actual != milista -> getCabeza() );
    }
    archivo.close();
    cout << "Turnos guardados correctamente." << endl;
}

void AccionesMenu::imprimirTurno(Lista* miLista) {
    string cedula;
    cout << "IMPRIMIR TURNO" << endl;
    cout << "Ingrese la cedula: ";
    cin >> cedula;
    Nodo* nodo = miLista->buscarTurno(cedula);
    if (nodo != nullptr) {
        Turno t = nodo->getTurno();
        cout << "TURNO" << endl;
        cout << "Cedula: " << t.getCedula() << endl;
        cout << "Nombre: " << t.getNombre() << endl;
        cout << "Apellido: " << t.getApellido() << endl;
        cout << "Placa: " << t.getPlaca() << endl;
        cout << "Matricula: " << t.getMatricula() << endl;
        cout << "Hora: " << t.getHora() << endl;
        cout << "Fecha: " << t.getFecha() << endl;
    } else {
        cout << "No se encontro ningun turno registrado con esa cedula." << endl;
    }
    cin.ignore();
    cin.get();
}

Turno* cargarArreglo(Lista* miLista, int& tam)
{
    tam = 0;
    Nodo* actual = miLista->getCabeza();
    if (actual == nullptr)
    {
        return nullptr;
    }
    do
    {
        tam++;
        actual = actual->getSiguiente();
    } while(actual != miLista->getCabeza());
    Turno* arreglo = new Turno[tam];
    actual = miLista->getCabeza();
    int i = 0;
    do
    {
        *(arreglo + i) = actual->getTurno();
        i++;
        actual = actual->getSiguiente();
    } while(actual != miLista->getCabeza());
    return arreglo;
}



void AccionesMenu::ordenarTurnos(Lista* milista)
{
    int tam;
    Turno* arregloTurno = cargarArreglo(milista, tam);
    MenuOrdenamiento m;
    string menu[]={"Ordenar por cedula","Ordenar por nombre","Ordenar por apellido","Ordenar por placa","Ordenar por fecha","Salir"};
    system("cls||clear");

    int size = sizeof(menu)/sizeof(menu[0]);
    int op = 0, tecla;
    bool seguir = true;
    bool datosCargados = true;

    while(seguir)
    {
        if (!datosCargados)
        {
            guardarDatos(milista);
        }
        system("cls||clear");
        cout << "==== MENU ====" << endl;
        for (int i = 0; i < size ; i++)
        {
            if (i == op)
            {
                cout << "-> ";
            } else {
                cout << "   ";
            }
            cout << menu[i] << endl;
        }
        tecla = _getch();
        if (tecla==224 || tecla == 0)
        {
            tecla = _getch();

            if (tecla == 72)
            {
                op --;
                if (op < 0){
                    op = size -1;
                }
            } else if (tecla == 80) {
                op++;

                if (op >= size){
                    op = 0;
                }
            }
        } else if (tecla == 13){
            switch (op)
            {
            case 0:
                m.ordenarPorCedula(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                break;
            case 1:
                m.ordenarPorNombre(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                break;
            case 2:
                m.ordenarPorApellido(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                break;
            case 3:
                m.ordenarPorPlaca(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                break;
            case 4:
                m.ordenarPorFecha(arregloTurno, tam);
                break;
            case 5:
                seguir = false;
                break;
            }
        }
    }
    delete[] arregloTurno;
}

void AccionesMenu::busquedaBinaria(Lista* miLista)
{
    int tam;
    Turno* arregloTurno = cargarArreglo(miLista, tam);
    BusquedaBinaria b;
    string menu[]={"Buscar cedula","Buscar nombre","Buscar placa","Salir"};
    system("cls||clear");
    string buscar;

    int size = sizeof(menu)/sizeof(menu[0]);
    int op = 0, tecla;
    bool seguir = true;
    bool datosCargados = true;

    while(seguir)
    {
        bool validar = false;
        Validar v;
        if (!datosCargados)
        {
            guardarDatos(miLista);
        }
        system("cls||clear");
        cout << "==== MENU ====" << endl;
        for (int i = 0; i < size ; i++)
        {
            if (i == op)
            {
                cout << "-> ";
            } else {
                cout << "   ";
            }
            cout << menu[i] << endl;
        }
        tecla = _getch();
        if (tecla==224 || tecla == 0)
        {
            tecla = _getch();

            if (tecla == 72)
            {
                op --;
                if (op < 0){
                    op = size -1;
                }
            } else if (tecla == 80) {
                op++;

                if (op >= size){
                    op = 0;
                }
            }
        } else if (tecla == 13){
            switch (op)
            {
            case 0:
                while(!validar){
                    cout << "Ingrese la cedula" << endl;
                    cin >> buscar;
                    validar=v.validarCedula(buscar);
                }
                b.buscquedaCedula(arregloTurno, size, buscar);
                break;
            case 1:
                b.buscquedaNombre(arregloTurno, size, buscar);
                while(!validar){
                    cout << "Ingrese el nombre" << endl;
                    cin >> buscar;
                    validar=v.validarPalabra(buscar);
                }
                break;
            case 2:
                b.buscarPlaca(arregloTurno, size, buscar);
                while(!validar){
                    cout << "Ingrese la placa" << endl;
                    cin >> buscar;
                    validar=v.validarPlaca(buscar);
                }
                break;
            case 3:
                seguir = false;
                break;
            }
        }
    }
    delete[] arregloTurno;
}