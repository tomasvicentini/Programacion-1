#include <stdio.h>
#include <stdlib.h>

void CambiarPorValor(int unDato);
void CambiarPorReferencia(int* unDato);
void CambiarPorReferencia(int *pDato);
int DameUnEntero(char* mensaje, int max, int cantidad, int *pNumero);

int main()
{
    int unNumero;
    int sePudo;
    sePudo = DameUnEntero("INGRESE SU EDAD: ", 100, 2, &unNumero);
    if(sePudo == -1){
        printf("NO SE PUDO CARGAR");
    } else{
        printf("EL NUMERO ES = %d", unNumero);
    }

    return 0;
}
int DameUnEntero(char* mensaje, int max, int cantidad, int *pNumero)
{

    int contador = 0;
    printf("%s", mensaje);
    scanf("%d", pNumero);

    while(*pNumero > max){
            contador++;
            printf("ERROR!! %s", mensaje);
            scanf("%d", pNumero);
            if(contador == cantidad){
                    return -1;
    }
    }
    return 0;
}
/*int main()
{
    int numero;
    numero = 22;
    CambiarPorValor(numero);
    printf("NUMERO = %d \n\n", numero);

    CambiarPorReferencia(&numero);
    printf("NUMERO = %d", numero);
    return 0;
}
void CambiarPorValor(int unDato)
{
    unDato = 99;
    printf("DATO POR VALOR = %d \n\n", unDato);
}
void CambiarPorReferencia(int *pDato)
{
    *pDato = 99;
    printf("\nDATO POR REFERENCIA %d \n\n", pDato);
}
*/
