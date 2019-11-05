#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
