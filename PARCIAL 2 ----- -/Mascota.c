#include <stdio.h>
#include <string.h>
#include "Mascota.h"
#define MASCOTAS 20
#define LIBRE 0
#define OCUPADO 1

void hardcodearMascotas(eMascota listaMascotas[], int tam)
{
    int i;

    int idMascota[11] = {1,2,3,4,5,6,7,8,9,10,11};
    char nombre[11][51] = {"Charly", "Wisky", "Foxtrot", "Alfa", "Tekila", "Beta", "Mike", "Echo", "November", "Kilo", "Oscar"};
    char tipo[11][10] = {"Gato", "Gato", "Perro", "Perro", "Gato", "Perro", "Raro", "Perro", "Gato", "Gato", "Perro"};
    char raza[11][51] = {"Bengala", "Ragdoll", "Golden Retreiver", "Salchicha", "Munchkin", "Pitbull", "Iguana", "Labrador", "Sphynx", "Maine Coon", "Bulldog"};
    char razaPais[11][51] = {"Angola", "Libia", "Noruega", "Arabia Saudita", "Alemania", "Islas Feroes", "Fiji", "China", "Emiratos Arabes", "Argentina", "Frances"};
    int edad[11] = {10,2,5,1,8,10,2,6,1,8,8};
    float peso[11] = {15,11,30,18,12,45,11,38,18,12,12};
    char sexo[11][10] = {"Hembra", "Hembra", "Macho", "Macho", "Macho", "Macho", "Macho", "Macho", "Macho", "Macho", "Macho"};
    int idCliente[11] = {100,100,101,101,101,102,102,103,104,104,104};
    int estado[20] = {OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,OCUPADO,LIBRE,LIBRE,LIBRE,LIBRE,LIBRE,LIBRE,LIBRE,LIBRE,LIBRE};

    for(i=0; i<tam; i++)
    {
        listaMascotas[i].idMascota = idMascota[i];
        strcpy(listaMascotas[i].nombre,nombre[i]);
        strcpy(listaMascotas[i].tipo,tipo[i]);
        strcpy(listaMascotas[i].raza.nombreRaza,raza[i]);
        strcpy(listaMascotas[i].raza.pais,razaPais[i]);
        listaMascotas[i].edad = edad[i];
        listaMascotas[i].peso = peso[i];
        strcpy(listaMascotas[i].sexo,sexo[i]);
        listaMascotas[i].idCliente = idCliente[i];
        listaMascotas[i].estado = estado[i];
    }
}

void inicializarMascotas(eMascota listaMascotas[], int tam)
{
    int i;
    for (i=0; i<tam; i++)
    {
        listaMascotas[i].estado = LIBRE;
    };
}

