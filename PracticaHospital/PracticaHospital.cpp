#include "Hospital.h"
#include "Paginador.h"
#include <conio.h>

int main() {
    Hospital hospital;
    hospital.inicializarValores();

    bool repetir = true; 
    bool update = true;
    do {
        if (update) { 
            system("cls");
            cout << "*** SISTEMA DE GESTION DE HOSPITAL ***" << endl << endl;
            cout << "------------ MENU GENERAL ------------" << endl;
            cout << "[L] - Acceso a listados" << endl;
            cout << "[B] - Buscar personas" << endl;
            cout << "[Q] - Agregar nuevo paciente" << endl;
            cout << "[W] - Agregar nuevo medico" << endl;
            cout << "[M] - Gestionar medicos" << endl;
            cout << "[S] - SALIR" << endl;
        }
        update = true;
        switch (toupper(_getch())) {
            case 'L':
                hospital.menuListados();
                break;
            case 'B':
                hospital.menuBusquedaPersonas();
                break;
            case 'Q':
                hospital.addPaciente();
                break;
            case 'W':
                hospital.addMedico();
                break;
            case 'S':
                repetir = false;
                break;
            default:
                update = false;
        }
    } while (repetir);
}