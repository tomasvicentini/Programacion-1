#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD = 5
int main()
{
    unsigned int sillas[CANTIDAD] = {55, 11, 22, 33, 44};
    int maximo;
    int minimo;

    void cargarArrayConHardcode(sillas, CANTIDAD);

    maximo=DameElMaximo(sillas, CANTIDAD);
    printf("%d", maximo);

    minimo=DameElMinimo(sillas, CANTIDAD);
    printf("%d", minimo);

    DarLaBienvenida();

    return 0;
}
