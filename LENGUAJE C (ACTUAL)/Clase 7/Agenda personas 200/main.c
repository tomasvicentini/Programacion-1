/*1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:
Nombre
Apellido
Legajo (NO SE PUEDE REPETIR)
a- Realizar un programa con un menú de opciones para hacer altas , bajas y modificaciones (ABM) de una agenda.
b- Mostrar un listado ordenado por Apellido
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

int main()
{
    char arrayNombres[MAX][50];
    char arrayApellidos[MAX][50];
    int arrayLegajos[MAX];

    char auxiliarNombresStr[50];
    char auxiliarApellidosStr[50];
    char auxiliarLegajoStr[50];
    int auxiliarLegajo;

    int indiceLugarLibre;
    int indiceResultadoBusqueda;
    int opcion;

    int i,j;

    incializarArrayInt(arrayLegajos,MAX,-1); // Se indica con -1 que esa posicion esta vacia
    do
    {
        printf("------Menu de opciones------\n");
        printf("1-ALTAS\n2-BAJAS\n3-MODIFICACIONES\n4-LISTAR\n5-ORDENAR\n6-SALIR");
        printf("\n----------------------------");
        printf("\nIngrese opcion: ");
        scanf("%i", &opcion);

        switch(opcion)
        {
            case 1:  //ALTA
                indiceLugarLibre = buscarPrimerOcurrencia(arrayLegajos,MAX, -1);
                if(indiceLugarLibre == -1)
                {
                    printf("\n\n NO QUEDAN LUGARES LIBRES!!!");
                    break;
                }
                printf("\nALTA\n");
                if(!getStringLetras("Ingrese el nombre: ", auxiliarNombresStr))
                {
                    printf("El nombre debe estar compuesto solo por letras\n");
                    break;
                }
                if(!getStringLetras("Ingrese el apellido: ", auxiliarApellidosStr))
                {
                    printf("El apellido debe estar compuesto solo por letras\n");
                    break;
                }
                if(!getStringNumeros("Ingrese el legajo: ", auxiliarLegajoStr))
                {
                    printf("El legajo debe ser numerico\n");
                    break;
                }
                auxiliarLegajo = atoi(auxiliarLegajoStr);

                if(buscarPrimerOcurrencia(arrayLegajos,MAX,auxiliarLegajo) != -1)
                {
                    printf("\n\nEL LEGAJO YA EXISTE!!!\n");
                    break;
                }

                strcpy(arrayNombres[indiceLugarLibre],auxiliarNombresStr);
                strcpy(arrayApellidos[indiceLugarLibre],auxiliarApellidosStr);
                arrayLegajos[indiceLugarLibre] = auxiliarLegajo;

                system("pause");
                system("cls");
                break;

            case 2: //BAJA
                if(!getStringNumeros("Ingrese el legajo a dar de baja: ", auxiliarLegajoStr))
                {
                    printf("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos, MAX, atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }
                arrayLegajos[indiceResultadoBusqueda]=-1; //SE REALIZA UNA BAJA LOGICA, ya que queda aun su nombre y apellido
                printf("Se a dado de baja el legajo\n\n");

                system("pause");
                system("cls");
                break;

            case 3:  //MODIFICAR
                if(!getStringNumeros("Ingrese el legajo a modificar: ", auxiliarLegajoStr))
                {
                    printf("El legajo debe ser numerico\n");
                    break;
                }
                indiceResultadoBusqueda = buscarPrimerOcurrencia(arrayLegajos, MAX, atoi(auxiliarLegajoStr));

                if(indiceResultadoBusqueda == -1)
                {
                    printf("\n\nNO SE ENCUENTRA ESE LEGAJO\n");
                    break;
                }
                if(!getStringLetras("Ingrese el nombre: ", auxiliarNombresStr))
                {
                    printf("El nombre debe estar compuesto solo por letras\n");
                    break;
                }
                if(!getStringLetras("Ingrese el apellido: ", auxiliarApellidosStr))
                {
                    printf("El apellido debe estar compuesto solo por letras\n");
                    break;
                }

                strcpy(arrayNombres[indiceLugarLibre],auxiliarNombresStr);
                strcpy(arrayApellidos[indiceLugarLibre],auxiliarApellidosStr);

                printf("Legajo modificado con exito\n\n");
                system("pause");
                system("cls");
                break;

            case 4:  //LISTAR
                printf("\LISTAR");
                for(i=0;i<MAX;i++)
                {
                    if(arrayLegajos[i] != -1)
                    {
                        printf("\n%i - %s %s\n",arrayLegajos[i], arrayNombres[i], arrayApellidos[i]);
                    }
                }
                system("pause");
                system("cls");
                break;

            case 5:  //ORDENAR
                printf("\nORDENADO\n");

                for(i=0; i<MAX-1; i++)
                {
                    if(arrayLegajos[i] == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j<MAX; j++)
                    {
                        if(arrayLegajos[j] == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayApellidos[i],arrayApellidos[j]))
                        {
                            strcpy(auxiliarNombresStr,arrayNombres[i]);
                            strcpy(arrayNombres[i],arrayNombres[j]);
                            strcpy(arrayNombres[j],auxiliarNombresStr);

                            strcpy(auxiliarApellidosStr,arrayApellidos[i]);
                            strcpy(arrayApellidos[i],arrayApellidos[j]);
                            strcpy(arrayApellidos[j],auxiliarApellidosStr);

                            auxiliarLegajo = arrayLegajos[i];
                            arrayLegajos[i] = arrayLegajos[j];
                            arrayLegajos[j] = auxiliarLegajo;
                        }
                    }
                }
                system("pause");
                system("cls");
                break;

            case 6:  //SALIR
                system("cls");
                printf("********************************************\n");
                printf("***************HASTA LUEGO******************\n");
                printf("********************************************\n");
                break;
            default:
                printf("Opcion INCORRECTA!!!");
        }
    }while(opcion!=6);

    return 0;
}
