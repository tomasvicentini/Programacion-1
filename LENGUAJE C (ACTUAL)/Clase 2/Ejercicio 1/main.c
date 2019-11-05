#include <stdio.h>
#include <stdlib.h>

// Realizar un programa que solicite cinco números e imprima por pantalla el promedio, el máximo y el mínimo.

int main()
{
    int vector[5];
    int i;
    float promedio;
    int acumulador = 0;
    int maximo;
    int minimo;
    int flag = 0;

    for(i=0; i<5; i++)
    {
        printf("INGRESE UN NUMERO: ");
        scanf("%d", &vector[i]);

        // MAXIMO
        if(maximo < vector[i] || flag == 0)
        {
            maximo = vector[i];
        }
        // MINIMO
        if(minimo > vector[i] || flag == 0)
        {
            minimo = vector[i];
            flag = 1;
        }

        acumulador = acumulador + vector[i];

    }

    promedio = acumulador / 5;

    printf("\nPROMEDIO = %.2f", promedio);
    printf("\nMINIMO = %d", minimo);
    printf("\nMAXIMO = %d", maximo);

    return 0;
}