int buscarLibreMascota(eMascota* listado, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

eMascota cargarUnaMascota(void)
{
    eMascota miMascota;

    printf("Nombre: ");
    //scanf("%s",&miMascota.nombre);
    fflush(stdin);
    fgets(&miMascota.nombre,51,stdin);
    miMascota.nombre[strlen( miMascota.nombre)-1]='\0';
    printf("Tipo (Gato-Perro-Raro): ");
    scanf("%s",&miMascota.tipo);
    fflush(stdin);
    int opcion;

    if(strcmp(miMascota.tipo,"Gato")==0)
    {
        do
        {
            printf("-----------------------------------------RAZAS DISPONIBLES------------------------------------------------------------------------\n");
            printf("| %20s | %20s |\n", "RAZA", "PAIS");
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("1- %20s | %20s |\n", "Bengala", "Angola");
            printf("2- %20s |\n", "Ragdoll", "Libia");
            printf("3- %20s | %20s |\n", "Munchkin", "Alemania");
            printf("4- %20s | %20s |\n", "Maine Coon", "Argentina");
            printf("5- %20s | %20s |\n", "Sphynx", "Emiratos Arabes");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    strcpy(miMascota.raza.nombreRaza,"Bengala");
                    strcpy(miMascota.raza.pais,"Angola");
                    break;
                case 2:
                    strcpy(miMascota.raza.nombreRaza,"Ragdoll");
                    strcpy(miMascota.raza.pais,"Libia");
                    break;
                case 3:
                    strcpy(miMascota.raza.nombreRaza,"Munchkin");
                    strcpy(miMascota.raza.pais,"Alemania");
                    break;
                case 4:
                    strcpy(miMascota.raza.nombreRaza,"Maine Coon");
                    strcpy(miMascota.raza.pais,"Argentina");
                    break;
                case 5:
                    strcpy(miMascota.raza.nombreRaza,"Sphynx");
                    strcpy(miMascota.raza.pais,"Emiratos Arabes");
                    break;
            }
        }while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5);
    }

    if(strcmp(miMascota.tipo,"Perro")==0)
    {
        do
        {
            printf("-----------------------------------------RAZAS DISPONIBLES------------------------------------------------------------------------\n");
            printf("| %20s | %20s |\n", "RAZA", "PAIS");
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("1- %20s | %20s |\n", "Golden Retreiver", "Noruega");
            printf("2- %20s | %20s |\n", "Salchicha", "Arabia Saudita");
            printf("3- %20s | %20s |\n", "Bulldog", "Frances");
            printf("4- %20s | %20s |\n", "Pitbull", "Islas Feroes");
            printf("5- %20s | %20s |\n", "Labrador", "China");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    strcpy(miMascota.raza.nombreRaza,"Golden Retreiver");
                    strcpy(miMascota.raza.pais,"Noruega");
                    break;
                case 2:
                    strcpy(miMascota.raza.nombreRaza,"Salchicha");
                    strcpy(miMascota.raza.pais,"Arabia Saudita");
                    break;
                case 3:
                    strcpy(miMascota.raza.nombreRaza,"Bulldog");
                    strcpy(miMascota.raza.pais,"Frances");
                    break;
                case 4:
                    strcpy(miMascota.raza.nombreRaza,"Pitbull");
                    strcpy(miMascota.raza.pais,"Islas Feroes");
                    break;
                case 5:
                    strcpy(miMascota.raza.nombreRaza,"Labrador");
                    strcpy(miMascota.raza.pais,"China");
                    break;
            }
        }while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5);
    }

    if(strcmp(miMascota.tipo,"Raro")==0)
    {
        do
        {
            printf("-----------------------------------------RAZAS DISPONIBLES------------------------------------------------------------------------\n");
            printf("| %20s | %20s |\n", "RAZA", "PAIS");
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("1- %20s | %20s |\n", "Iguana", "Fiji");
            printf("2- %20s | %20s |\n", "Cocodrilo", "Madagascar");
            printf("3- %20s | %20s |\n", "Jirafa", "Costa de Marfil");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    strcpy(miMascota.raza.nombreRaza,"Iguana");
                    strcpy(miMascota.raza.pais,"Fiji");
                    break;
                case 2:
                    strcpy(miMascota.raza.nombreRaza,"Cocodrilo");
                    strcpy(miMascota.raza.pais,"Madagascar");
                    break;
                case 3:
                    strcpy(miMascota.raza.nombreRaza,"Jirafa");
                    strcpy(miMascota.raza.pais,"Costa de Marfil");
                    break;
            }
        }while(opcion!=1&&opcion!=2&&opcion!=3);
    }
    /*printf("Raza: ");
    fflush(stdin);
    fgets(&miMascota.raza.nombreRaza,51,stdin);
    miMascota.raza.nombreRaza[strlen( miMascota.raza.nombreRaza)-1]='\0';
    printf("Pais de Raza: ");
    fflush(stdin);
    fgets(&miMascota.raza.pais,51,stdin);
    miMascota.raza.pais[strlen( miMascota.raza.pais)-1]='\0';*/
    printf("Edad: ");
    scanf("%d",&miMascota.edad);
    printf("Peso: ");
    scanf("%f",&miMascota.peso);
    printf("Genero: ");
    scanf("%s",&miMascota.sexo);
    fflush(stdin);
    printf("ID Cliente: ");
    scanf("%d",&miMascota.idCliente);

    miMascota.estado = OCUPADO;

    return miMascota;
}

