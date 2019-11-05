#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"

int main()
{
    float auxiliar_float;
    float area;

    auxiliar_float = pedirNumero();
    area = calcularAreaCirculo(auxiliar_float);
    printf("El area del circulo es: %.2f\n", area);

    return 0;
}

