#ifndef TDA_LISTA_PRACTICAS_POR_INGRESO_H_INCLUDED
#define TDA_LISTA_PRACTICAS_POR_INGRESO_H_INCLUDED

typedef struct {
    int nroIngreso;
    int nroPractica;
    int dniPaciente;
    char resultado[40];
} stPractXIngreso;

typedef struct {
    stPractXIngreso practXIngreso;
    struct nodoPractXIngreso* siguiente;
} nodoPractXIngreso;

/// TDA Practicas por ingresos

nodoPractXIngreso*  inicListaPracticasXIngresos();
nodoPractXIngreso*  crearNodoPracticaXIngreso(stPractXIngreso);
nodoPractXIngreso*  insertarPracticaXIngresoPcipio(nodoPractXIngreso*, stPractXIngreso);
void                mostrarPracticaPorIngreso(stPractXIngreso);
void                mostrarPracticasPorIngreso(nodoPractXIngreso*);

#endif // TDA_LISTA_PRACTICAS_POR_INGRESO_H_INCLUDED
