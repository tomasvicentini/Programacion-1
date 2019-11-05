/*1) Agregar a la biblioteca utn.h funciones para validar diferentes tipos de valores:

Solo números, ej. 123436679
Solo letras, ej. abBD
Alfanumericos, ej. ab555gT6
Teléfono, ej. 4XXX-XXXX
2) Realizar un programa que pida al usuario el ingreso de un dato y determine con cuales de los tipos cumple.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define MAXINPUT 100

int main()
{
    char input[MAXINPUT];
    int len;

    printf("Ingrese algo: ");
    scanf("%s", input);
    len=strlen(input);
    if(len>0)
    {
        if(esNumerico(input))
        {
            printf("Si, es un numero.\n");
        }
        if(esTelefono(input))
        {
            printf("Si, es un telefono.\n");
        }
        if(esAlfaNumerico(input))
        {
            if((esNumerico(input))|| (esSoloLetras(input)))
            {

            }
            else
            {
                printf("Si, es alfa numerico.\n");
            }
        }
        if(esSoloLetras(input))
        {
            printf("Si, es solo letras.\n");
        }
    }

    return 0;
}
