#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tda_lista_empleados.h"

#define PERFIL_ADMINISTRADOR        "administrador"
#define PERFIL_ADMINISTRATIVO       "administrativo"
#define PERFIL_PROFESIONAL          "profesional"

stEmpleado cargarNuevoEmpleado ()
{
    stEmpleado nuevoEmpleado;
    int validar;

    printf("\n Ingrese su DNI: ");
    scanf("%d", &nuevoEmpleado.dni);

    printf("\n Ingrese su apellido y nombre: ");
    fflush(stdin);
    gets(nuevoEmpleado.apellidoYNombre);

    do
    {
        printf("\n Ingrese su contrasenia: ");
        fflush(stdin);
        gets(nuevoEmpleado.contrasena);

        validar = validarPalabra(nuevoEmpleado.contrasena);
    }
    while(validar == 0);

    do
    {
        printf("\n Ingrese su usuario: ");
        fflush(stdin);
        gets(nuevoEmpleado.usuario);

        validar = validarPalabra(nuevoEmpleado.usuario);
    }
    while(validar == 0);

    do
    {
        printf("\n Ingrese su tipo de acceso(administrador | profesional | administrativo): \n");
        fflush(stdin);
        gets(nuevoEmpleado.perfil);

        validar = validarPalabra(nuevoEmpleado.perfil);

        int esString = validar == 1;

        if(esString) {
            int esAdministrativo = strcmp(nuevoEmpleado.perfil, PERFIL_ADMINISTRATIVO) == 0;
            int esAdministrador = strcmp(nuevoEmpleado.perfil, PERFIL_ADMINISTRADOR) == 0;
            int esProfesional = strcmp(nuevoEmpleado.perfil, PERFIL_PROFESIONAL) == 0;
            if(!esAdministrativo && !esAdministrador && !esProfesional) {
                printf("Perfil no valido. \n");
                validar = 0;
            }
        }
    }
    while(validar == 0);


    return nuevoEmpleado;

}

nodoEmpleado * inicializarListaEmpleados()
{

    return NULL;
}

