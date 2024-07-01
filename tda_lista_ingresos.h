#ifndef TDA_LISTA_INGRESOS_H_INCLUDED
#define TDA_LISTA_INGRESOS_H_INCLUDED

#include "tda_lista_practicas_por_ingreso.h"

typedef struct {
    int nroIngreso;
    char fechaIngreso[10];
    char fechaRetiro[10];
    int dniPaciente;
    int matriculaProfesional;
    int eliminado;
} stIngresos;

typedef struct {
    stIngresos ingreso;
    struct nodoPractXIngreso* listaPracticas;
    struct nodoIngreso* siguiente;
} nodoIngreso;

/// TDA Ingresos
stIngresos          cargarNuevoIngreso();
nodoIngreso*        inicListaIngresos();
nodoIngreso*        crearNodoIngreso(stIngresos);
nodoIngreso*        insertarIngresoAlPcipio(nodoIngreso*, stIngresos);
nodoIngreso*        buscarIngresoPorNro(nodoIngreso*, int);
stIngresos          copiarIngreso(nodoIngreso*);
nodoIngreso*        cargarListaIngresosDeArchivo(FILE*, nodoIngreso*);
int                 nroUltimoIngreso(nodoIngreso*);
void                mostrarIngreso(stIngresos);
void                mostrarIngresos(nodoIngreso*);
void                mostrarIngresosSinEliminados(nodoIngreso* listaIngresos);

#endif // TDA_LISTA_INGRESOS_H_INCLUDED
