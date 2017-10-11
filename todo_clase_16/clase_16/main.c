#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"




int main()
{
    char nombre[30];


    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s",nombre);
    mostrarCadena(nombre);

  //  printf("%d",sizeof (2));
    return 0;
}



