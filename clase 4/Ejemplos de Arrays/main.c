#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int vectorDeNumeros[10] = {1,2,3,4,5,6,7,8,9,10};
    numero = 0;
    int i;
    int minimo;
    int maximo;
    int flag = 0;
    int contPos = 0;
    int posMin = 0;
    int posMax = 0;

    //int contPares = 0;
    //int acumPares = 0;
    //float promedio;

    printf("Ejemplos de Vectores \n");

    for(i = 0; i < 10; i++){
        //printf("Ingrese un numero: ");
        //scanf("%d", &vectorDeNumeros[i]);
        /*if(vectorDeNumeros[i] % 2 == 0){
            acumPares = acumPares + i;
            contPares++;
        }*/
        if(vectorDeNumeros[i] > maximo || flag == 0){
            maximo = vectorDeNumeros[i];
            posMin = contPos;
        }
        if(vectorDeNumeros[i] < minimo || flag == 0){
            minimo = vectorDeNumeros[i];
            flag = 1;
            posMax = contPos;
        }
        contPos++;

    }
    printf("NUMERO MINIMO = %i -- POSICION = %i\n", minimo, posMin);
    printf("NUMERO MAXIMO = %i -- POSICION = %i\n", maximo, posMax);


   /* for(i = 0; i < 10; i++){  PARA QUE MUESTRE NUMEROS NEGATIVOS
            if(vectorDeNumeros[i] < 0){
        printf("\n %i",vectorDeNumeros[i]);
            }
    }
    promedio = (float)acumPares / contPares;

    printf("SUMA = %d -- CANTIDAD = % d \n\n", acumPares, contPares);

    printf("PROMEDIO NUMEROS PARES: \n %f",promedio);
    */

    return 0;
}
