#ifndef TDA_ARBOL_PACIENTES_H_INCLUDED
#define TDA_ARBOL_PACIENTES_H_INCLUDED

#include "tda_lista_ingresos.h"

typedef struct {
    char apellidoYNombre[40];
    int edad;
    int dni;
    char direccion[30];
    char telefono[15];
    int eliminado;
} stPaciente;

typedef struct {
    stPaciente paciente;
    struct ArbolPacientes * izq;
    struct ArbolPacientes * der;
    nodoIngreso* listaIngresos;
} ArbolPacientes;

// TDA Arboles
ArbolPacientes*     inicializarArbol();
ArbolPacientes*     crearNodoArbolPacientes(stPaciente);
ArbolPacientes*     insertarArbol(ArbolPacientes*, stPaciente);

// Funciones Asociadas
stPaciente          cargarNuevoPaciente();
ArbolPacientes*     altaDePaciente(ArbolPacientes*);
ArbolPacientes*     buscarPacientePorDNI(ArbolPacientes*, int);
void                muestraPaciente(stPaciente);
int                 pideCampoAModificar();
ArbolPacientes*     modificarPaciente(ArbolPacientes*);
void                mostrarIngresosSegunPaciente(ArbolPacientes* arbolPacientes);
void                darDeBajaPaciente(ArbolPacientes* arbolPacientes);
void                eliminarIngreso(ArbolPacientes* arbolPacientes);
void                muestraArbol(ArbolPacientes*);
void                muestraArbolNoEliminados(ArbolPacientes*);
void                mostrarIngresosSegunPacienteSinEliminados(ArbolPacientes* arbolPacientes);


#endif // TDA_ARBOL_PACIENTES_H_INCLUDED
