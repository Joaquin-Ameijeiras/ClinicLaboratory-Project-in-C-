#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

#define PERFIL_ADMINISTRADOR        "administrador"
#define PERFIL_ADMINISTRATIVO       "administrativo"
#define PERFIL_PROFESIONAL          "profesional"

void displayMainMenu() {
    printf("------------------PACIENTES------------------- \n\n");
    printf(" 1- Alta de paciente \n");
    printf(" 2- Mostrar pacientes \n");
    printf(" 3- Modificar datos del paciente \n");
    printf(" 4- Dar de baja paciente \n");
    printf("\n-------PRACTICAS x INGRESOS x PACIENTES------- \n\n");
    printf(" 5- Ingrese practicas x ingreso x paciente \n");
    printf(" 6- Mostrar ingresos con practicas del paciente \n");
    printf(" 7- Mostrar practicas \n");
    printf(" 8- Cargar resultados \n");
    printf(" 9- Dar de baja practica\n");
    printf("\n------------------INGRESOS------------------- \n\n");
    printf(" 10- Mostrar Ingresos segun paciente\n");
    printf(" 11- Eliminar ingreso segun paciente\n");
    printf("\n------------------EMPLEADOS------------------- \n\n");
    printf(" 12- Eliminar Empleado\n");
    printf(" 13- Mostrar Empleados\n");
    printf(" 14- Salir\n");
}

void displayAdministrativoMenu() {
    printf("------------------PACIENTES------------------- \n\n");
    printf(" 1- Alta de paciente \n");
    printf(" 2- Mostrar pacientes \n");
    printf(" 3- Modificar datos del paciente \n");
    printf(" 4- Dar de baja paciente \n");
    printf("\n-------PRACTICAS x INGRESOS x PACIENTES------- \n\n");
    printf(" 5- Ingrese practicas x ingreso x paciente \n");
    printf(" 6- Mostrar ingresos con practicas del paciente \n");
    printf(" 7- Mostrar practicas \n");
    printf(" 8- Dar de baja practica\n");
    printf("\n------------------INGRESOS------------------- \n\n");
    printf(" 9- Mostrar Ingresos segun paciente\n");
    printf(" 10- Eliminar ingreso segun paciente\n");
    printf(" 11- Salir\n");
}

void displayProfesionalMenu() {
    printf("------------------PACIENTES------------------- \n");
    printf(" 1- Mostrar pacientes \n");
    printf("------------------PRACTICAS------------------- \n");
    printf(" 2- Mostrar listado general de practicas \n");
    printf(" 3- Mostrar practicas de un paciente \n");
    printf("---------------CARGAR RESULTADOS--------------- \n");
    printf(" 4- Cargar resultados \n");
    printf(" 5- Salir\n");
}

void obtenerIndicesMenu(stMenuIndexes* menuIndexes, stEmpleado usuarioLogeado) {
    int esAdministrativo = strcmp(usuarioLogeado.perfil, PERFIL_ADMINISTRATIVO) == 0;
    int esAdministrador = strcmp(usuarioLogeado.perfil, PERFIL_ADMINISTRADOR) == 0;
    int esProfesional = strcmp(usuarioLogeado.perfil, PERFIL_PROFESIONAL) == 0;

    if(esProfesional) {
        menuIndexes->muestraPacienteIndex = 1;
        menuIndexes->mostrarPracticas = 2;
        menuIndexes->mostrarIngresosConPracticasXPaciente = 3;
        menuIndexes->cargarResultadoPractica = 4;
        menuIndexes->salir = 5;
        menuIndexes->altaPacienteIndex = NULL;
        menuIndexes->altaPracticasXIngresoXPaciente = NULL;
        menuIndexes->darDeBajaPacienteIndex = NULL;
        menuIndexes->modificaPacienteIndex = NULL;
        menuIndexes->mostrarListaEmpleado = NULL;
        menuIndexes->eliminarEmpleado = NULL;
        menuIndexes->darDeBajaPractica = NULL;
        menuIndexes->mostrarIngresos  = NULL;
        menuIndexes->eliminarIngreso = NULL;
    } else if(esAdministrativo) {
        menuIndexes->altaPacienteIndex = 1;
        menuIndexes->muestraPacienteIndex = 2;
        menuIndexes->modificaPacienteIndex = 3;
        menuIndexes->darDeBajaPacienteIndex = 4;
        menuIndexes->altaPracticasXIngresoXPaciente = 5;
        menuIndexes->mostrarIngresosConPracticasXPaciente = 6;
        menuIndexes->mostrarPracticas = 7;
        menuIndexes->darDeBajaPractica = 8;
        menuIndexes->mostrarIngresos = 9;
        menuIndexes->eliminarIngreso = 10;
        menuIndexes->salir = 11;
        menuIndexes->cargarResultadoPractica = NULL;
        menuIndexes->eliminarEmpleado = NULL;
        menuIndexes->mostrarListaEmpleado = NULL;
    } else {
        menuIndexes->altaPacienteIndex = 1;
        menuIndexes->muestraPacienteIndex = 2;
        menuIndexes->modificaPacienteIndex = 3;
        menuIndexes->darDeBajaPacienteIndex = 4;
        menuIndexes->altaPracticasXIngresoXPaciente = 5;
        menuIndexes->mostrarIngresosConPracticasXPaciente = 6;
        menuIndexes->mostrarPracticas = 7;
        menuIndexes->cargarResultadoPractica = 8;
        menuIndexes->darDeBajaPractica = 9;
        menuIndexes->mostrarIngresos = 10;
        menuIndexes->eliminarIngreso = 11;
        menuIndexes->eliminarEmpleado = 12;
        menuIndexes->mostrarListaEmpleado = 13;
        menuIndexes->salir = 14;
    }
}

void displayMenu(stEmpleado usuarioLogeado) {
    int esAdministrativo = strcmp(usuarioLogeado.perfil, PERFIL_ADMINISTRATIVO) == 0;
    int esAdministrador = strcmp(usuarioLogeado.perfil, PERFIL_ADMINISTRADOR) == 0;
    int esProfesional = strcmp(usuarioLogeado.perfil, PERFIL_PROFESIONAL) == 0;

    if(esProfesional) {
        displayProfesionalMenu();
    } else if(esAdministrativo) {
        displayAdministrativoMenu();
    } else {
        displayMainMenu();
    }
}

void displayUIPacienteMenu() {
    printf(" Op 1: Nombre y Apellido \n");
    printf(" Op 2: Edad \n");
    printf(" Op 3: Direccion \n");
    printf(" Op 4: Telefono \n");
    printf(" Ingrese campo a modificar: ");
}

void displayLogin() {
    printf("____________________________________________\n\n");
    printf(" Bienvenido. \n");
    printf(" 1- Iniciar Sesion\n");
    printf(" 2- Registrarse\n");
    printf("____________________________________________\n\n");
}






