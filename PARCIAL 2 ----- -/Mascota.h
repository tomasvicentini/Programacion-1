typedef struct
{
    char nombreRaza[51];
    char pais[51];
}eRaza;
typedef struct
{
    int idMascota;
    char nombre[51];
    char tipo[10];
    //char raza[51];
    eRaza raza;
    int edad;
    float peso;
    char sexo[10];

    int estado;
    int idCliente;
}eMascota;


void hardcodearMascotas(eMascota listaMascotas[], int tam);
void inicializarMascotas(eMascota listaMascotas[], int tam);
int buscarLibreMascota(eMascota* listado, int tam);
eMascota cargarUnaMascota(void);
void cargarListadoDeMascotas(eMascota listado[], int tam);
void mostrarUnaMascota(eMascota miMascota);
void mostrarListadoDeMascotas(eMascota listado[], int tam);
void eliminarUnaMascota(eMascota listaMascota[], int sizeMascotas);
void modificarMascota(eMascota listado[], int sizeMascotas);
void ordenarMascotasPorTipo(eMascota listaMascotas[], int sizeMascota);
void mostrarListadoDeMascotasEligiendoTipo(eMascota listado[], int tam);
void promedioEdadMascotas(eMascota listado[], int tam);
void promedioEdadMascotasPorTipo(eMascota listado[], int tam);
//void mostraRazasyPaises(eMascota listado, int tam, int i);
