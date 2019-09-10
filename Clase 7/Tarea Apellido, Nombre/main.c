#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

   char nombre[20];
   char apellido[20];
   char auxString[1000];
   int i;
   int len;
   char apellidoNombre[45]; // Apellido, Nombre .... Por ejem: Scarafilo, German

   printf("Ingrese su nombre: ");
   fflush(stdin);
   gets(auxString);
   while(strlen(auxString)>19)
   {
       printf("Reingrese su nombre: ");
       fflush(stdin);
       gets(auxString);
   }
   strcpy(nombre, auxString);

   printf("Ingrese su apellido: ");
   fflush(stdin);
   gets(auxString);
   while(strlen(auxString)>19)
   {
       printf("Reingrese su apellido: ");
       fflush(stdin);
       gets(auxString);
   }
   strcpy(apellido, auxString);

   strcpy(apellidoNombre, apellido);
   strcat(apellidoNombre, ", ");
   strcat(apellidoNombre, nombre);

   len = strlen(apellidoNombre);
   for(i=0; i<len; i++)
   {
       apellidoNombre
   }
    return 0;
}
