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

bool AccionesMenu::cargarDatos(Lista* milista, TablaHash* tabla)
{
    ifstream archivo( "C:/Programas/SistemaTurnos-main/turnos.txt" );
    if ( !archivo.is_open() )
    {
        cout << "No se encontro el archivo" << endl;
        return true;
    }
    string c, n, a, p, h, f;
    TablaHash temporal(101);
    while (archivo >> c >> n >> a >> p>> h >> f)
    {
        if (temporal.buscar(c) == nullptr)
        {
            Turno turno( c , n , a , p , h , f);
            temporal.insertar(turno);
        } else {
            cout << "Archivo manipulado, saliendo del programa." << endl;
            return false;
        }
    }
    
    archivo.clear();
    archivo.seekg(0);

    while ( archivo >> c >> n >> a >> p >> h >> f )
    {
        Turno turno(c , n , a , p , h , f);
        milista -> insertar( c , n , a , p  , h , f );
        tabla ->insertar(turno);
    }
    cout<<"Archivo cargado" <<endl;
    archivo.close();
    return true;
}

void AccionesMenu::ingresarTurno(Lista* milista, ListaFeriadosBase& feriadosBase, TablaHash* tabla)
{
    Validar v;
    bool validar;
    cout << "INGRESAR UN TURNO" << endl;
    string cedula, nombre, apellido, placa, hora, fecha, fechaLaborable;
    do
    {
        cout << "Ingrese la cedula: ";
        cin >> cedula;
        if (v.validarCedula(cedula) && !(v.verificarExistencia(cedula))){
            validar = true;
        } else {
            validar = false;
        }
    } while (!validar);
    
    do
    {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        validar = v.validarPalabra(nombre);
    } while (!validar);    

    do
    {
        cout << "Ingrese el apellido: ";
        cin >> apellido;
        validar = v.validarPalabra(apellido);
    }while (!validar);

    do 
    {
        cout << "Ingrese la placa (formato AAA1234): ";
        cin >> placa;
        validar =  v.validarPlaca(placa);
    }while (!validar);

    do
    { 
        do
        {
            cout << "Ingrese la fecha (dd/mm/aaaa): ";
            cin >> fecha;
            validar = v.validarFecha(fecha);
            if (validar)
            {
                int d, m, a;
                extraerDiaMesAnio(fecha, d, m, a);
                validar = fechaExiste(d, m, a);
            }
            if (!validar){
                cout << "Fecha no valida" << endl;
            }
        }while (!validar);

        fechaLaborable = siguienteLaborable(fecha, feriadosBase);
        if (fechaLaborable != fecha)
        {
            cout << "La fecha ingresada cae en fin de semana o feriado. Se asigna: " << fechaLaborable << endl;
        }

        do
        {
            do{
                cout << "Ingrese la hora (HH:MM, de 08:00 a 16:00): ";
                cin >> hora;
                validar = v.validarHora(hora, fechaLaborable);
            }while (!validar);

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
                validar = false;
                cout << "Hora ocupada en esa fecha. Elija otra hora." << endl;
            } else {
                validar = true;
            }
        }while(!validar);        
    }while (!validar);

    Turno t(cedula, nombre, apellido, placa, hora, fechaLaborable);
    milista->insertar(cedula, nombre, apellido, placa, hora, fechaLaborable);
    cout << "Turno registrado exitosamente." << endl;
    tabla ->insertar(t);

    guardarDatos(milista);
    cin.ignore();
    cin.get();
}

void AccionesMenu::eliminarTurno(Lista* miLista, TablaHash* tabla)
{
    string cedula;
    bool eliminado = false;

    if (miLista->getCabeza() == nullptr)
    {
        cout << "No existen turnos cargados" << endl;
        system("pause");
        return;
    }
    cout << "ELIMINAR TURNO" << endl;
    cout << "Ingrese la cedula del turno que desea eliminar: ";
    cin >> cedula;
    eliminado = tabla->eliminar(cedula);
    if (eliminado)
    {
        if (miLista != nullptr)
        {
            miLista->eliminar(cedula);
        }
        cout << "Turno eliminado" << endl;
    } else {
        cout << "El turno no existia" << endl;
    }
    if (miLista != nullptr)
    {
        guardarDatos(miLista);
    }
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
    bool validar;
    Validar v;
    if (miLista->getCabeza() == nullptr)
    {
        cout << "No existen turnos cargados" << endl;
        system("pause");
        return;
    }
    
    cout << "IMPRIMIR TURNO" << endl;
    do
    {
        cout << "Ingrese la cedula: ";
        cin >> cedula;
        validar = v.validarCedula(cedula);
    } while (!validar);
    Nodo* nodo = miLista->buscarTurno(cedula);
    if (nodo != nullptr) {
        Turno t = nodo->getTurno();
        cout << "TURNO" << endl;
        cout << "Cedula: " << t.getCedula() << endl;
        cout << "Nombre: " << t.getNombre() << endl;
        cout << "Apellido: " << t.getApellido() << endl;
        cout << "Placa: " << t.getPlaca() << endl;
        cout << "Hora: " << t.getHora() << endl;
        cout << "Fecha: " << t.getFecha() << endl;
    } else {
        cout << "No se encontro ningun turno registrado con esa cedula." << endl;
    }
    cin.ignore();
    cin.get();
}

