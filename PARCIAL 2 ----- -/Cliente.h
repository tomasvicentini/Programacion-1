typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char localidad[51];
    unsigned int telefono;
    int edad;
    char sexo[10];

    int estado;
}eCliente;

void hardcodearClientes(eCliente listaClientes[], int tam);
void inicializarClientes(eCliente listaClientes[], int tam);
int buscarLibreCliente(eCliente* listado, int tam);
eCliente cargarUnCliente(void);
void cargarListadoDeClientes(eCliente listado[], int tam);
void mostrarUnCliente(eCliente miCliente);
void mostrarListadoDeClientes(eCliente listado[], int tam);

void modificarCliente(eCliente listado[], int sizeClientes);

void mostrarClientesOrdenadosPorContadorDeMascotas(eCliente* listaClientes, int sizeCliente, int* cont);

void mostrarClientesOrdenadosPorContadorDeMascotasYporNombres(eCliente* listaClientes, int sizeCliente, int* cont);
void promedioDeMujVarClientes(eCliente listado[], int tam);
