#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "archivos.h"

/// Carga el Arbol de listas de listas
ArbolPacientes* cargarPacientes(ArbolPacientes* arbolPacientes, FILE* archPacientes) {
    stPaciente paciente;
    while(fread(&paciente, sizeof(stPaciente), 1, archPacientes) > 0) {
        arbolPacientes = insertarArbol(arbolPacientes, paciente);
    }
    return arbolPacientes;
}

void cargarArbolConIngresos(ArbolPacientes* arbolPacientes, FILE* arch) {
    stIngresos ingreso;
    while(fread(&ingreso, sizeof(stIngresos), 1, arch) > 0) {
        ArbolPacientes* encontrado = buscarPacientePorDNI(arbolPacientes, ingreso.dniPaciente);
        if(encontrado) {
            encontrado->listaIngresos = insertarIngresoAlPcipio(encontrado->listaIngresos , ingreso);
        }
    }
}

void cargarArbolConPracticasDeIngreso(ArbolPacientes* arbolPacientes, FILE* arch) {
    stPractXIngreso practXIngreso;
    while(fread(&practXIngreso, sizeof(stPractXIngreso), 1, arch) > 0) {
        mostrarPracticaPorIngreso(practXIngreso);
        ArbolPacientes* pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, practXIngreso.dniPaciente);
        if(pacienteEncontrado) {
            nodoIngreso* ingresoEncontrado = buscarIngresoPorNro(pacienteEncontrado->listaIngresos, practXIngreso.nroIngreso);
            if(ingresoEncontrado) {
                ingresoEncontrado->listaPracticas = insertarPracticaXIngresoPcipio(ingresoEncontrado->listaPracticas, practXIngreso);
            }
        }
    }
}

ArbolPacientes* cargarADLDL(ArbolPacientes* arbolPacientes, FILE* archPacientes, FILE* archIngresos, FILE* archPracticasPorIngresos) {
    arbolPacientes = cargarPacientes(arbolPacientes, archPacientes);
    cargarArbolConIngresos(arbolPacientes, archIngresos);
    cargarArbolConPracticasDeIngreso(arbolPacientes, archPracticasPorIngresos);
    return arbolPacientes;
}

/// Guarda el Arbol de listas de listas
void guardarPaciente(stPaciente paciente, FILE* arch) {
    fwrite(&paciente, sizeof(stPaciente), 1, arch);
}

void guardarPracticasPorIngreso(nodoPractXIngreso* listaPracticasXIngreso, FILE* arch) {
    nodoPractXIngreso* seg = listaPracticasXIngreso;
    while(seg) {
        fwrite(&(seg->practXIngreso), sizeof(stPractXIngreso), 1, arch);
        seg = seg->siguiente;
    }
}

void guardarIngresosYPracticas(nodoIngreso* listaIngresos, FILE* archIngresos, FILE* archPracticas) {
    nodoIngreso* seg = listaIngresos;
    while(seg) {
        fwrite(&(seg->ingreso), sizeof(stIngresos), 1, archIngresos);
        guardarPracticasPorIngreso(seg->listaPracticas, archPracticas);
        seg = seg->siguiente;
    }
}

void guardarADLDL(ArbolPacientes* arbolPacientes, FILE* archPacientes, FILE* archIngresos, FILE* archPracticasXIngresos) {
    if(arbolPacientes) {
        guardarPaciente(arbolPacientes->paciente, archPacientes);
        guardarIngresosYPracticas(arbolPacientes->listaIngresos, archIngresos, archPracticasXIngresos);
        guardarADLDL(arbolPacientes->izq, archPacientes, archIngresos, archPracticasXIngresos);
        guardarADLDL(arbolPacientes->der, archPacientes, archIngresos, archPracticasXIngresos);
    }
}

/// Carga la lista de practicas
nodoPracticas* cargarPracticas(nodoPracticas* listaPracticas, FILE* arch) {
    stPracticas practica;
    while(fread(&practica, sizeof(stPracticas), 1, arch) > 0) {
        listaPracticas = insertarPracticaPcipio(listaPracticas, practica);
    }
    return listaPracticas;
}

/// Guarda la lista de practicas
void guardarPracticas(nodoPracticas* listaPracticas, FILE* arch) {
    nodoPracticas* seg = listaPracticas;
    while(seg) {
        fwrite(&(seg->practica), sizeof(stPracticas), 1, arch);
        seg = seg->siguiente;
    }
}

/// Carga la lista de empleados
nodoEmpleado * cargarListaDeArchivoEmpleados (FILE * archivoEmpleado, nodoEmpleado * listaEmpleados)
{
    stEmpleado empleado;
    while(fread(&empleado, sizeof(stEmpleado), 1, archivoEmpleado) > 0)
    {
        listaEmpleados = insertarEmpleadoAlPcipio(listaEmpleados, empleado);
    }
    return listaEmpleados;
}
/// Guarda la lista de empleados
void guardarEmpleadosEnArchivo(FILE* archivoEmpleados, nodoEmpleado * listaEmpleados)
{
    nodoEmpleado* seg = listaEmpleados;
    while(seg)
    {
        fwrite(&(seg->empleado), sizeof(stEmpleado), 1, archivoEmpleados);
        seg = seg->siguiente;
    }
}














