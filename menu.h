#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "tda_lista_empleados.h"

typedef struct {
    int finalizacion;
    int inicarSesion;
    int registrarse;
} stLoginIndexes;

typedef struct
{
    int finalizacionIndex;
    int altaPacienteIndex;
    int muestraPacienteIndex;
    int modificaPacienteIndex;
    int darDeBajaPacienteIndex;
    int altaPracticasXIngresoXPaciente;
    int mostrarIngresosConPracticasXPaciente;
    int mostrarPracticas;
    int cargarResultadoPractica;
    int darDeBajaPractica;
    int mostrarIngresos;
    int eliminarIngreso;
    int eliminarEmpleado;
    int mostrarListaEmpleado;
    int salir;
} stMenuIndexes;

void    displayUIPacienteMenu();
void    displayLogin();
void    displayMainMenu();
void    displayAdministrativoMenu();
void    displayProfesionalMenu();
void    displayMenu(stEmpleado);
void    obtenerIndicesMenu(stMenuIndexes*, stEmpleado);


#endif // MENU_H_INCLUDED
