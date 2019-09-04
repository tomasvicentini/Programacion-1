#include <stdio.h>
#include <stdlib.h>

/** \brief Calcula el factorial de un nº
 *
 * \param int El numero sobre el que se calcula el factorial
 * \return int El factorial
 *
 */
unsigned int factorial(int);

int main()
{
    int numero = 13;
    int resultado = 1;

    resultado = factorial(numero);

    printf("El factorial es: %i", resultado);

    return 0;
}

unsigned int factorial(int numero)
{
    unsigned int resultado;

    if(numero == 0)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero*factorial(numero-1);
    }
    return resultado; //DEJAR SOLO UN RETURN POR FUNCION
}

/*
void ordenarVector(int vector[], int tam)
{
    int i;
    int j;
    int aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1, j<tam; j++)
        {
            if(vector[i]>vector[j])
            {
                // SWAP
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux
            }
        }
    }
}
