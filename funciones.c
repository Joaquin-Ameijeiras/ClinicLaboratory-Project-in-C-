#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "funciones.h"

/// Funciones Asociadas ///

/// Practicas por Ingresos por Paciente
ArbolPacientes* altaDePracticaPorIngresoPorPaciente(ArbolPacientes* arbolPacientes, nodoPracticas** listaPracticas) {
    /// Busca si ya esta registrado el paciente, si no, lo agrega
    int dniPaciente;
    printf(" Ingrese DNI del paciente: ");
    scanf("%i", &dniPaciente);
    ArbolPacientes* pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, dniPaciente);
    if(!pacienteEncontrado) {
        printf(" El paciente no se encuentra registrado en el sistema \n");
        printf(" Ingrese datos para dar el alta al mismo \n");
        arbolPacientes = altaDePaciente(arbolPacientes);
        pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, dniPaciente);
    }

    muestraPaciente(pacienteEncontrado->paciente);
    printf("\n");

    mostrarIngresos(pacienteEncontrado->listaIngresos);
    printf("\n");

    /// Busca si ya existe un ingreso, si no, lo agrega
    int nroIngreso;
    printf(" Ingrese numero de ingreso:");
    scanf("%i", &nroIngreso);
    printf("\n");
    nodoIngreso* ingresoEncontrado = buscarIngresoPorNro(pacienteEncontrado->listaIngresos, nroIngreso);

    if(!ingresoEncontrado) {
        stIngresos nuevoIngreso;
        nuevoIngreso = cargarNuevoIngreso();
        nuevoIngreso.nroIngreso = nroUltimoIngreso(pacienteEncontrado->listaIngresos) + 1;
        nuevoIngreso.dniPaciente = pacienteEncontrado->paciente.dni;

        pacienteEncontrado->listaIngresos = insertarIngresoAlPcipio(pacienteEncontrado->listaIngresos, nuevoIngreso);
    }

    /// Agrega practicas hasta que lo desee
    printf(" Ingrese practicas \n");
    char opcion = 's';
    do {
        // pide datos practica
        stPracticas nuevaPractica = cargarNuevaPractica();
        nuevaPractica.nroPractica = nroUltimoPractica(*listaPracticas) + 1;
        // agrega nueva practica
        *listaPracticas = insertarPracticaPcipio(*listaPracticas, nuevaPractica);
         //agrega practica por ingreso
        stPractXIngreso nuevaPracticaXIngreso;
        if(ingresoEncontrado) {
            nuevaPracticaXIngreso.dniPaciente = ingresoEncontrado->ingreso.dniPaciente;
            nuevaPracticaXIngreso.nroPractica = nuevaPractica.nroPractica;
            nuevaPracticaXIngreso.nroIngreso = ingresoEncontrado->ingreso.nroIngreso;
            strcpy(nuevaPracticaXIngreso.resultado, " Sin resultado");
            ingresoEncontrado->listaPracticas = insertarPracticaXIngresoPcipio(ingresoEncontrado->listaPracticas, nuevaPracticaXIngreso);
        }else {
            nuevaPracticaXIngreso.dniPaciente = pacienteEncontrado->listaIngresos->ingreso.dniPaciente;
            nuevaPracticaXIngreso.nroPractica = nuevaPractica.nroPractica;
            nuevaPracticaXIngreso.nroIngreso = pacienteEncontrado->listaIngresos->ingreso.nroIngreso;
            strcpy(nuevaPracticaXIngreso.resultado, " Sin resultado");
            pacienteEncontrado->listaIngresos->listaPracticas = insertarPracticaXIngresoPcipio(pacienteEncontrado->listaIngresos->listaPracticas, nuevaPracticaXIngreso);
        }
        mostrarPracticaPorIngreso(nuevaPracticaXIngreso);
        // pregunta si desea seguir cargando
        printf(" Desea seguir cargando practicas? [s/n] \n");
        scanf("%c", &opcion);
    } while(opcion == 's');

    return arbolPacientes;
}

