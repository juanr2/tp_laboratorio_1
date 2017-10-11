#include <stdio.h>
#include <stdlib.h>



typedef struct
{

    int dia;
    int mes;
    int anio;


} eFecha;

typedef struct
{

    long int dni;
    char nombre[31];
    eFecha fechaNac;

} ePersona;


ePersona per,*punteroPer,pers[5],*punteroPers5;



int main()
{
    punteroPer=&per;
    punteroPers5=pers;

    int i;

    for(i=0;i<5;i++){

        printf("ingrese el nombre:");
        fflush(stdin);
        scanf("%s",punteroPers5[i].nombre);


    }


        printf("los nombres son:");

       for(i=0;i<5;i++){


        printf("%s\n",punteroPers5[i].nombre);


    }
    printf("INGRESE EL DNI: ");
    scanf("%ld",&(*punteroPer).dni);


    printf("INGRESE EL NOMBRE");
    fflush(stdin);
    scanf("%s",punteroPer->nombre);

    printf("INGRESE EL DIA DE NACIMIENTO: ");
    scanf("%d",&(*punteroPer).fechaNac.dia);

    printf("INGRESE EL MES DE NACIMIENTO: ");
    scanf("%d",&punteroPer->fechaNac.mes);

    printf("INGRESE EL MES DE ANIO: ");
    scanf("%d",&punteroPer->fechaNac.anio);

    printf("\nel nombre es:%s",punteroPer->nombre);
    printf("\nel dni es:%ld",punteroPer->dni);
    printf("\nla fecha de nacimiento es:%d",(*punteroPer).fechaNac.dia);


    return 0;
}