nodoEmpleado * crearNodoEmpleado (stEmpleado nuevoEmpleado)
{
    nodoEmpleado * nuevoNodo = (nodoEmpleado*)malloc(sizeof(nodoEmpleado));
    strcpy(nuevoNodo->empleado.apellidoYNombre, nuevoEmpleado.apellidoYNombre);
    strcpy(nuevoNodo->empleado.contrasena, nuevoEmpleado.contrasena);
    strcpy(nuevoNodo->empleado.perfil, nuevoEmpleado.perfil);
    strcpy(nuevoNodo->empleado.usuario, nuevoEmpleado.usuario);
    nuevoNodo->empleado.dni = nuevoEmpleado.dni;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

nodoEmpleado * insertarEmpleadoAlPcipio(nodoEmpleado * listaEmpleados, stEmpleado nuevoEmpleado)
{
    nodoEmpleado * nuevoNodo = crearNodoEmpleado(nuevoEmpleado);
    if(listaEmpleados != NULL)
    {
        nuevoNodo->siguiente = listaEmpleados;
    }
    listaEmpleados = nuevoNodo;

    return listaEmpleados;
}

void mostrarListaEmpleados (nodoEmpleado * listaEmpleados)
{
    nodoEmpleado * seg = listaEmpleados;
    if(seg == NULL)
    {
        printf(" La lista no tiene datos\n");
    }

    while(seg != NULL)
    {
        printf(" Nombre: %s\n", seg->empleado.apellidoYNombre);
        printf(" Contrasenia: %s\n", seg->empleado.contrasena);
        printf(" DNI: %d\n", seg->empleado.dni);
        printf(" Tipo de acceso: %s\n", seg->empleado.perfil);
        printf(" Usuario: %s\n\n", seg->empleado.usuario);
        seg = seg->siguiente;
    }
}

nodoEmpleado* registrarEmpleado (nodoEmpleado * listaEmpleados)
{
    FILE * archivoEmpleados;
    stEmpleado nuevoEmpleado;

    archivoEmpleados = fopen("./archivos/empleados.dat", "ab");
    if(archivoEmpleados) {
        nuevoEmpleado = cargarNuevoEmpleado();
        fwrite(&nuevoEmpleado, sizeof(stEmpleado), 1, archivoEmpleados);
        fclose(archivoEmpleados);
    }else { printf(" Error al abrir el archivo de empleados.\n");}


    listaEmpleados = insertarEmpleadoAlPcipio(listaEmpleados, nuevoEmpleado);

    printf(" Usuario creado correctamente.\n\n");
    system("pause");
    system("cls");

    return listaEmpleados;
}

int iniciarSesion(stEmpleado* usuarioLogueado)
{
    int loginExitoso = 0;
    int dni = 0;
    char contrasenia[20];
    stEmpleado empleado;
    int validar;

    printf(" Ingrese su DNI: ");
    scanf("%d", &dni);
    do
    {
        printf(" Ingrese su contrasenia: ");
        fflush(stdin);
        scanf("%s", &contrasenia);
        validar = validarPalabra(contrasenia);
    }
    while(validar == 0);

    FILE * archivoEmpleados = fopen("./archivos/empleados.dat", "rb");
    while (fread(&empleado, sizeof(stEmpleado), 1, archivoEmpleados) > 0)
    {
        if(empleado.dni == dni && strcmpi(empleado.contrasena, contrasenia) == 0)
        {
            usuarioLogueado->dni = dni;
            strcpy(usuarioLogueado->apellidoYNombre, empleado.apellidoYNombre);
            strcpy(usuarioLogueado->contrasena, empleado.contrasena);
            strcpy(usuarioLogueado->perfil, empleado.perfil);
            strcpy(usuarioLogueado->usuario, empleado.usuario);
            loginExitoso = 1;
        }
    }

    return loginExitoso;
}

void mostrarEmpleado (stEmpleado empleadoAMostrar)
{
    printf(" Apellido y nombre: %s\n", empleadoAMostrar.apellidoYNombre);
    printf(" DNI: %d \n", empleadoAMostrar.dni);
    printf(" Ususario: %s \n", empleadoAMostrar.usuario);
    printf(" Contraseña: %s \n", empleadoAMostrar.contrasena);
    printf(" Tipo de acceso: %s \n\n", empleadoAMostrar.perfil);
}

void mostrarEmpleadoEnMenu(stEmpleado empleadoAMostrar) {
    int esAdministrador = strcmp(empleadoAMostrar.perfil, "administrador") == 0;
    void mostrarContrasenia() {
        if(esAdministrador) {
            printf(" Contraseña: %s \n", empleadoAMostrar.contrasena);
        } else {
            printf(" Contraseña: ****** \n");
        }
    }

    printf("\n---------------------------USUARIO---------------------------\n\n");
    printf(" Apellido y nombre: %s\n", empleadoAMostrar.apellidoYNombre);
    printf(" DNI: %d \n", empleadoAMostrar.dni);
    printf(" Ususario: %s \n", empleadoAMostrar.usuario);
    mostrarContrasenia();
    printf(" Tipo de acceso: %s \n", empleadoAMostrar.perfil);
    printf("\n-----------------------------------------------------------------\n");
}

int validarPalabra(char palabra[])
{
    int i;
    for(i = 0; i < strlen(palabra); i++)
    {
        if(!(isalpha(palabra[i])))
        {
            printf("\n Solo se permite ingresar letras.\n");
            return 0;
        }

    }
    return 1;
}

nodoEmpleado* eliminarEmpleado(nodoEmpleado* listaEmpleados,  int dni) {
    nodoEmpleado* aux = listaEmpleados;
    nodoEmpleado* ant;
    if(listaEmpleados && aux->empleado.dni == dni) {
        listaEmpleados = listaEmpleados->siguiente;
        free(aux);
    } else {
        while(aux && aux->empleado.dni != dni) {
            ant = aux;
            aux = aux->siguiente;
        }
    }

    if(aux) {
        ant->siguiente = aux->siguiente;
        free(aux);
    }

    return listaEmpleados;
}









