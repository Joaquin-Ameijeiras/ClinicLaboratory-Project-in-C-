#ifndef LISTA_PRACTICAS_POR_INGRESO_H_INCLUDED
#define LISTA_PRACTICAS_POR_INGRESO_H_INCLUDED

typedef struct {
    int nroIngreso;
    int nroPractica;
    char resultado[40];
} stPractXIngreso;

typedef struct {
    stPractXIngreso practXIngreso;
    struct nodoPractXIngreso* siguiente;
} nodoPractXIngreso;

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
// void            guardarIngresos(FILE*, nodoIngreso*);
nodoIngreso*        cargarListaIngresosDeArchivo(FILE*, nodoIngreso*);
int                 nroUltimoIngreso(nodoIngreso*);
void                mostrarIngreso(stIngresos);
void                mostrarIngresos(nodoIngreso*);

/// TDA Practicas por ingresos
nodoPractXIngreso*  inicListaPracticasXIngresos();
nodoPractXIngreso*  crearNodoPracticaXIngreso(stPractXIngreso);
nodoPractXIngreso*  insertarPracticaXIngresoPcipio(nodoPractXIngreso*, stPractXIngreso);



#endif // LISTA_PRACTICAS_POR_INGRESO_H_INCLUDED
