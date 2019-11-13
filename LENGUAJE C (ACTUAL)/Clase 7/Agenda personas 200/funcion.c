#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}
/** \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]<'0' || str[i]>'9')
            return 0;
            i++;
    }
    return 1;
}

/** \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
 {
     int i=0;
     while(str[i]!='\0')
     {
         if((str[i]!=' ')&&(str[i]<'a')||(str[i]>'z'))
         {
             return 0;
         }
         i++;
     }
     return 1;
 }

 /** \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
 {
     int i=0;
     while(str[i]!='\0')
     {
         if((str[i]!=' ')&&(str[i]<'a' || str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]<'0'||str[i]>'9'))
         {
             return 0;
         }
         i++;
     }
     return 1;
 }

 /** \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, y 0 si no lo es
 *
 */
int esTelefono(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i]!='\0')
    {
        if((str[i]!=' ')&&(str[i]!='-')&&(str[i]<'0'||str[i]>'9'))
        {
             return 0;
        }
        if(str[i] == '-')
        {
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1) //debe tener un guion
    {
        return 1;
    }

    return 0;
}

/** \brief Solicita un texto al usuario y lo devuelve
 * \param  mensaje Es el mensaje a ser mostrado
 * \param  input Array donde se cargara el texto ingresado
 * \return void
 */
 void getString(char mensaje[], char input[])
 {
     printf(mensaje);
     scanf("%s", input);
 }

 /** \brief Solicita un texto al usuario y lo devuelve
  * \param mensaje Es el mensaje a ser mostrado
  * \param input Array donde se cargara el texto ingresado
  * \return 1 si el texto contiene solo letras y 0 si no
  */
int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

 /** \brief Solicita un texto al usuario y lo devuelve
  * \param mensaje Es el mensaje a ser mostrado
  * \param input Array donde se cargara el texto ingresado
  * \return 1 si el texto contiene solo numeros y 0 si no
  */
int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/** \brief Genera un numero aleatorio
 *  \param desde Numero aleatorio minimo
 *  \param hasta Numero aleatorio maximo
 *  \param iniciar Indica si se trata del primer nº solicitado, 1 indica que si
 *  \return retorna el numero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde + (rand()%(hasta + 1 - desde));
}

/** \brief Inicializa un array de enteros con el valor recibido
 * \param array Es el array a ser incializado
 * \param cantidad_de_elementos Indica la longitud del array
 * \param valor Es el valor que sera cargado en cada posicion
 * \return -
 *
 */
void incializarArrayInt(int array[], int cantidad_de_elementos, int valor)
{
    int i;
    for(i=0; i<cantidad_de_elementos;i++)
    {
        array[i] = valor;
    }
}

/** \brief Busca la primer ocurrencia de un valor en un array de enteros
 * \param array Es el array a ser incializado
 * \param cantidad_de_elementos Indica la longitud del array
 * \param valor Es el valor que sera cargado en cada posicion
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarPrimerOcurrencia(int array[], int cantidad_de_elementos, int valor)
{
    int i;
    for(i=0; i < cantidad_de_elementos; i++)
    {
        if(array[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

