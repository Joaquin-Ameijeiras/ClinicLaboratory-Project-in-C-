#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tda_lista_ingresos.h"

/// TDA Ingresos

stIngresos cargarNuevoIngreso() {
    stIngresos nuevoIngreso;
    nuevoIngreso.eliminado = 0;
    printf("\n Cargue el ingreso \n\n");
    printf(" Fecha Ingreso: ");
    fflush(stdin);
    gets(nuevoIngreso.fechaIngreso);
    printf(" Fecha Retiro:");
    fflush(stdin);
    gets(nuevoIngreso.fechaRetiro);
    printf(" Matricula del profesional: \n");
    scanf("%i", &nuevoIngreso.matriculaProfesional);
    return nuevoIngreso;
}

nodoIngreso* inicListaIngresos() {
    return NULL;
}

nodoIngreso* crearNodoIngreso(stIngresos nuevoIngreso) {
    nodoIngreso* nuevoNodo = (nodoIngreso*)malloc(sizeof(nodoIngreso));
    // inicializa datos
    nuevoNodo->ingreso.nroIngreso = nuevoIngreso.nroIngreso;
    nuevoNodo->ingreso.eliminado = nuevoIngreso.eliminado;
    nuevoNodo->ingreso.dniPaciente = nuevoIngreso.dniPaciente;
    nuevoNodo->ingreso.matriculaProfesional = nuevoIngreso.matriculaProfesional;
    strcpy(nuevoNodo->ingreso.fechaIngreso, nuevoIngreso.fechaIngreso);
    strcpy(nuevoNodo->ingreso.fechaRetiro, nuevoIngreso.fechaRetiro);
    // inicializa punteros
    nuevoNodo->listaPracticas = NULL;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

nodoIngreso* insertarIngresoAlPcipio(nodoIngreso* listaIngresos, stIngresos nuevoIngreso) {
    nodoIngreso* nuevoNodo = crearNodoIngreso(nuevoIngreso);
    if(listaIngresos != NULL) {
        nuevoNodo->siguiente = listaIngresos;
    }
    listaIngresos = nuevoNodo;
    return listaIngresos;
}

nodoIngreso* buscarIngresoPorNro(nodoIngreso* listaIngresos, int nroIngresoABuscar) {
    nodoIngreso* seg = listaIngresos;
    while((seg != NULL) && (seg->ingreso.nroIngreso != nroIngresoABuscar)) {
        seg = seg->siguiente;
    }
    return seg;
}

//probar
nodoIngreso* cargarListaIngresosDeArchivo(FILE* arch, nodoIngreso* listaIngreso) {
    stIngresos copy;
    while(fread(&copy, sizeof(stIngresos), 1, arch) > 0) {
        listaIngreso = insertarIngresoAlPcipio(listaIngreso, copy);
    }
    return listaIngreso;
}

int nroUltimoIngreso(nodoIngreso* listaIngresos) {
    int nroIngreso = 0;
    nodoIngreso* seg = listaIngresos;
    if(seg) {
        nroIngreso = seg->ingreso.nroIngreso;
    }else {
        printf(" No hay ingresos cargados\n");
    }

    return nroIngreso;
}

void mostrarIngreso(stIngresos ingreso) {
    printf(" Ingreso Nro: %i | Fecha ingreso: %s | Fecha retiro: %s | Matricula profesional: %i | Eliminado: %d\n",
           ingreso.nroIngreso,
           ingreso.fechaIngreso,
           ingreso.fechaRetiro,
           ingreso.matriculaProfesional,
           ingreso.eliminado
    );
}

void mostrarIngresos(nodoIngreso* listaIngresos) {
    nodoIngreso* seg = listaIngresos;
    printf(" Ingresos \n");
    while(seg) {
        mostrarIngreso(seg->ingreso);
        seg = seg->siguiente;
    }
}

void mostrarIngresosSinEliminados(nodoIngreso* listaIngresos) {
    nodoIngreso* seg = listaIngresos;
    printf(" Ingresos \n");
    while(seg) {
        if(seg->ingreso.eliminado != 1) {
            mostrarIngreso(seg->ingreso);
        }
        seg = seg->siguiente;
    }
}






