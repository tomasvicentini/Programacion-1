#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    utn_getNumero(&n,"Agregar numero: ", "ERROR!", 1, 25, 3);
    printf("---------------------------------");
    printf("\n     Numero ingresado: %d\n", n);
    printf("---------------------------------\n\n");
    system("pause");

    return 0;
}
