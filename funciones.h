#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "tda_arbol_pacientes.h"
#include "tda_lista_practicas.h"
#include "tda_lista_practicas_por_ingreso.h"
#include "tda_lista_ingresos.h"
#include "tda_lista_empleados.h"

/// Funciones Asociadas ///

// Funciones del administrativo
ArbolPacientes*     altaDePracticaPorIngresoPorPaciente(ArbolPacientes*, nodoPracticas**);
void                mostrarPracticasPorIngresosPorPaciente();

// Funciones del profesional/administrativo
void                cargarResultadoPractica();
void                mostrarPracticasPorIngresosPorPacienteNoEliminados(ArbolPacientes* arbolPacientes, nodoPracticas* listaPracticas);

#endif // FUNCIONES_H_INCLUDED
