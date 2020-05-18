#include <stdio.h>
#include <string.h>
#include "Cliente.h"
#define CLIENTES 10
#define LIBRE 0
#define OCUPADO 1

void hardcodearClientes(eCliente listaClientes[], int tam)
{
    int i;

    int idCliente[5] = {100,101,102,103,104};
    char nombre[5][51] = {"Gisela", "Thierry", "Gabriela", "Dennis", "Juan Roman"};
    char apellido[5][51] = {"Dulko", "Henry", "Sabatini", "Bergkamp", "Riquelme"};
    char localidad[5][51] = {"Docksud", "Paris", "Cordoba", "Amsterdam", "Don Torcuato"};
    unsigned int telefono[5] = {31125494,48024818,71821122,46012081,42008080};
    int edad[5] = {45,41,20,18,44};
    char sexo[5][10] = {"Femenino", "Masculino", "Femenino", "Masculino", "Masculino"};
    int estado[10] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,LIBRE,LIBRE,LIBRE,LIBRE,LIBRE};

    for(i=0; i<tam; i++)
    {
        listaClientes[i].idCliente = idCliente[i];
        strcpy(listaClientes[i].nombre,nombre[i]);
        strcpy(listaClientes[i].apellido,apellido[i]);
        strcpy(listaClientes[i].localidad,localidad[i]);
        listaClientes[i].telefono = telefono[i];
        listaClientes[i].edad = edad[i];
        strcpy(listaClientes[i].sexo,sexo[i]);
        listaClientes[i].estado = estado[i];
    }
}

void inicializarClientes(eCliente listaClientes[], int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        listaClientes[i].estado = LIBRE;
    };
}

int buscarLibreCliente(eCliente* listado, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

eCliente cargarUnCliente(void)
{
    eCliente miCliente;

    printf("Nombre: ");
    //scanf("%s",&miCliente.nombre);
    fflush(stdin);
    fgets(&miCliente.nombre,51,stdin);
    miCliente.nombre[strlen( miCliente.nombre)-1]='\0';
    printf("Apellido: ");
    //scanf("%s",&miCliente.apellido);
    fflush(stdin);
    fgets(&miCliente.apellido,51,stdin);
    miCliente.apellido[strlen( miCliente.apellido)-1]='\0';
    printf("Localidad: ");
    //scanf("%s",&miCliente.localidad);
    fflush(stdin);
    fgets(&miCliente.localidad,51,stdin);
    miCliente.localidad[strlen( miCliente.localidad)-1]='\0';
    printf("Telefono: ");
    scanf("%d", &miCliente.telefono);
    printf("Edad: ");
    scanf("%d", &miCliente.edad);
    printf("Genero: ");
    scanf("%s",&miCliente.sexo);
    fflush(stdin);

    miCliente.estado = OCUPADO;

    return miCliente;
}

void cargarListadoDeClientes(eCliente listado[], int tam)
{
    int index;
    index = buscarLibreCliente(listado,tam);
    if(index!=-1)
    {
       listado[index] = cargarUnCliente();
       listado[index].idCliente = index + 1;
    }
    else
    {
        printf("------------------------------\n");
        printf("ERROR! No hay mas espacio!\n");
        printf("------------------------------\n\n");
    }
}


void mostrarListadoDeClientes(eCliente listado[], int tam)
{
    int i;
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %30s | %30s | %30s | %10s | %4s | %10s |\n","ID CLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<tam; i++)
    {
       if(listado[i].estado == OCUPADO)
        {
            mostrarUnCliente(listado[i]);
        }
    }
}

void mostrarUnCliente(eCliente miCliente)
{
    printf("%10d | %30s | %30s | %30s | %10d | %4d | %10s |\n",  miCliente.idCliente,
                                                                 miCliente.nombre,
                                                                 miCliente.apellido,
                                                                 miCliente.localidad,
                                                                 miCliente.telefono,
                                                                 miCliente.edad,
                                                                 miCliente.sexo);
}

