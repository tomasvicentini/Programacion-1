#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    /* CADENA o STRING,  en C no existen el tipo de dato String, se utiliza char como array*/
    char palabra[10]; /* h|o|l|a|\o --- el \o cuenta como lugar, tendriamos 9 espacios libres de [10]*/
    char otraPalabra[10];
    int largo;
    int comp;

    strcpy(palabra, "hola"); //tam del origen no sea superior al de destino
    strcat(palabra, otraPalabra); /*SIRVE PARA CONCATENAR VARIABLES*/


    printf("Ingrese una palabra: ");
    fflush(stdin); /*SIEMPRE, POR LAS DUDAS*/
    /*/scanf("%s", palabra);*/ // NO SIRVE PARA STRINGS VAMOS A UTILIZAR LA FUNCION:
    gets(palabra); // fgets(palabra, 10, stdin); PARA LINUX
    //scanf("%[^\n]", palabra);

    printf("%s", palabra);

    comp = strcmp(palabra, otraPalabra);
    stricmp() // compara sin discriminar mayus de minusculas
    //Cuando las dos palabras son iguales, devuelve 0--- de lo contrario 1/-1(A - C = -1 || H - C = 1)

    strupr(palabra); /*SIRVE PARA PONER TODO EN MAYUS LA VARIABLE */
    strlwr(palabra); /*SIRVE PARA PONER TODO EN MINUS LA VARIABLE */

    //largo = strlen(palabra); /*Cuenta la longitud de la variable*/
    // strlen SE PUEDE UTILIZAR PARA VALIDAR CANTIDAD DE CARACTERES PARA CADENA
    //printf("El largo es %i", largo);



    return 0;
}
