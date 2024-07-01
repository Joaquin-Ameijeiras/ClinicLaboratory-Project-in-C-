#include <stdio.h>
#include <stdlib.h>
#include "gui.h"

void displayMainMenu() {
        system("cls");
        printf("\n________________________________________________________________\n\n");
        printf(" MENU\n\n");
        printf(" 0- Persistir datos y finalizar (no cerrar consola) \n\n");
        printf("------------------PACIENTES------------------- \n\n");
        printf(" 1- Alta de paciente \n");
        printf(" 2- Mostrar pacientes \n");
        printf(" 3- Modificar datos del paciente \n");
        printf(" 4- Dar de baja paciente (TODO) \n");
        printf("\n-------PRACTICAS x INGRESOS x PACIENTES------- \n\n");
        printf(" 5- Ingrese practicas x ingreso x paciente \n");
        printf(" 6- Mostrar ingresos con practicas del paciente \n");
        printf(" 7- Mostrar practicas \n");
        printf("\n________________________________________________________________\n\n");
        printf(" Eleccion: ");
}

void displayPacienteMenu() {
    printf(" Op 1: Nombre y Apellido \n");
    printf(" Op 2: Edad \n");
    printf(" Op 3: Direccion \n");
    printf(" Op 4: Telefono \n");
    printf(" Ingrese campo a modificar: ");
}














