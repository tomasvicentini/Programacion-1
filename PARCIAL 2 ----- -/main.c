#include <stdio.h>
#include <stdlib.h>
#include "Cliente-Mascota.h"
#define CLIENTES 10
#define MASCOTAS 20
#define LIBRE 0
#define OCUPADO 1

int main()
{
    int opcion;

    eCliente listaClientes[CLIENTES]; /*= { {1,"Gisela","Dulko","Docksud",42008080,45,"Femenino",OCUPADO},
                                            {2,"Thierry","Henry","Paris",31125494,41,"Masculino",OCUPADO},
                                            {3,"Gabriela","Sabatini","Cordoba",48024818,20,"Femenino",OCUPADO},
                                            {4,"Dennis","Bergkamp","Amsterdan",71821122,18,"Masculino",OCUPADO},
                                            {5,"Juan Roman","Riquelme","Don Torcuato",46012081,44,"Masculino",OCUPADO}
                                       };*/
    eMascota listaMascotas[MASCOTAS]; /*= { {1,"Charly","Gato","Bengala",10,15,"Hembra",OCUPADO,1},
                                            {2,"Wisky","Gato","Ragdoll",2,11,"Hembra",OCUPADO,1},
                                            {3,"Foxtrot","Perro","Golden Retreiver",5,30,"Macho",OCUPADO,2},
                                            {4,"Alfa","Perro","Salchicha",1,18,"Macho",OCUPADO,2},
                                            {5,"Tekila","Gato","Munchkin",8,12,"Macho",OCUPADO,2},
                                            {6,"Beta","Perro","Pitbull",10,45,"Macho",OCUPADO,3},
                                            {7,"Mike","Raro","Iguana",2,11,"Hembra",OCUPADO,3},
                                            {8,"Echo","Perro","Labrador",6,38,"Macho",OCUPADO,4},
                                            {9,"November","Gato","Sphynx",1,18,"Macho",OCUPADO,5},
                                            {10,"Kilo","Gato","Maine Coon",8,12,"Macho",OCUPADO,5},
                                            {11,"Oscar","Perro","Bulldog",8,12,"Macho",OCUPADO,5}
                                       };*/

    inicializarClientes(listaClientes,CLIENTES);
    inicializarMascotas(listaMascotas,MASCOTAS);
    hardcodearClientes(listaClientes,10);
    hardcodearMascotas(listaMascotas,20);

    do
    {
        printf("-----------MENU DE OPCIONES-----------\n");
        printf("1- LISTADO DE CLIENTES\n");
        printf("2- LISTADO DE MASCOTAS\n");
        printf("3- LISTADO DE CLIENTES CON MASCOTAS\n");
        printf("4- ALTA DE MASCOTA\n");
        printf("5- BAJA DE MASCOTA\n");
        printf("6- MODIFICAR MASCOTA\n");
        printf("7- ALTA DUENIO\n");
        printf("8- BAJA DE DUENIO\n");
        printf("9- ORDENAR MASCOTAS POR TIPO\n");
        printf("10- MODIFICAR DUENIOS\n");
        printf("11- LISTAR CLIENTES CON MAS DE 1 MASCOTA\n");
        printf("12- LISTAR MASCOTAS DE MAS DE TRES ANIOS\n");
        printf("13- LISTAR MASCOTAS POR TIPO\n");
        printf("14- ORDENAR DUENIOS POR CANTIDAD DE MASCOTAS\n");
        printf("15- ORDENAR DUENIOS POR CANTIDAD DE MASCOTAS Y POR ORDEN ALFABETICO DE NOMBRES\n");
        printf("16- PROMEDIO DE EDAD ENTRE LAS MASCOTAS\n");
        printf("17- PROMEDIO DE EDAD ENTRE LAS MASCOTAS POR TIPO\n");
        printf("18- PROMEDIO DE MUJERES Y VARONES CLIENTES\n");
        printf("19- SALIR\n");
        printf("--------------------------------------\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        system("cls");

        switch(opcion)
        {
            case 1:
                mostrarListadoDeClientes(listaClientes,CLIENTES);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                mostrarListadoDeMascotas(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 3:
                mostrarClienteConSusMascotas(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 4:
                mostrarListadoDeClientes(listaClientes,CLIENTES);
                cargarListadoDeMascotas(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 5:
                mostrarListadoDeMascotas(listaMascotas,MASCOTAS);
                eliminarUnaMascota(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                mostrarListadoDeMascotas(listaMascotas,MASCOTAS);
                modificarMascota(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 7:
                cargarListadoDeClientes(listaClientes,CLIENTES);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 8:
                mostrarClienteConSusMascotas(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                eliminarClienteConSusMascotas(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 9:
                ordenarMascotasPorTipo(listaMascotas,MASCOTAS);
                mostrarListadoDeMascotasConClientes(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 10:
                mostrarListadoDeClientes(listaClientes,CLIENTES);
                modificarCliente(listaClientes,CLIENTES);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 11:
                mostrarClienteConMasDeUnaMascota(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 12:
                mostrarListadoDeMascotasConMasDeTresAnioConClientes(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 13:
                mostrarListadoDeMascotasEligiendoTipo(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 14:
                contarMascotasDeTodosLosClientes(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 15:
                contarMascotasDeTodosLosClientesYOrdenarPorCantMascYporNombre(listaClientes,CLIENTES,listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 16:
                promedioEdadMascotas(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 17:
                promedioEdadMascotasPorTipo(listaMascotas,MASCOTAS);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 18:
                promedioDeMujVarClientes(listaClientes,CLIENTES);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 19:
                printf("\tHASTA LUEGO\n\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("ERROR! Opcion invalida.\n\n");
                system("pause");
                system("cls");
        }

    }while(opcion!=19);


    return 0;
}
