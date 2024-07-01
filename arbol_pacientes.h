#ifndef ARBOL_PACIENTES_H_INCLUDED
#define ARBOL_PACIENTES_H_INCLUDED

#include "lista_practicas_por_ingreso.h"

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
void                muestraPaciente(stPaciente);
void                guardarPacientes(FILE*, ArbolPacientes*);
ArbolPacientes*     cargarArboldeArchPacientes(FILE*, ArbolPacientes*);
ArbolPacientes*     buscarPacientePorDNI(ArbolPacientes*, int);
int                 pideCampoAModificar();
ArbolPacientes*     modificarPaciente(ArbolPacientes*);


#endif // ARBOL_PACIENTES_H_INCLUDED
