#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/*/De esta forma completamos la función utn_getNumero, la cual utiliza internamente las
funciones:
• getInt: Pide un texto al usuario, lo almacena como cadena, valida y convierte el texto
a numero y lo devuelve como int.
• esNumerica: Recibe una cadena de caracteres y devuelve 1 en el caso de que el texto
este compuesto solo por números*/

int utn_getNumero(int* pResultado,
                  char* mensaje,
                  char* mensajeError,
                  int minimo,
                  int maximo,
                  int reintentos)
{
    int ret;
    int num;
    while(reintentos>0)
    {
        printf(mensaje);
        if(getInt(&num)==1)   //(scanf("%d",&num)==1) //ES PARA VERIFICAR QUE SE
        {                       //INGRESO UN NUMERO
            if(num<=maximo && num>=minimo)
            {
                break;
            }
        }
        fflush(stdin); //SE REPITE EL MENSAJE PORQUE NO SE LIMPIA EL BUFFER
                       // =>DA ERROR LAS VECES QUE DEMOS DE REINTENTOS
        reintentos--;
        printf(mensajeError);
        printf("\n");
    }
    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResultado = num;
    }
    return ret;
}
///////////////////////////////////////////////////
static int getInt(int* pResultado)
 {
     int ret=-1;
     char buffer[64];
     scanf("%s", buffer);
     if(esNumerica(buffer))
     {
         *pResultado = atoi(buffer);
         ret=1;
     }
     return ret;
 }
///////////////////////////////////////////////////
static int esNumerica(char* cadena)
{
    int ret=-1;
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(cadena[i]<'0' || cadena[i]>'9')
                break;
            i++;
        }
        if(cadena[i]=='\0')
            ret=1;
    }
    return ret;
}

