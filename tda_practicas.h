#ifndef TDA_PRACTICAS_H_INCLUDED
#define TDA_PRACTICAS_H_INCLUDED

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

#endif // TDA_PRACTICAS_H_INCLUDED



