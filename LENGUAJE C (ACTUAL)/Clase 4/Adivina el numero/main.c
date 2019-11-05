#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int numOculto;
    int numIngresado;
    char teclaIngresada;
    int jugar;

    teclaIngresada = 's';
    while(teclaIngresada == 's' || teclaIngresada == 'S')
    {
        jugar = 1;
        numOculto = getNumeroAleatorio(1,100,1);
        while(jugar == 1)
        {
            numIngresado = getInt("Ingrese un numero(0-99)\n");
            if(numIngresado < 0)
            {
                jugar = 0;
            }
            else if(numIngresado == numOculto)
            {
                printf("GANASTE!!! :D\n");
                jugar = 0;
            }
            else if(numIngresado < numOculto)
            {
                printf("Te quedaste corto! :O\n");
            }
            else if(numIngresado > numOculto)
            {
                printf("Te pasaste !! :S\n");
            }

        }
        system("pause");
        system("cls");

        teclaIngresada = getChar("Desea jugar nuevamente? (S/N)");

    }

    return 0;
}
