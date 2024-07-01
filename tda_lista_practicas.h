#ifndef TDA_LISTA_PRACTICAS_H_INCLUDED
#define TDA_LISTA_PRACTICAS_H_INCLUDED

typedef struct {
    int nroPractica;
    char nombre[30];
    int eliminado;
} stPracticas;

typedef struct {
    stPracticas practica;
    struct nodoPracticas* siguiente;
} nodoPracticas;

stPracticas     cargarNuevaPractica();
nodoPracticas*  inicListaPracticas();
nodoPracticas*  crearNodoPractica(stPracticas);
nodoPracticas*  insertarPracticaPcipio(nodoPracticas*, stPracticas);
void            mostrarPractica(stPracticas);
void            mostrarPracticas(nodoPracticas*);
nodoPracticas*  buscarPracticaPorNro(nodoPracticas*, int);
int             nroUltimoPractica(nodoPracticas* practicas);
void            eliminarPractica(nodoPracticas* listaPracticas);
void            mostrarPracticasSinEliminado(nodoPracticas* listaPracticas);

#endif // TDA_LISTA_PRACTICAS_H_INCLUDED
