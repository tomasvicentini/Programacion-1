//1) Solicitar al usuario 5 números,
//permitir listarlos por pantalla indicando
//el máximo, el mínimo y el promedio.
//Permitir Modificar el valor de cualquiera de los números
//cargados indicando el índice del mismo y su nuevo valor.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define MAX 5

int main()
{
    int v[MAX], i;
    int numeroIngresado;
    int valorIngresado;
    int opcionMenu = 0;


    for(i=0; i<MAX; i++)
    {
        numeroIngresado = getInt("Ingrese el valor: ");
        v[i] = numeroIngresado;
    }
    while(opcionMenu!=3)
    {
        opcionMenu=getInt("\n1-Mostrar\n2-Modificar\n3-Salir\n");
        switch(opcionMenu)
        {
            case 1:
                printf("\nINDICE -   VALOR\n");
                for(i=0;i<MAX;i++)
                {
                   printf(" %d     -     %d \n", i, v[i]);
                }
                break;
            case 2:
                i=getInt("\nIngrese el indice a modificar: ");
                if(i>=0 && i<MAX)
                {
                    valorIngresado=getInt("Ingrese el valor: \n");
                    v[i]=valorIngresado;
                }
                else
                {
                    printf("\nEl indice ingresado esta fuera de rango");
                }
                break;
            case 3:
                printf("HASTA LUEGO!!!");
                break;
            default:
                printf("Opcion incorrecta!!!");
        }
    }
    return 0;
}
