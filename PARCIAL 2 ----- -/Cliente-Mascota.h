#include "Cliente.h"
#include "Mascota.h"
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idCliente;
    int cantidadMascotas;

}eAux;


void mostrarClienteConSusMascotas(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota);
void mostrarProveedorConMasproductos(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota);
void eliminarClienteConSusMascotas(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota);

void mostrarListadoDeMascotasConClientes(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota);
void mostrarClienteConMasDeUnaMascota(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota);
void mostrarListadoDeMascotasConMasDeTresAnioConClientes(eCliente listaClientes[], int sizeCliente, eMascota listaMascotas[], int sizeMascota);
void contarMascotasDeTodosLosClientes(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota);
void contarMascotasDeTodosLosClientesYOrdenarPorCantMascYporNombre(eCliente listaClientes[],int sizeCliente, eMascota listaMascotas[], int sizeMascota);
