#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tda_lista_practicas.h"

stPracticas cargarNuevaPractica() {
    stPracticas nuevaPractica;
    nuevaPractica.eliminado = 0;
    printf(" Cargue la practica \n");
    printf(" Descripcion de la practica: ");
    fflush(stdin);
    gets(nuevaPractica.nombre);
    return nuevaPractica;
}

nodoPracticas* inicListaPracticas() {
    return NULL;
}

nodoPracticas* crearNodoPractica(stPracticas nuevaPractica) {
    nodoPracticas* nuevoNodo = (nodoPracticas*)malloc(sizeof(nodoPracticas));
    nuevoNodo->practica.eliminado = nuevaPractica.eliminado;
    nuevoNodo->practica.nroPractica = nuevaPractica.nroPractica;
    strcpy(nuevoNodo->practica.nombre, nuevaPractica.nombre);
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoPracticas* insertarPracticaPcipio(nodoPracticas* listaPracticas, stPracticas nuevaPractica) {
    nodoPracticas* nuevoNodo = crearNodoPractica(nuevaPractica);
    if(listaPracticas) {
        nuevoNodo->siguiente = listaPracticas;
    }
    listaPracticas = nuevoNodo;
    return listaPracticas;
}

void mostrarPractica(stPracticas practica) {
    printf(" Practica nro %i, nombre: %s, eliminado: %d \n",
        practica.nroPractica,
        practica.nombre,
        practica.eliminado);
}

void mostrarPracticas(nodoPracticas* listaPracticas) {
    nodoPracticas* seg = listaPracticas;
    while(seg) {
        mostrarPractica(seg->practica);
        seg = seg->siguiente;
    }
}

void mostrarPracticasSinEliminado(nodoPracticas* listaPracticas) {
    nodoPracticas* seg = listaPracticas;
    while(seg) {
        if(seg->practica.eliminado != 1) {
            mostrarPractica(seg->practica);
        }
        seg = seg->siguiente;
    }
}

nodoPracticas* buscarPracticaPorNro(nodoPracticas* listaPracticas, int nroPractica) {
    nodoPracticas* seg = listaPracticas;
    while((seg != NULL) && (seg->practica.nroPractica != nroPractica)) {
        seg = seg->siguiente;
    }
    return seg;
}

int nroUltimoPractica(nodoPracticas* listaPracticas) {
    int nroPractic = 0;
    nodoPracticas* seg = listaPracticas;
    if(seg) {
        nroPractic = seg->practica.nroPractica;
    }else {
        printf("\n No hay practicas cargadas\n");
    }

    return nroPractic;
}

void eliminarPractica(nodoPracticas* listaPracticas) {
    int nroPractica;
    printf("\n Eliminar Practica\n Nro de Practica: ");
    scanf("%d", &nroPractica);
    nodoPracticas* buscar = buscarPracticaPorNro(listaPracticas, nroPractica);
    if(buscar) {
        buscar->practica.eliminado = 1;
    } else {
        printf(" \nLo siento, no se encontro la practica ingresada\n");
    }

}













