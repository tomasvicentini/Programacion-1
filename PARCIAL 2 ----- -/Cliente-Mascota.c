#include "Cliente-Mascota.h"
#include <stdio.h>
#include <string.h>


void mostrarClienteConSusMascotas(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i; // Clientes
    int j; // Mascotas
    char flagTieneMascotas;

    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO)
        {
            printf("\n---------------------------------------------------------------------------\n");
            printf("ID: %d |CLIENTE: %s %s|TELEFONO: %d \n", listaClientes[i].idCliente ,listaClientes[i].nombre,listaClientes[i].apellido, listaClientes[i].telefono);
            printf("---------------------------------------------------------------------------\n");
            flagTieneMascotas = 'n';

            printf("| %4s | %15s | %5s | %20s | %20s |\n","ID","NOMBRE","TIPO","RAZA","PAIS");
            printf("---------------------------------------------------------------------------\n");
            for(j=0;j<sizeMascota; j++)
            {
                if(listaMascotas[j].idCliente == listaClientes[i].idCliente && listaMascotas[j].estado == OCUPADO)
                {
                    printf("| %4d | %15s | %5s | %20s | %20s |\n", listaMascotas[j].idMascota,
                                                                    listaMascotas[j].nombre,
                                                                    listaMascotas[j].tipo,
                                                                    listaMascotas[j].raza.nombreRaza,
                                                                    listaMascotas[j].raza.pais);
                    flagTieneMascotas = 's';
                }
            }

            if(flagTieneMascotas == 'n')
            {
                printf("El cliente no tiene mascotas.\n\n");
            }
        }
    }
}

void mostrarProveedorConMasproductos(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    eAux aux[sizeCliente];

    int i;
    int j;
    int maximo;

    for(i=0; i<sizeCliente; i++)
    {
        aux[i].idCliente = listaClientes[i].idCliente;
        aux[i].cantidadMascotas = 0;
    }

    for(i=0; i<sizeCliente; i++)
    {
        for(j=0; j<sizeMascota; j++)
        {
            if(listaMascotas[j].idCliente == aux[i].idCliente)
            {
                aux[i].cantidadMascotas++;
            }
        }
    }

    for(i=0; i<sizeCliente; i++)
    {
        if(i==0 || aux[i].cantidadMascotas>maximo)
        {
            maximo = aux[i].cantidadMascotas;
        }
    }

    for(i=0; i<sizeCliente; i++)
    {
        for(j=0; j<sizeCliente; j++)
        {
            if(listaClientes[j].idCliente == aux[i].idCliente && aux[i].cantidadMascotas == maximo)
            {
                printf("\n%s %s-- %d\n", listaClientes[i].nombre, listaClientes[i].apellido, maximo);
            }
        }
    }
}

void eliminarClienteConSusMascotas(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i; // Clientes
    int j; // Mascotas
    int idCliente;
    char confirmacion;

    printf("Ingrese el ID de la cliente a eliminar: ");
    scanf("%d", &idCliente);

    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO && idCliente == listaClientes[i].idCliente)
        {
            printf("Desea eliminar el cliente %s?(s/n): ", listaClientes[i].nombre);
            fflush(stdin);
            scanf("%c",&confirmacion);

            for(j=0;j<sizeMascota; j++)
            {
                if(listaMascotas[j].idCliente == listaClientes[i].idCliente && listaMascotas[j].estado == OCUPADO)
                {
                    if(confirmacion == 's')
                    {
                        listaClientes[i].estado = LIBRE;
                        listaMascotas[j].estado = LIBRE;
                        printf("Cliente eliminado del registro.\n\n");
                        break;
                    }
                }
            }
            if(confirmacion == 'n')
            {
                printf("No se elimino el cliente del registro\n\n");
            }
        }
    }
}

