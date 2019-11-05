#include <stdio.h>
#include <stdlib.h>

/*Solicite al usuario 10 números
Calcule cuántos son negativos y cuantos son positivos
Muestre por pantalla la cantidad de negativos y la cantidad de positivos*/

int main()
{
    int vector[10];
    //vector[10] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    int contNegativos = 0;
    int contPositivos = 0;

    for(i=0; i<10; i++)
    {
        printf("INGRESE UN NUMERO: ");
        scanf("%d", &vector[i]);

        // NEGATIVOS
        if(vector[i] < 0)
        {
            contNegativos++;
        }
        // POSITIVOS
        if(vector[i] > 0)
        {
            contPositivos++;
        }
    }

    //system("cls");

    printf("\nCantidad de negativos = %d ----- Cantidad de positivos = %d", contNegativos, contPositivos);

    return 0;
}
