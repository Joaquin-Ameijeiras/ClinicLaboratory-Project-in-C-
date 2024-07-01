#ifndef TDA_LISTA_EMPLEADOS_H_INCLUDED
#define TDA_LISTA_EMPLEADOS_H_INCLUDED

typedef struct {
    int dni;
    char apellidoYNombre[40];
    char usuario[20];
    char perfil[20];
    char contrasena[15];
} stEmpleado;

typedef struct
{
    stEmpleado empleado;
    struct nodoEmpleado * siguiente;
} nodoEmpleado;

// TDA LISTAS
nodoEmpleado*   inicializarListaEmpleados();
nodoEmpleado*   crearNodoEmpleado(stEmpleado);
nodoEmpleado*   insertarEmpleadoAlPcipio(nodoEmpleado*, stEmpleado);

//Funciones Asociadas
stEmpleado      cargarNuevoEmpleado();
nodoEmpleado*   registrarEmpleado(nodoEmpleado*);
nodoEmpleado*   buscarEmpleadoPorContraseniaYDNI(nodoEmpleado*, char[], int);
void            mostrarEmpleado(stEmpleado);
void            mostrarEmpleadoEnMenu(stEmpleado);
void            mostrarListaEmpleados(nodoEmpleado*);
void            inicarSesion();
int             validarPalabra(char palabra[]);

#endif // TDA_LISTA_EMPLEADOS_H_INCLUDED