void cargarListadoDeMascotas(eMascota listado[], int tam)
{
    int index;
    index = buscarLibreMascota(listado,tam);
    if(index!=-1)
    {
       listado[index] = cargarUnaMascota();
       listado[index].idMascota = index + 1;
       //mostraRazasyPaises(listado[index],tam,index);
    }
    else
    {
        printf("------------------------------\n");
        printf("ERROR! No hay mas espacio!\n");
        printf("------------------------------\n\n");
    }
}

void mostrarListadoDeMascotas(eMascota listado[], int tam)
{
    int i;
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%10s | %30s | %5s | %20s | %20s | %8s | %5s | %10s |\n","ID MASCOTA","NOMBRE","TIPO","RAZA", "PAIS", "EDAD","PESO","SEXO");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");
    for(i=0; i<tam; i++)
    {
       if(listado[i].estado == OCUPADO)
        {
            mostrarUnaMascota(listado[i]);
        }
    }
}

void mostrarUnaMascota(eMascota miMascota)
{
    printf("%10d | %30s | %5s | %20s | %20s | %8d | %4.2f | %10s |\n",   miMascota.idMascota,
                                                                         miMascota.nombre,
                                                                         miMascota.tipo,
                                                                         miMascota.raza.nombreRaza,
                                                                         miMascota.raza.pais,
                                                                         miMascota.edad,
                                                                         miMascota.peso,
                                                                         miMascota.sexo);
}

void eliminarUnaMascota(eMascota listaMascota[], int sizeMascotas)
{
    int idMascota;
    printf("Ingrese el ID de la mascota a eliminar: ");
    scanf("%d", &idMascota);

    int i;
    char confirmacion;
    for(i=0; i<sizeMascotas; i++)
    {
        if(listaMascota[i].estado == OCUPADO && idMascota == listaMascota[i].idMascota)
        {
            printf("Desea eliminar la mascota %s?(s/n): ", listaMascota[i].nombre);
            fflush(stdin);
            scanf("%c",&confirmacion);
            if(confirmacion == 's')
            {
                listaMascota[i].estado = LIBRE;
                printf("Mascota eliminado del registro.\n\n");
                break;
            }
            else
            {
                if(confirmacion == 'n')
                {
                    printf("No se elimino la mascota del registro\n\n");
                }
            }
        }
    }
}

void modificarMascota(eMascota listado[], int sizeMascotas)
{
    int idMascota;
    printf("Ingrese el ID de la mascota a modificar: ");
    scanf("%d", &idMascota);

    int i;
    char confirmacion;
    for(i=0; i<sizeMascotas; i++)
    {
        if(listado[i].estado == OCUPADO && idMascota == listado[i].idMascota)
        {
            printf("Desea modificar la mascota %s?(s/n): ", listado[i].nombre);
            fflush(stdin);
            scanf("%c",&confirmacion);
            if(confirmacion == 's')
            {
                printf("Nombre: ");
                //scanf("%s",&listado[i].nombre);
                fflush(stdin);
                fgets(&listado[i].nombre,51,stdin);
                listado[i].nombre[strlen( listado[i].nombre)-1]='\0';
                printf("Tipo (Gato-Perro-Raro): ");
                scanf("%s",&listado[i].tipo);
                fflush(stdin);
                printf("Raza: ");
                fflush(stdin);
                fgets(&listado[i].raza.nombreRaza,51,stdin);
                listado[i].raza.nombreRaza[strlen( listado[i].raza.nombreRaza)-1]='\0';
                printf("Pais de Raza: ");
                fflush(stdin);
                fgets(&listado[i].raza.pais,51,stdin);
                listado[i].raza.pais[strlen( listado[i].raza.pais)-1]='\0';
                printf("Edad: ");
                scanf("%d",&listado[i].edad);
                printf("Peso: ");
                scanf("%f",&listado[i].peso);
                printf("Genero: ");
                scanf("%s",&listado[i].sexo);
                fflush(stdin);
                break;
            }
            else
            {
                if(confirmacion == 'n')
                {
                    printf("No se modifico la mascota\n\n");
                }
            }
        }
    }
}

