#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tda_arbol_pacientes.h"

/// Commons (TDA) ///
ArbolPacientes* inicializarArbol() {
    return NULL;
}

ArbolPacientes* crearNodoArbolPacientes(stPaciente paciente) {
    ArbolPacientes* nuevoNodo = (ArbolPacientes*)malloc(sizeof(ArbolPacientes));
    // carga datos paciente
    nuevoNodo->paciente.eliminado = paciente.eliminado;
    nuevoNodo->paciente.dni = paciente.dni;
    nuevoNodo->paciente.edad = paciente.edad;
    strcpy(nuevoNodo->paciente.apellidoYNombre, paciente.apellidoYNombre);
    strcpy(nuevoNodo->paciente.direccion, paciente.direccion);
    strcpy(nuevoNodo->paciente.telefono, paciente.telefono);
    nuevoNodo->listaIngresos = NULL;
    // inicializa punteros
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;
    return nuevoNodo;
}

ArbolPacientes* insertarArbol(ArbolPacientes* arbolPacientes, stPaciente nuevoPaciente) {
    if(!arbolPacientes) {
        arbolPacientes = crearNodoArbolPacientes(nuevoPaciente);
    } else {
        if(nuevoPaciente.dni > arbolPacientes->paciente.dni) {
            arbolPacientes->der = insertarArbol(arbolPacientes->der, nuevoPaciente);
        } else {
            arbolPacientes->izq = insertarArbol(arbolPacientes->izq, nuevoPaciente);
        }
    }
    return arbolPacientes;
}

void muestraArbol(ArbolPacientes* arbolPacientes) {
    if(arbolPacientes) {
        muestraPaciente(arbolPacientes->paciente);
        muestraArbol(arbolPacientes->izq);
        muestraArbol(arbolPacientes->der);
    }
}

void muestraArbolNoEliminados(ArbolPacientes* arbolPacientes) {
    if(arbolPacientes) {
        if(arbolPacientes->paciente.eliminado != 1) {
            muestraPaciente(arbolPacientes->paciente);
        }
        muestraArbolNoEliminados(arbolPacientes->izq);
        muestraArbolNoEliminados(arbolPacientes->der);
    }
}

void guardarPacientes(FILE* arch, ArbolPacientes* arbolPacientes) {
    if(arbolPacientes) {
        fwrite(&(arbolPacientes->paciente), sizeof(stPaciente), 1, arch);
        guardarPacientes(arch, arbolPacientes->izq);
        guardarPacientes(arch, arbolPacientes->der);
    }
}

ArbolPacientes* cargarArboldeArchPacientes(FILE* arch, ArbolPacientes* arbolPacientes) {
    stPaciente paciente;
    while(fread(&paciente, sizeof(stPaciente), 1, arch) > 0) {
        arbolPacientes = insertarArbol(arbolPacientes, paciente);
    }
    return arbolPacientes;
}

ArbolPacientes* buscarPacientePorDNI(ArbolPacientes* arbolPacientes, int dniABuscar) {
    ArbolPacientes* encontrado = inicializarArbol();
    if(arbolPacientes) {
        if(arbolPacientes->paciente.dni == dniABuscar) {
            encontrado = arbolPacientes;
        } else {
            if(arbolPacientes->paciente.dni > dniABuscar) {
                encontrado = buscarPacientePorDNI(arbolPacientes->izq, dniABuscar);
            } else {
                encontrado = buscarPacientePorDNI(arbolPacientes->der, dniABuscar);
            }
        }
    }
    return encontrado;
}


/// Funciones Asociadas ///
stPaciente cargarNuevoPaciente() {
    stPaciente nuevoPaciente;
    nuevoPaciente.eliminado = 0;
    printf(" CARGA PACIENTE \n");
    printf(" Ingrese DNI: ");
    scanf("%i", &nuevoPaciente.dni);
    printf(" Ingrese Nombre y Apellido: ");
    fflush(stdin);
    gets(nuevoPaciente.apellidoYNombre);
    printf(" Ingrese Edad: ");
    scanf("%i", &nuevoPaciente.edad);
    printf(" Ingrese Direccion: ");
    fflush(stdin);
    gets(nuevoPaciente.direccion);
    printf(" Ingrese Telefono: ");
    fflush(stdin);
    gets(nuevoPaciente.telefono);
    return nuevoPaciente;
}

