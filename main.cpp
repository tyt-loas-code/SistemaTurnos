#include <iostream>
#include "AccionesMenu.h"
#include <conio.h>
#include "FechaUtils.h"

using namespace std;

int main()
{
    Lista* miLista = new Lista();
    TablaHash* tabla = new TablaHash(5);
    ListaFeriadosBase feriadosBase;
    feriadosBase.cargarDesdeArchivo("feriados.txt");

    string menu[]={"Registrar","Buscar","Eliminar","Ordenar Turnos","Busqueda binaria","Salir"};
    AccionesMenu accionesMenu;
    system("cls||clear");
    accionesMenu.cargarDatos(miLista, tabla);
    system("pause");

    int size = sizeof(menu)/sizeof(menu[0]);
    int op = 0, tecla;
    bool seguir = true;

    while(seguir)
    {
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
                accionesMenu.ingresarTurno(miLista, feriadosBase);
                break;
            case 1:
               accionesMenu.imprimirTurno(miLista);
                break;
            case 2:
                accionesMenu.eliminarTurno(miLista);
                break;
            case 3:
                accionesMenu.ordenarTurnos(miLista);
                break;
            case 4:
                accionesMenu.busquedaBinaria(miLista);
                break;
            case 5:
                seguir = false;
                break;
            }
        }
    }
    accionesMenu.guardarDatos(miLista);
    delete miLista;



    return 0;
}
