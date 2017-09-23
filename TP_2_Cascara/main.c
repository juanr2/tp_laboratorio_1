#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define CANTIDAD 20



int main()
{

    EPersona pers[CANTIDAD];

    int indiceLibre,indiceDni;
    int i,auxN,auxNum,flag=0;
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
    {   printf("--------MENU PRINCIPAL--------");
        printf("\n\n\n\n");
        printf("1- AGREGAR PERSONA\n");
        printf("2- BORRAR PERSONA\n");
        printf("3- IMPRIMIR LISTA ORDENADA POR NOMBRE\n");
        printf("4- IMPRIMIR GRAFICO DE EDADES\n");
        printf("5- SALIR\n");

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
            scanf("%[^\n]", auxNombre);
            auxN=funcionValidar(auxNombre);

            while(auxN==0)
            {

                printf("ERROR: SOLO SE PERMITEN LETRAS\n ");
                printf("INGRESE EL NOMBRE: ");
                fflush(stdin);
                scanf("%s", auxNombre);
                auxN=funcionValidar(auxNombre);

            }

            strlwr(auxNombre);
            auxNombre[0]=toupper(auxNombre[0]);

            strcpy(pers[indiceLibre].nombre,auxNombre);


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

            if((atoi(auxiliarNumero)<0)||(atoi(auxiliarNumero)>120)){

                printf("ERROR GRAVE: NO EXISTEN EDADES MENORES A CERO O MAYORES A 120\n\n");
                printf("REALIZAR NUEVAMENTE LA CARGA COMPLETA DEL REGISTRO. GRACIAS\n");

                system("pause");
                system("cls");
                break;
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

            flag=1;


            system("pause");
            system("cls");

            break;

        case '2':

            if(flag==0){

                printf("ERROR: DEBE CARGAR AL MENOS UN REGISTRO EN LA OPCION UNO.\n");
                system("pause");
                system("cls");

                break;
            }

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

            if(flag==0){

                printf("ERROR: DEBE CARGAR AL MENOS UN REGISTRO EN LA OPCION UNO.\n");
                system("pause");
                system("cls");

                break;
            }

            for(i=0; i<CANTIDAD; i++)
            {

                if(pers[i].estado==1)
                {

                    contadorPrincipal++;
                }

            }



            funcionOrdenar(pers,contadorPrincipal);

            printf("\n\n\nREGISTRO ORDENADO POR NOMBRE\n\n\n");
            printf("NOMBRE\t\t\tEDAD\tESTADO\tDNI\n\n");

            funcionImprimirOrdenados(pers,contadorPrincipal);
            printf("\n\n\n");
            system("pause");
            system("cls");


            break;
        case '4':
            if(flag==0){

                printf("ERROR: DEBE CARGAR AL MENOS UN REGISTRO EN LA OPCION UNO.\n");
                system("pause");
                system("cls");

                break;
            }
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
            printf(">18\t19-35\t>35\n");
            break;
        case '5':
            seguir = 'n';
            break;
        }
    }

    return 0;
}