ArbolPacientes* altaDePaciente(ArbolPacientes* arbolPacientes) {
    char letra = 'p';
    stPaciente nuevoPaciente = cargarNuevoPaciente();
    ArbolPacientes* encontrar = buscarPacientePorDNI(arbolPacientes, nuevoPaciente.dni);
    if(encontrar == NULL) {
        arbolPacientes = insertarArbol(arbolPacientes, nuevoPaciente);
    } else {
        printf("\n El DNI ingresado ya se encuentra en el sistema.");
        if(encontrar->paciente.eliminado == 1) {
            printf(" Este paciente fue dado de baja ¿Desea darlo de alta? (S/N): ");
            fflush(stdin);
            scanf("%c", &letra);
            while(letra != 's' && letra != 'S' && letra != 'n' && letra != 'N' ) {
                printf(" Si desea o no darlo de alta ingrese S/N: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
            if(letra == 's' || letra == 'S') {
                encontrar->paciente.eliminado = 0;
                printf(" \nSe ha dado de alta correctamente.\n");
            }
        }
    }

    return arbolPacientes;
}

void muestraPaciente(stPaciente paciente) {
    printf("\n DNI: %i, NyA: %s, Edad: %i, Direc: %s, Telefono: %s, Eliminado: %d\n",
        paciente.dni,
        paciente.apellidoYNombre,
        paciente.edad,
        paciente.direccion,
        paciente.telefono,
        paciente.eliminado);
}

int pideCampoAModificar() {
    int opcion = 0;
    displayUIPacienteMenu();
    scanf("%i", &opcion);
    return opcion;
}

ArbolPacientes* modificarPaciente(ArbolPacientes* arbolPacientes) {
    int dniABuscar;
    char salir = 'n';
    printf("\n Ingrese DNI de paciente a buscar: ");
    scanf("%i", &dniABuscar);
    ArbolPacientes* pacienteEncontrado = buscarPacientePorDNI(arbolPacientes, dniABuscar);
    if(pacienteEncontrado) {
        muestraPaciente(pacienteEncontrado->paciente);
        do {
            printf("\n");
            int campoAModificar = pideCampoAModificar();
            switch(campoAModificar) {
                case 1: fflush(stdin);
                printf("\n Nombre: ");
                gets(pacienteEncontrado->paciente.apellidoYNombre);
                printf("\n Se modifico correctamente.");
                break;

                case 2: printf("\n Edad: ");
                scanf("%i", &(pacienteEncontrado->paciente.edad));
                printf("\n Se modifico correctamente.");
                break;

                case 3: printf("\n Direccion: ");
                fflush(stdin);
                gets(pacienteEncontrado->paciente.direccion);
                printf("\n Se modifico correctamente.");
                break;

                case 4: printf("\n Telefono: ");
                fflush(stdin);
                gets(pacienteEncontrado->paciente.telefono);
                printf("\n Se modifico correctamente.");
                break;

                default: printf("\n Este campo no existe. Reintentelo");
                break;
            }

            printf("\n Salir (S/N): ");
            fflush(stdin);
            scanf("%c", &salir);
        }while(salir == 'n' || salir == 'N');
    } else {
        printf(" Lo sentimos, el paciente no pudo ser encontrado \n");
    }

    return pacienteEncontrado;
}

void darDeBajaPaciente(ArbolPacientes* arbolPacientes) {
    int dni;
    ArbolPacientes* seg = arbolPacientes;
    printf(" Ingrese DNI: ");
    scanf("%d", &dni);
    seg = buscarPacientePorDNI(arbolPacientes, dni);
    if(seg) {
        if(seg->paciente.eliminado != 1) {
            seg->paciente.eliminado = 1;
            printf(" \n\n Se ha dado de baja correctamente.\n");
        } else { printf(" El paciente ya se encuentra dado de baja.\n"); }
    } else { printf(" No se encontro al paciente.\n"); }
}

void mostrarIngresosSegunPaciente(ArbolPacientes* arbolPacientes) {
    int dni;
    printf(" Ingrese DNI del paciente: ");
    scanf("%d", &dni);
    ArbolPacientes* encontrar = buscarPacientePorDNI(arbolPacientes, dni);
    if(encontrar) {
        mostrarIngresos(encontrar->listaIngresos);
    }
}

void mostrarIngresosSegunPacienteSinEliminados(ArbolPacientes* arbolPacientes) {
    int dni;
    printf(" Ingrese DNI del paciente: ");
    scanf("%d", &dni);
    ArbolPacientes* encontrar = buscarPacientePorDNI(arbolPacientes, dni);
    if(encontrar) {
        mostrarIngresosSinEliminados(encontrar->listaIngresos);
    }
}

void eliminarIngreso(ArbolPacientes* arbolPacientes) {
    int nro, flag = 0, dni;
    printf(" Ingrese DNI del paciente: ");
    scanf("%d", &dni);
    ArbolPacientes* encontrar = buscarPacientePorDNI(arbolPacientes, dni);
    if(encontrar) {
        printf(" Ingreso a eliminar. Ingrese su numero: ");
        scanf("%d", &nro);
        nodoIngreso* seg = encontrar->listaIngresos;
        while(seg) {
            if(seg->ingreso.nroIngreso == nro) {
                seg->ingreso.eliminado = 1;
                printf(" \nSe ha eliminado correctamente.\n");
                flag = 1;
            }
            seg = seg->siguiente;
        }
        if(flag == 0) {
            printf(" No se ha encontrado respectivo ingreso.\n");
        }
    } else { printf(" No se ha encontrado al paciente.\n");}
}