void mostrarListadoDeMascotasConClientes(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i, j;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %30s | %5s | %20s | %20s | %4s | %5s | %10s | %30s |\n","ID MASCOTA","NOMBRE","TIPO","RAZA","PAIS","EDAD","PESO","SEXO","CLIENTE");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0; i<sizeMascota; i++)
    {
        if(listaMascotas[i].estado == OCUPADO)
        {
            for(j=0;j<sizeCliente; j++)
            {
                if(listaClientes[j].idCliente == listaMascotas[i].idCliente && listaClientes[j].estado == OCUPADO)
                {
                    printf("%10d | %30s | %5s | %20s | %20s | %4d | %3.2f | %10s | %30s |\n",  listaMascotas[i].idMascota,
                                                                                               listaMascotas[i].nombre,
                                                                                               listaMascotas[i].tipo,
                                                                                               listaMascotas[i].raza.nombreRaza,
                                                                                               listaMascotas[i].raza.pais,
                                                                                               listaMascotas[i].edad,
                                                                                               listaMascotas[i].peso,
                                                                                               listaMascotas[i].sexo,
                                                                                               listaClientes[j].apellido);
                }
            }
        }
    }
}

void mostrarClienteConMasDeUnaMascota(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i; // Clientes
    int j; // Mascotas
    int cont[sizeCliente];

    for (i=0; i<sizeCliente; i++)
    {

        if(listaClientes[i].estado == OCUPADO)
        {
            cont[i] = 0;
            for(j=0;j<sizeMascota; j++)
            {
                if(listaMascotas[j].idCliente == listaClientes[i].idCliente && listaMascotas[j].estado == OCUPADO)
                {
                    cont[i]++;
                }
            }
        }
    }

    printf("-----------------------------------------------LISTA DE CLIENTES CON MAS DE UNA MASCOTA----------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %25s | %25s | %25s | %10s | %4s | %10s | %13s |\n","ID CLIENTE","NOMBRE","APELLIDO","LOCALIDAD","TELEFONO","EDAD","SEXO","CANT MASCOTAS");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO && cont[i] > 1)
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

void mostrarListadoDeMascotasConMasDeTresAnioConClientes(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i, j;

    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %30s | %5s | %20s | %20s | %4s | %5s | %10s | %30s |\n","ID MASCOTA","NOMBRE","TIPO","RAZA", "PAIS","EDAD","PESO","SEXO","CLIENTE");
    printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (i=0; i<sizeMascota; i++)
    {
        if(listaMascotas[i].estado == OCUPADO && listaMascotas[i].edad > 3)
        {
            for(j=0;j<sizeCliente; j++)
            {
                if(listaClientes[j].idCliente == listaMascotas[i].idCliente && listaClientes[j].estado == OCUPADO)
                {
                    printf("%10d | %30s | %5s | %20s | %20s | %4d | %3.2f | %10s | %30s |\n",  listaMascotas[i].idMascota,
                                                                                               listaMascotas[i].nombre,
                                                                                               listaMascotas[i].tipo,
                                                                                               listaMascotas[i].raza.nombreRaza,
                                                                                               listaMascotas[i].raza.pais,
                                                                                               listaMascotas[i].edad,
                                                                                               listaMascotas[i].peso,
                                                                                               listaMascotas[i].sexo,
                                                                                               listaClientes[j].apellido);
                }
            }
        }
    }
}

void contarMascotasDeTodosLosClientes(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i; // Clientes
    int j; // Mascotas
    int cont[sizeCliente];

    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO)
        {
            cont[i] = 0;
            for(j=0;j<sizeMascota; j++)
            {
                if(listaMascotas[j].idCliente == listaClientes[i].idCliente && listaMascotas[j].estado == OCUPADO)
                {
                    cont[i]++;
                }
            }
        }
    }
    mostrarClientesOrdenadosPorContadorDeMascotas(listaClientes,sizeCliente,cont);
}

void contarMascotasDeTodosLosClientesYOrdenarPorCantMascYporNombre(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota)
{
    int i; // Clientes
    int j; // Mascotas
    int cont[sizeCliente];

    for (i=0; i<sizeCliente; i++)
    {
        if(listaClientes[i].estado == OCUPADO)
        {
            cont[i] = 0;
            for(j=0;j<sizeMascota; j++)
            {
                if(listaMascotas[j].idCliente == listaClientes[i].idCliente && listaMascotas[j].estado == OCUPADO)
                {
                    cont[i]++;
                }
            }
        }
    }

    mostrarClientesOrdenadosPorContadorDeMascotasYporNombres(listaClientes,sizeCliente,cont);
}