void ordenarMascotasPorTipo(eMascota listaMascotas[], int sizeMascota)
{
    int i, j;
    eMascota aux;

    for(i=0;i<sizeMascota-1;i++)
    {
        for(j=i+1;j<sizeMascota;j++)
        {
            if(strcmp(listaMascotas[i].tipo,listaMascotas[j].tipo)>0)
            {
                aux=listaMascotas[i];
                listaMascotas[i]=listaMascotas[j];
                listaMascotas[j]=aux;
            }
        }
    }
}

void mostrarListadoDeMascotasEligiendoTipo(eMascota listado[], int tam)
{
    int i, opcion;
    do
    {
        printf("-----------LISTAR MASCOTAS POR TIPO-----------\n");
        printf("1- LISTA DE GATOS\n");
        printf("2- LISTA DE PERROS\n");
        printf("3- LISTA DE ANIMALES RAROS\n");
        printf("4- VOLVER\n");
        scanf("%d",&opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%10s | %30s | %5s | %20s | %8s | %5s | %10s |\n","ID MASCOTA","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                for(i=0; i<tam; i++)
                {
                    if(listado[i].estado == OCUPADO && strcmp(listado[i].tipo,"Gato")==0)
                    {
                        mostrarUnaMascota(listado[i]);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 2:
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%10s | %30s | %5s | %20s | %8s | %5s | %10s |\n","ID MASCOTA","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                for(i=0; i<tam; i++)
                {
                    if(listado[i].estado == OCUPADO && strcmp(listado[i].tipo,"Perro")==0)
                    {
                        mostrarUnaMascota(listado[i]);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 3:
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                printf("%10s | %30s | %5s | %20s | %8s | %5s | %10s |\n","ID MASCOTA","NOMBRE","TIPO","RAZA","EDAD","PESO","SEXO");
                printf("------------------------------------------------------------------------------------------------------------------------------\n");
                for(i=0; i<tam; i++)
                {
                    if(listado[i].estado == OCUPADO && strcmp(listado[i].tipo,"Raro")==0)
                    {
                        mostrarUnaMascota(listado[i]);
                    }
                }
                system("pause");
                system("cls");
                break;
            case 4:
                break;
            default:
                printf("Opcion incorrecta!\n");
                system("pause");
                system("cls");
        }
    }while(opcion!=4);
}

void promedioEdadMascotas(eMascota listado[], int tam)
{
    int i;
    int contMascotas = 0;
    float sumaEdad = 0;
    float promedioEdad = 0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            sumaEdad += listado[i].edad;
            contMascotas++;
        }
    }
    promedioEdad = (float)(sumaEdad / contMascotas);

    printf("El promedio de edad entre las mascotas es de %.2f\n",promedioEdad);
}

void promedioEdadMascotasPorTipo(eMascota listado[], int tam)
{
    int i;
    int contMascotasGato = 0;
    int contMascotasPerro = 0;
    int contMascotasRaro = 0;
    float sumaEdadGato = 0;
    float sumaEdadPerro = 0;
    float sumaEdadRaro = 0;
    float promedioEdadGato = 0;
    float promedioEdadPerro = 0;
    float promedioEdadRaro = 0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            if(strcmp(listado[i].tipo,"Gato")==0)
            {
                sumaEdadGato += listado[i].edad;
                contMascotasGato++;
            }
            else if(strcmp(listado[i].tipo,"Perro")==0)
            {
                sumaEdadPerro += listado[i].edad;
                contMascotasPerro++;
            }
            else if(strcmp(listado[i].tipo,"Raro")==0)
            {
                sumaEdadRaro += listado[i].edad;
                contMascotasRaro++;
            }
        }
    }
    promedioEdadGato = (float)(sumaEdadGato / contMascotasGato);
    promedioEdadPerro = (float)(sumaEdadPerro / contMascotasPerro);
    promedioEdadRaro = (float)(sumaEdadRaro / contMascotasRaro);

    printf("El promedio de edad entre las mascotas de tipo GATO es de %.2f\n",promedioEdadGato);
    printf("El promedio de edad entre las mascotas de tipo PERRO es de %.2f\n",promedioEdadPerro);
    printf("El promedio de edad entre las mascotas de tipo RARO es de %.2f\n",promedioEdadRaro);
}

