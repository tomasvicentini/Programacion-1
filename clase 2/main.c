#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dinero;
    char tipo; // P,D,L,B
    int maximoDolar;
    int contDolar = 1;
    int contador = 0;
    float promPesos;
    int acumPesos = 0;
    int contPesos = 0;
    float porcCantPesos;
    float porcCantLibras;
    float porcCantBTC;
    float porcCantDolares;
    int contLibras = 0;
    int contBTC = 0;
    int contUSD = 0;

    while(contador < 5){
        printf("Tipo de moneda: ");
        fflush(stdin);
        scanf("%c", &tipo);

        while(tipo != 'D' && tipo != 'P' && tipo != 'L' && tipo != 'B'){
                    printf("ERROR!!! Reingrese el tipo de moneda: (P,D,L,B)");
                    fflush(stdin);
                    scanf("%c", &tipo);
        }

        printf("Cantidad: ");
        fflush(stdin);
        scanf("%i", &dinero);

        if(tipo == 'D'){
                if(contDolar == 1){
                    contDolar = 0;
                    maximoDolar = dinero;
                }
                if(dinero > maximoDolar){
                    maximoDolar = dinero;
                }
        }
        if(tipo == 'P'){
            acumPesos = acumPesos + dinero;
            contPesos++;
        } else if(tipo == 'L'){
            contLibras++;
        } else if(tipo == 'D'){
            contUSD++;
        } else if(tipo == 'B'){
            contBTC++;
        }

        contador++;
    }

        if(contDolar == 1){
            printf("No se ingresaron dolares");
        } else{
            printf("El maximo valor de dolares es: %d \n", maximoDolar);
        }

    promPesos = acumPesos/(float)contPesos;
    printf("El promedio de pesos es de: %f \n",promPesos);

    porcCantPesos = (float)contPesos *100 / 5;
    printf("El porcentaje total de $ en la cartera es de: %f \n", porcCantPesos);

    porcCantLibras = (float)contLibras *100 / 5;
    printf("El porcentaje total de Libras en la cartera es de: %f \n", porcCantLibras);

    porcCantBTC = (float)contBTC *100 / 5;
    printf("El porcentaje total de BTC en la cartera es de: %f \n", porcCantBTC);

    porcCantDolares = (float)contUSD *100 / 5;
    printf("El porcentaje total de U$D en la cartera es de: %f \n", porcCantDolares);

    return 0;
}
