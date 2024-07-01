#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "funciones.h"

/// Funciones de carga de archivos
ArbolPacientes*     cargarPacientes(ArbolPacientes*, FILE*);
void                cargarArbolConIngresos(ArbolPacientes*, FILE*);
ArbolPacientes*     cargarADLDL(ArbolPacientes*, FILE*, FILE*, FILE*);
nodoPracticas*      cargarPracticas(nodoPracticas*, FILE*);
nodoEmpleado *      cargarListaDeArchivoEmpleados (FILE * archivoEmpleado, nodoEmpleado * listaEmpleados);

/// Funciones de guardar en archivos
void                guardarPaciente(stPaciente, FILE*);
void                guardarPracticasPorIngreso(nodoPractXIngreso*, FILE*);
void                guardarIngresosYPracticas(nodoIngreso*, FILE*, FILE*);
void                guardarADLDL(ArbolPacientes*, FILE*, FILE*, FILE*);
void                guardarPracticas(nodoPracticas*, FILE*);
void                guardarEmpleadosEnArchivo(FILE* archivoEmpleados, nodoEmpleado * listaEmpleados);


#endif // ARCHIVOS_H_INCLUDED
