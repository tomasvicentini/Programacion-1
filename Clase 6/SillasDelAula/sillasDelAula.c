#include <stdio.h>
#include <stdlib.h>
#include <sillasDelAula.h>
#define CANTIDAD = 5

void cargarArrayConHardcode(sillas, CANTIDAD)
{
     unsigned int sillas[CANTIDAD] = {55, 11, 22, 33, 44};

     return sillas;
}

int DameElMaximo(int sillas[CANTIDAD], int maximo)
{
    int flag = 0;

    if(maximo < sillas[CANTIDAD] || flag == 0)
    {
    maximo=sillas[CANTIDAD];
    flag = 1;
    }

    return maximo;
}
int DameElMinimo(int sillas[CANTIDAD], int minimo)
{
    int flag = 0;

    if(minimo > sillas[CANTIDAD] || flag == 0)
    {
    minimo=sillas[CANTIDAD]
    flag = 1;
    }

    return minimo;
}