void AccionesMenu::buscarTurno(TablaHash* tabla)
{
    bool validar;
    string cedula;
    Validar v;
    if (tabla->estaVacia()){
        cout << "No existen turnos cargados" << endl;
        system("pause");
        return;
    }
    do
    {
        cout << "Ingrese la cedula: ";
        cin >> cedula;
        validar = v.validarCedula(cedula);
    } while (!validar);
    Turno* t = tabla ->buscar(cedula);
    if (t != nullptr)
    {
        cout << "TURNO" << endl;
        cout << "Cedula: " << t->getCedula() << endl;
        cout << "Nombre: " << t->getNombre() << endl;
        cout << "Apellido: " << t->getApellido() << endl;
        cout << "Placa: " << t->getPlaca() << endl;
        cout << "Hora: " << t->getHora() << endl;
        cout << "Fecha: " << t->getFecha() << endl;
    } else {
        cout << "Turno no encontrado en la tabla" << endl;
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



int AccionesMenu::ordenarTurnos(Lista* milista)
{
    if (milista->getCabeza() == nullptr){
        cout << "No existen turnos cargados" << endl;
        system("pause");
        return -1;
    }
    int tam;
    Turno* arregloTurno = cargarArreglo(milista, tam);
    MenuOrdenamiento m;
    string menu[]={"Ordenar por cedula","Ordenar por nombre","Ordenar por apellido","Ordenar por placa","Ordenar por fecha","Salir"};
    system("cls||clear");

    int size = sizeof(menu)/sizeof(menu[0]);
    int op = 0, tecla, orden = -1;
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
                orden = 1;
                break;
            case 1:
                m.ordenarPorNombre(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                orden = -1;
                break;
            case 2:
                m.ordenarPorApellido(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                orden = -1;
                break;
            case 3:
                m.ordenarPorPlaca(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                orden = 3;
                break;
            case 4:
                m.ordenarPorFecha(arregloTurno, tam);
                actualizarLista(milista, arregloTurno, tam);
                datosCargados = false;
                orden = 2;
                break;
            case 5:
                seguir = false;
                break;
            }
        }
    }
    delete[] arregloTurno;
    return orden;
}

void AccionesMenu::busquedaBinaria(Lista* miLista, int orden)
{
    if (miLista->getCabeza() == nullptr){
        cout << "No existen turnos cargados" << endl;
        system("pause");
        return;
    }
    int tam;
    int pos;
    Turno* arregloTurno = cargarArreglo(miLista, tam);
    BusquedaBinaria b;
    string menu[]={"Buscar cedula","Buscar fecha proxima","Buscar placa","Salir"};
    system("cls||clear");
    string buscar;

    int size = sizeof(menu)/sizeof(menu[0]);
    int op = 0, tecla;
    bool seguir = true;
    bool datosCargados = true;

    while(seguir)
    {
        bool validar;
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
                if(orden == 1){
                    do{
                        cout << "Ingrese la cedula" << endl;
                        cin >> buscar;
                        validar=v.validarCedula(buscar);
                    }while (!validar);
                    pos = b.buscquedaCedula(arregloTurno, tam, buscar);
                    if (pos >= 0)
                    {
                        cout << "Cedula: " <<(arregloTurno + pos)->getCedula() << endl;
                        cout << "Para la fecha :" << (arregloTurno + pos)->getFecha() << endl;
                    } else {
                        cout << "No se encontro ninguna cedula" << endl;
                    }
                } else {
                    cout << "Ordenar por cedula" << endl;
                }
                system("pause");
                break;
            case 1:
                if (orden == 2){
                    do{
                        cout << "Ingrese la fecha con el formato DD/MM/AAAA" << endl;
                        cin >> buscar;
                        validar=v.validarFecha(buscar);
                    } while(!validar);
                    pos = b.buscquedaFechaIgualOMayor(arregloTurno, tam, buscar);
                    if (pos >= 0)
                    {
                        cout << "Fecha proxima: " <<(arregloTurno + pos)->getFecha() << endl;
                    } else {
                        cout << "No se encontro niguna fecha" << endl;
                    }
                } else {
                    cout << "Ordenar por fecha" << endl;
                }
                system("pause");
                break;
            case 2:
                if (orden == 3){
                    do{
                        cout << "Ingrese la placa" << endl;
                        cin >> buscar;
                        validar=v.validarPlaca(buscar);
                    } while(!validar);
                    pos = b.buscarPlaca(arregloTurno, tam, buscar);
                    if (pos >= 0)
                    {
                        cout << "Fecha proxima: " <<(arregloTurno + pos)->getFecha() << endl;
                    } else {
                        cout << "Placa: " <<(arregloTurno + pos)->getPlaca() << endl;
                        cout << "Para la fecha :" << (arregloTurno + pos)->getFecha() << endl;
                    }
                } else {
                    cout << "Ordenar por placa" << endl;
                }
                system("pause");
                break;
            case 3:
                seguir = false;
                break;
            }
        }
    }
    delete[] arregloTurno;
}