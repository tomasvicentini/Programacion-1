#include "funcion.h"

/** \brief Solicita un numero y lo retorna
 *  \param aux es el numero a ingresar
 *  \return el numero ingresado
 *
 */

float pedirNumero()
{
    float aux;
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &aux);
    return aux;
}

/** \brief Recibe el radio y calcula el area del ciruclo
 *  \param Radio es el radio del circulo
 *  \return El area del circulo
 *
 */
float calcularAreaCirculo(float radio)
{
    float resultado;
    resultado = 3.14 * radio * radio;
    return resultado;
}
