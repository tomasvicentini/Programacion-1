#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** \brief Solicita un numera al usario y devuelve el resultado
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

/** \brief Solicita un numera al usario y devuelve el resultado
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%i", &auxiliar);
    return auxiliar;
}

/** \brief Solicita un numera al usario y devuelve el resultado
 *
 * \param mensaje Es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);  //fpurge(stdin) en LINUX O MAC
    scanf("%c", &auxiliar);
    return auxiliar;
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