void mostrarPracticasPorIngresosPorPaciente(ArbolPacientes* arbolPacientes, nodoPracticas* listaPracticas) {
    int dniPaciente;
    printf(" Ingrese DNI del paciente: ");
    scanf("%i", &dniPaciente);
    ArbolPacientes* pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, dniPaciente);

    if(!pacienteEncontrado) {
        printf(" El paciente no se encuentra registrado en el sistema \n");
        return 1;
    }

    nodoIngreso* segIngresos = pacienteEncontrado->listaIngresos;

    while(segIngresos) {
        mostrarIngreso(segIngresos->ingreso);
        printf("\n");
        nodoPractXIngreso* segPracticas = segIngresos->listaPracticas;
        while(segPracticas) {
            nodoPracticas* practicaEncontrada = buscarPracticaPorNro(listaPracticas, segPracticas->practXIngreso.nroPractica);
            mostrarPractica(practicaEncontrada->practica);
            mostrarPracticaPorIngreso(segPracticas->practXIngreso);
            segPracticas = segPracticas->siguiente;
            printf("\n");
        }
        segIngresos = segIngresos->siguiente;
    }
}

void mostrarPracticasPorIngresosPorPacienteNoEliminados(ArbolPacientes* arbolPacientes, nodoPracticas* listaPracticas) {
    int dniPaciente;
    printf(" Ingrese DNI del paciente: ");
    scanf("%i", &dniPaciente);
    ArbolPacientes* pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, dniPaciente);

    if(!pacienteEncontrado) {
        printf(" El paciente no se encuentra registrado en el sistema \n");
        return 1;
    }

    nodoIngreso* segIngresos = pacienteEncontrado->listaIngresos;

    while(segIngresos) {
        printf("\n");
        if(segIngresos->ingreso.eliminado != 1) {
            mostrarIngreso(segIngresos->ingreso);
            printf("\n");
            nodoPractXIngreso* segPracticas = segIngresos->listaPracticas;
            while(segPracticas) {
                nodoPracticas* practicaEncontrada = buscarPracticaPorNro(listaPracticas, segPracticas->practXIngreso.nroPractica);
                if(practicaEncontrada->practica.eliminado != 1) {
                    mostrarPractica(practicaEncontrada->practica);
                    mostrarPracticaPorIngreso(segPracticas->practXIngreso);
                }
                segPracticas = segPracticas->siguiente;
                printf("\n");
            }
        }

        segIngresos = segIngresos->siguiente;
    }
}

void cargarResultadoPractica(ArbolPacientes* arbolPacientes, nodoPracticas* listaPracticas) {
    int dniPaciente;
    printf(" Ingrese DNI del paciente: ");
    scanf("%i", &dniPaciente);

    ArbolPacientes* pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, dniPaciente);

    if(!pacienteEncontrado) {
        printf(" El paciente no se encuentra registrado en el sistema \n");
        return 1;
    }

    muestraPaciente(pacienteEncontrado->paciente);

    nodoIngreso* segIngresos = pacienteEncontrado->listaIngresos;
    printf("\n");

    int nroPracticaABuscar;
    printf(" Cargar numero de practica: ");
    scanf("%i", &nroPracticaABuscar);

    int practicaEncontrada = false;

    while((segIngresos != NULL) && (!practicaEncontrada)) {
        nodoPractXIngreso* segPracticas = segIngresos->listaPracticas;
        while((segPracticas != NULL) && (!practicaEncontrada)) {
            if((segPracticas->practXIngreso.nroPractica == nroPracticaABuscar)) {
                // muestra detalle de practica
                nodoPracticas* practicaEncontrada = buscarPracticaPorNro(listaPracticas, nroPracticaABuscar);
                mostrarPractica(practicaEncontrada->practica);
                // pide ingresar resultado
                printf(" Ingrese resultado de practica: ");
                fflush(stdin);
                gets(segPracticas->practXIngreso.resultado);
                // actualiza flag para parar de buscar
                practicaEncontrada = true;
            }
            segPracticas = segPracticas->siguiente;
        }
        segIngresos = segIngresos->siguiente;
    }
}


