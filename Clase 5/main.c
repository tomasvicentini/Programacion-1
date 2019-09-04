#include <stdio.h>
#include <stdlib.h>

void funcion(int*);

int main()
{
    int numero = 4;
    printf("El numero antes de modificar es: %i", numero);
    funcion(&numero);
    printf("\nEl numero despues de modificar es: %i", numero);

    return 0;
}
void funcion(int* numero)
{
    printf("\nIngrese un numero: ");
    scanf("%i", .numero);


}