/*void mostraRazasyPaises(eMascota listado, int tam,int i)
{
    int opcion;

    if(strcmp(listado.tipo,"Gato")==0)
    {
        do
        {
            printf("-----------------------------------------RAZAS DISPONIBLES------------------------------------------------------------------------\n");
            printf("| %20s | %20s |\n", "RAZA", "PAIS");
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("1- %20s | %20s |\n", "Bengala", "Angola");
            printf("2- %20s |\n", "Ragdoll", "Libia");
            printf("3- %20s | %20s |\n", "Munchkin", "Alemania");
            printf("4- %20s | %20s |\n", "Maine Coon", "Argentina");
            printf("5- %20s | %20s |\n", "Sphynx", "Emiratos Arabes");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    strcpy(listado[i].raza.nombreRaza,"Bengala");
                    strcpy(listado[i].raza.pais,"Angola");
                    break;
                case 2:
                    strcpy(listado[i].raza.nombreRaza,"Ragdoll");
                    strcpy(listado[i].raza.pais,"Libia");
                    break;
                case 3:
                    strcpy(listado[i].raza.nombreRaza,"Munchkin");
                    strcpy(listado[i].raza.pais,"Alemania");
                    break;
                case 4:
                    strcpy(listado[i].raza.nombreRaza,"Maine Coon");
                    strcpy(listado[i].raza.pais,"Argentina");
                    break;
                case 5:
                    strcpy(listado[i].raza.nombreRaza,"Sphynx");
                    strcpy(listado[i].raza.pais,"Emiratos Arabes");
                    break;
            }
        }while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5);
    }

    if(strcmp(listado.tipo,"Perro")==0)
    {
        do
        {
            printf("-----------------------------------------RAZAS DISPONIBLES------------------------------------------------------------------------\n");
            printf("| %20s | %20s |\n", "RAZA", "PAIS");
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("1- %20s | %20s |\n", "Golden Retreiver", "Noruega");
            printf("2- %20s | %20s |\n", "Salchicha", "Arabia Saudita");
            printf("3- %20s | %20s |\n", "Bulldog", "Frances");
            printf("4- %20s | %20s |\n", "Pitbull", "Islas Feroes");
            printf("5- %20s | %20s |\n", "Labrador", "China");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    strcpy(listado[i].raza.nombreRaza,"Golden Retreiver");
                    strcpy(listado[i].raza.pais,"Noruega");
                    break;
                case 2:
                    strcpy(listado[i].raza.nombreRaza,"Salchicha");
                    strcpy(listado[i].raza.pais,"Arabia Saudita");
                    break;
                case 3:
                    strcpy(listado[i].raza.nombreRaza,"Bulldog");
                    strcpy(listado[i].raza.pais,"Frances");
                    break;
                case 4:
                    strcpy(listado[i].raza.nombreRaza,"Pitbull");
                    strcpy(listado[i].raza.pais,"Islas Feroes");
                    break;
                case 5:
                    strcpy(listado[i].raza.nombreRaza,"Labrador");
                    strcpy(listado[i].raza.pais,"China");
                    break;
            }
        }while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5);
    }

    if(strcmp(listado.tipo,"Raro")==0)
    {
        do
        {
            printf("-----------------------------------------RAZAS DISPONIBLES------------------------------------------------------------------------\n");
            printf("| %20s | %20s |\n", "RAZA", "PAIS");
            printf("----------------------------------------------------------------------------------------------------------------------------------\n");
            printf("1- %20s | %20s |\n", "Iguana", "Fiji");
            printf("2- %20s | %20s |\n", "Cocodrilo", "Madagascar");
            printf("3- %20s | %20s |\n", "Jirafa", "Costa de Marfil");
            printf("Elija una opcion: ");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    strcpy(listado[i].raza.nombreRaza,"Iguana");
                    strcpy(listado[i].raza.pais,"Fiji");
                    break;
                case 2:
                    strcpy(listado[i].raza.nombreRaza,"Cocodrilo");
                    strcpy(listado[i].raza.pais,"Madagascar");
                    break;
                case 3:
                    strcpy(listado[i].raza.nombreRaza,"Jirafa");
                    strcpy(listado[i].raza.pais,"Costa de Marfil");
                    break;
            }
        }while(opcion!=1&&opcion!=2&&opcion!=3);
    }
}*/
