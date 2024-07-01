#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tda_lista_practicas_por_ingreso.h"

/// TDA Practicas por ingresos

nodoPractXIngreso* inicListaPracticasXIngresos() {
    return NULL;
}

nodoPractXIngreso* crearNodoPracticaXIngreso(stPractXIngreso nuevaPracticaXIngreso) {
    nodoPractXIngreso* nuevoNodo = (nodoPractXIngreso*)malloc(sizeof(nodoPractXIngreso));
    nuevoNodo->practXIngreso.nroIngreso = nuevaPracticaXIngreso.nroIngreso;
    nuevoNodo->practXIngreso.nroPractica = nuevaPracticaXIngreso.nroPractica;
    nuevoNodo->practXIngreso.dniPaciente = nuevaPracticaXIngreso.dniPaciente;
    strcpy(nuevoNodo->practXIngreso.resultado, nuevaPracticaXIngreso.resultado);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoPractXIngreso* insertarPracticaXIngresoPcipio(nodoPractXIngreso* listaPracticasXIngresos, stPractXIngreso nuevaPracticaXIngreso) {
    nodoPractXIngreso* nuevoNodo = crearNodoPracticaXIngreso(nuevaPracticaXIngreso);
    if(listaPracticasXIngresos) {
        nuevoNodo->siguiente = listaPracticasXIngresos;
    }
    listaPracticasXIngresos = nuevoNodo;
    return listaPracticasXIngresos;
}

void mostrarPracticaPorIngreso(stPractXIngreso practXIngreso) {
    printf(" Resultado: %s \n", practXIngreso.resultado);
}

void mostrarPracticasPorIngreso(nodoPractXIngreso* listaPractXIngreso) {
    nodoPractXIngreso* seg = listaPractXIngreso;
    while(seg) {
        mostrarPracticaPorIngreso(seg->practXIngreso);
        seg = seg->siguiente;
    }
}





