#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main()
{


EMovie movie, auxMovie;

    char seguir='s';
    int opcion=0;


    while(seguir=='s')
    {

        opcion=getMenu("-------MENU PRINCIPAL-------\n\n1-AGREGAR PELICULA\n2-BORRAR PELICULA\n3-GENERAR PAGINA WEB\n4-SALIR\n\n ELIJA UNA OPCION: ","ERROR: SOLO SE PERMITEN NUMEROS!!!!","ERROR: RANGO DE SELECCION!!!! 1 AL 4",1,4);
        switch(opcion)
        {
            case 1:

            if(!agregarPelicula(movie)){

                printf("\nNO SE PUDO CARGAR LA PELICULA!!!!\n");
            }
            else{

                printf("\nPELICULA CARGADA EXITOSAMENTE!!!!\n");
            }

            system("pause");
            system("cls");

                break;
            case 2:

           if(! borrarPelicula(movie,auxMovie)){

                printf("\nNO SE PUDO BORRAR LA PELICULA!!!!\n");
            }
            else{

                printf("\nPELICULA FUE BORRADA EXITOSAMENTE!!!!\n");
            }

            system("pause");
            system("cls");


                break;
            case 3:

            generarPagina(movie, "peliculas.html");

            system("pause");
            system("cls");
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
