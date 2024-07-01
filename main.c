#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "funciones.h"
#include "archivos.h"
#include "tda_lista_empleados.h"

#define ARCH_PACIENTES              "./archivos/pacientes.dat"
#define ARCH_INGRESOS               "./archivos/ingresos.dat"
#define ARCH_PRACTICAS_X_INGRESOS   "./archivos/practicas_x_ingresos.dat"
#define ARCH_PRACTICAS              "./archivos/practicas.dat"
#define ARCH_EMPLEADOS              "./archivos/empleados.dat"

#define PERFIL_ADMINISTRADOR        "administrador"
#define PERFIL_ADMINISTRATIVO       "administrativo"
#define PERFIL_PROFESIONAL          "profesional"

int main()
{
    FILE *archPacientes, *archIngresos, *archPracticasXIngreso, *archPracticas, *archEmpleados;
    ArbolPacientes* arbolPacientes;
    nodoPracticas* listaPracticas;
    nodoEmpleado * listaEmpleados;
    stMenuIndexes menuIndexes;
    stLoginIndexes loginIndexes;
    stEmpleado usuarioLogeado;
    int loginExitoso = 0;

    /** Inicializaciones **/
    arbolPacientes = inicializarArbol();
    listaPracticas = inicListaPracticas();
    listaEmpleados = inicializarListaEmpleados();

    archPacientes =         fopen(ARCH_PACIENTES, "rb");
    archIngresos =          fopen(ARCH_INGRESOS, "rb");
    archPracticasXIngreso = fopen(ARCH_PRACTICAS_X_INGRESOS, "rb");
    archPracticas =         fopen(ARCH_PRACTICAS, "rb");
    archEmpleados =         fopen(ARCH_EMPLEADOS, "rb");

    /** Carga datos de arhivos **/
    arbolPacientes = cargarADLDL(arbolPacientes, archPacientes, archIngresos, archPracticasXIngreso);
    listaPracticas = cargarPracticas(listaPracticas, archPracticas);
    listaEmpleados = cargarListaDeArchivoEmpleados(archEmpleados, listaEmpleados);

    /** Login **/
    loginIndexes.finalizacion = 0;
    loginIndexes.inicarSesion = 1;
    loginIndexes.registrarse = 2;
    int opcionLogin = loginIndexes.finalizacion;

    do {
        inicio:
        system("cls");
        displayLogin();
        printf(" ");
        scanf("%d", &opcionLogin);

        if(opcionLogin == loginIndexes.inicarSesion)
        {
            loginExitoso = iniciarSesion(&usuarioLogeado);
            if(loginExitoso) {
                break;
            } else {
                printf("\n Error al iniciar sesion.\n");
                system("pause");
            }
        }
        else if(opcionLogin == loginIndexes.registrarse)
        {
            listaEmpleados = registrarEmpleado(listaEmpleados);
        }
    } while (!loginExitoso);

    int esAdministrativo = strcmp(usuarioLogeado.perfil, PERFIL_ADMINISTRATIVO) == 0;
    int esAdministrador = strcmp(usuarioLogeado.perfil, PERFIL_ADMINISTRADOR) == 0;
    int esProfesional = strcmp(usuarioLogeado.perfil, PERFIL_PROFESIONAL) == 0;

    /** MENU Principal**/
    menuIndexes.finalizacionIndex = 0;
    int opcion = menuIndexes.finalizacionIndex;
    obtenerIndicesMenu(&menuIndexes, usuarioLogeado);
    do {
        system("cls");
        mostrarEmpleadoEnMenu(usuarioLogeado);
        printf("\n______________________________MENU__________________________________\n\n");
        printf(" 0- Persistir datos y finalizar (no cerrar consola) \n\n");
        displayMenu(usuarioLogeado);
        printf("\n____________________________________________________________________\n\n");
        printf(" Eleccion: ");
        scanf("%i", &opcion);
        if(opcion == menuIndexes.finalizacionIndex) {
            break;
        }
        else if(opcion == menuIndexes.altaPacienteIndex)
        {
            arbolPacientes = altaDePaciente(arbolPacientes);
        }
        else if(opcion == menuIndexes.muestraPacienteIndex)
        {
            esAdministrador == 1 ? muestraArbol(arbolPacientes) : muestraArbolNoEliminados(arbolPacientes);
        }
        else if(opcion == menuIndexes.modificaPacienteIndex)
        {
            modificarPaciente(arbolPacientes);
        }
        else if(opcion == menuIndexes.darDeBajaPacienteIndex)
        {
            darDeBajaPaciente(arbolPacientes);
        }
        else if(opcion == menuIndexes.altaPracticasXIngresoXPaciente)
        {
            arbolPacientes = altaDePracticaPorIngresoPorPaciente(arbolPacientes, &listaPracticas);
        }
        else if(opcion == menuIndexes.mostrarIngresosConPracticasXPaciente)
        {
            esAdministrador == 1 ? mostrarPracticasPorIngresosPorPaciente(arbolPacientes, listaPracticas) : mostrarPracticasPorIngresosPorPacienteNoEliminados(arbolPacientes, listaPracticas);
        }
        else if(opcion == menuIndexes.mostrarPracticas)
        {
            esAdministrador == 1 ? mostrarPracticas(listaPracticas) : mostrarPracticasSinEliminado(listaPracticas);
        }
        else if(opcion == menuIndexes.cargarResultadoPractica)
        {
            cargarResultadoPractica(arbolPacientes, listaPracticas);
        }
        else if (opcion == menuIndexes.mostrarIngresos)
        {
            esAdministrador == 1 ? mostrarIngresosSegunPaciente(arbolPacientes) : mostrarIngresosSegunPacienteSinEliminados(arbolPacientes);
        }
        else if (opcion == menuIndexes.eliminarIngreso)
        {
            eliminarIngreso(arbolPacientes);
        }
        else if (opcion == menuIndexes.darDeBajaPractica)
        {
            eliminarPractica(listaPracticas);
        }
        else if (opcion == menuIndexes.eliminarEmpleado)
        {
            int dni;
            printf(" Ingrese DNI del empleado a borrar: ");
            scanf("%d", &dni);
            listaEmpleados = eliminarEmpleado(listaEmpleados, dni);
        }
        else if (opcion == menuIndexes.mostrarListaEmpleado)
        {
            mostrarListaEmpleados(listaEmpleados);
        }
        else if (opcion == menuIndexes.salir)
        {
            loginExitoso = 0;
            goto inicio;
        }
        system("pause");
    } while(opcion != menuIndexes.finalizacionIndex);

    /** Guarda - persiste datos en archivos **/
    archPacientes =         fopen(ARCH_PACIENTES, "wb");
    archIngresos =          fopen(ARCH_INGRESOS, "wb");
    archPracticasXIngreso = fopen(ARCH_PRACTICAS_X_INGRESOS, "wb");
    archPracticas =         fopen(ARCH_PRACTICAS, "wb");
    archEmpleados =         fopen(ARCH_EMPLEADOS, "wb");

    guardarADLDL(arbolPacientes, archPacientes, archIngresos, archPracticasXIngreso);
    guardarPracticas(listaPracticas, archPracticas);
    guardarEmpleadosEnArchivo(archEmpleados, listaEmpleados);

    fclose(archPacientes);
    fclose(archIngresos);
    fclose(archPracticasXIngreso);
    fclose(archPracticas);
    fclose(archEmpleados);

    return 0;
}
