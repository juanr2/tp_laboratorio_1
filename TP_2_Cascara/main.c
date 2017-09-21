#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include<string.h>
#include<conio.h>
#define CANTIDAD 20



int main()
{

    EPersona pers[CANTIDAD];

    int indiceLibre,indiceDni;
    int i,auxN,auxNum;
    char auxiliarNumero[50],auxiliarDniBuscar[50];
    char auxNombre[50];

    int contadorPrincipal=0;


    for(i=0; i<CANTIDAD; i++)
    {


        pers[i].estado=0;
    }


    char seguir='s';
    char opcion;

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("\n\nELIJA UNA OPCION: ");
        fflush(stdin);
        opcion=getche();
        printf("\n");

        while(opcion < '1' || opcion > '5')
        {
            printf("Error: debe seleccionar una opcion entre 1 y 5.\n");
            printf("\n\nELIJA UNA OPCION: ");
            fflush(stdin);
            opcion=getche();
            printf("\n");

        }

        switch(opcion)
        {
        case '1':

            indiceLibre=obtenerEspacioLibre(pers,CANTIDAD);

            if(indiceLibre==-1)
            {

                printf("NO HAY LUGAR DISPONIBLE\n");
                break;
            }

            printf("INGRESE EL NOMBRE: ");
            fflush(stdin);
            scanf("%s", auxNombre);
            auxN=funcionValidar(auxNombre);

            while(auxN==0)
            {

                printf("ERROR: SOLO SE PERMITEN LETRAS ");
                printf("INGRESE EL NOMBRE: ");
                fflush(stdin);
                scanf("%s", auxNombre);
                auxN=funcionValidar(auxNombre);

            }



            strcpy(pers[indiceLibre].nombre,strupr(auxNombre));


            printf("INGRESE LA EDAD: ");
            fflush(stdin);
            scanf("%s",auxiliarNumero);



            auxNum=funcionValidarNumeros(auxiliarNumero);

            while(auxNum==0)
            {

                printf("ERROR: SOLO SE PERMITEN NUMEROS: \n");
                printf("INGRESE LA EDAD: ");
                fflush(stdin);
                scanf("%s",auxiliarNumero);
                auxNum=funcionValidarNumeros(auxiliarNumero);

            }


            pers[indiceLibre].edad=atoi(auxiliarNumero);


            printf("INGRESE EL DNI: ");
            fflush(stdin);
            scanf("%s",auxiliarNumero);
            auxNum=funcionValidarNumeros(auxiliarNumero);

            while(auxNum==0)
            {

                printf("ERROR: SOLO SE PERMITEN NUMEROS: \n");
                printf("INGRESE EL DNI: ");
                fflush(stdin);
                scanf("%s",auxiliarNumero);
                auxNum=funcionValidarNumeros(auxiliarNumero);




            }
            pers[indiceLibre].dni=atoi(auxiliarNumero);

            pers[indiceLibre].estado=1;

            system("cls");
            system("pause");

            break;

        case '2':

            printf("INGRESE EL DNI DE LA PERSONA QUE DESEA BORRAR: \n");
            scanf("%s",auxiliarDniBuscar);
            auxNum=funcionValidarNumeros(auxiliarDniBuscar);

            while(auxNum==0)
            {

                printf("ERROR: SOLO SE PERMITEN NUMEROS: \n");
                printf("INGRESE EL DNI: ");
                scanf("%s",auxiliarNumero);
                auxNum=funcionValidarNumeros(auxiliarDniBuscar);


            }

            indiceDni=buscarPorDni(pers,atoi(auxiliarDniBuscar),CANTIDAD);

            if(indiceDni==-1)
            {

                printf("EL DNI NO SE ENCUENTRA CARGADO: \n");
                break;

            }

            pers[indiceDni].estado=0;
            pers[indiceDni].dni=0;
            pers[indiceDni].edad=0;



            break;
        case '3':

            for(i=0; i<CANTIDAD; i++)
            {

                if(pers[i].estado==1)
                {

                    contadorPrincipal++;
                }

            }

            printf("NOMBRE\tEDAD\tESTADO\tDNI\n");

              for(i=0; i<contadorPrincipal; i++)
            {

                printf("%s\t", pers[i].nombre );
                printf("%d\t", pers[i].edad );
                printf("%d\t", pers[i].estado );
                printf("%d\n", pers[i].dni );



            }

            funcionOrdenar(pers,contadorPrincipal);

            printf("ordenado\n");
            printf("NOMBRE\tEDAD\tESTADO\tDNI\n");

            funcionImprimirOrdenados(pers,contadorPrincipal);


            break;
        case '4':
            for(i=0; i<CANTIDAD; i++)
            {

                if(pers[i].estado==1)
                {

                    contadorPrincipal++;
                }

            }



            funcionGraficar(pers,contadorPrincipal);
            printf("\n");
            printf("-------------------\n");
            printf(">18\t18>35\t>35\n");
            break;
        case '5':
            seguir = 'n';
            break;
        }
    }

    return 0;
}