void modificarCliente(eCliente listado[], int sizeClientes)
{
    int idCliente;
    printf("Ingrese el ID de la cliente a modificar: ");
    scanf("%d", &idCliente);

    int i;
    char confirmacion;
    for(i=0; i<sizeClientes; i++)
    {
        if(listado[i].estado == OCUPADO && idCliente == listado[i].idCliente)
        {
            printf("Desea modificar el cliente %s?(s/n): ", listado[i].nombre);
            fflush(stdin);
            scanf("%c",&confirmacion);
            if(confirmacion == 's')
            {
                printf("Nombre: ");
                //scanf("%s",&listado[i].nombre);
                fflush(stdin);
                fgets(&listado[i].nombre,51,stdin);
                listado[i].nombre[strlen( listado[i].nombre)-1]='\0';
                printf("Apellido: ");
                //scanf("%s",&listado[i].apellido);
                fflush(stdin);
                fgets(&listado[i].apellido,51,stdin);
                listado[i].apellido[strlen( listado[i].apellido)-1]='\0';
                printf("Localidad: ");
                //scanf("%s",&listado[i].localidad);
                fflush(stdin);
                fgets(&listado[i].localidad,51,stdin);
                listado[i].localidad[strlen( listado[i].localidad)-1]='\0';
                printf("Telefono: ");
                scanf("%lf", &listado[i].telefono);
                printf("Edad: ");
                scanf("%d", &listado[i].edad);
                printf("Genero: ");
                scanf("%s",&listado[i].sexo);
                fflush(stdin);
                break;
            }
            else
            {
                if(confirmacion == 'n')
                {
                    printf("No se modifico el cliente\n\n");
                }
            }
        }
    }
}

void mostrarClientesOrdenadosPorContadorDeMascotas(eCliente* listaClientes, int sizeCliente, int* cont)
{
    int i, j;
    int auxcont;
    eCliente aux;
    for (i=0; i<sizeCliente-1; i++)
    {
        for(j=i+1; j<sizeCliente;j++)
        {
            if(listaClientes[i].estado == OCUPADO && cont[i] > cont[j])
            {
                aux = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = aux;

                auxcont = cont[i];
                cont[i] = cont[j];
                cont[j] = auxcont;
            }
        }
    }

    printf("-----------------------------------------------LISTA DE CLIENTES ORDENADOS POR CANTIDAD DE MASCOTAS----------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %25s | %25s | %25s | %10s | %4s | %10s | %13s |\n","ID CLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO","CANT MASCOTAS");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO)
        {

            printf("%10d | %25s | %25s | %25s | %10d | %4d | %10s | %13d |\n",  listaClientes[i].idCliente,
                                                                                listaClientes[i].nombre,
                                                                                listaClientes[i].apellido,
                                                                                listaClientes[i].localidad,
                                                                                listaClientes[i].telefono,
                                                                                listaClientes[i].edad,
                                                                                listaClientes[i].sexo,
                                                                                cont[i]);
        }
    }
}

void mostrarClientesOrdenadosPorContadorDeMascotasYporNombres(eCliente* listaClientes, int sizeCliente, int* cont)
{
    int i, j;
    eCliente aux;
    for (i=0; i<sizeCliente-1; i++)
    {
        for(j=i+1; j<sizeCliente;j++)
        {
            if(listaClientes[i].estado == OCUPADO && cont[i] > cont[j])
            {
                aux = listaClientes[i];
                listaClientes[i] = listaClientes[j];
                listaClientes[j] = aux;
            }
            else if(listaClientes[i].estado == OCUPADO && cont[i] == cont[j])
            {
                if(strcmp(listaClientes[i].nombre,listaClientes[j].nombre)>0)
                {
                    aux = listaClientes[i];
                    listaClientes[i] = listaClientes[j];
                    listaClientes[j] = aux;
                }
            }
        }
    }

    printf("-----------------------------------------------LISTA DE CLIENTES ORDENADOS POR CANTIDAD DE MASCOTAS----------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %25s | %25s | %25s | %10s | %4s | %10s | %13s |\n","ID CLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO","CANT MASCOTAS");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO)
        {

            printf("%10d | %25s | %25s | %25s | %10d | %4d | %10s | %13d |\n",  listaClientes[i].idCliente,
                                                                                listaClientes[i].nombre,
                                                                                listaClientes[i].apellido,
                                                                                listaClientes[i].localidad,
                                                                                listaClientes[i].telefono,
                                                                                listaClientes[i].edad,
                                                                                listaClientes[i].sexo,
                                                                                cont[i]);
        }
    }
}

void promedioDeMujVarClientes(eCliente listado[], int tam)
{
    int i;
    float contVarones = 0;
    float contMujeres = 0;
    float contTotal = 0;
    float promedioVar = 0;
    float promedioMuj = 0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            contTotal++;
            if(strcmp(listado[i].sexo,"Masculino")==0)
            {
                contVarones++;
            }
            else if(strcmp(listado[i].sexo,"Femenino")==0)
            {
                contMujeres++;
            }
        }
    }
    promedioVar = contVarones / contTotal;
    promedioMuj = contMujeres / contTotal;


    printf("El promedio de varones clientes es de %.2f\n",promedioVar);
    printf("El promedio de mujeres clientes es de %.2f\n",promedioMuj);
}
