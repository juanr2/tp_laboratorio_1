#include "funciones.h"
#include<string.h>
#include<stdio.h>

int obtenerEspacioLibre(EPersona lista[],int cant){

int i;

for(i=0;i<cant;i++){


    if(lista[i].estado==0){


        return i;
    }
}
    return -1;
}




int funcionValidar(char validar[]){

int i=0;

while(validar[i]!='\0'){

    if((validar[i]<'a'||validar[i]>'z')&&(validar[i]<'A'||validar[i]>'Z')&&(validar[i]!='\n')&&(validar[i]!=' '))

        return 0;



    i++;

}
return 1;
}


int buscarPorDni(EPersona lista[], int dni,int cant){
int i=0;

for(i=0;i<cant;i++){

    if(lista[i].dni==dni)
    {
        return i;
        break;
    }

}

return -1;

}


int funcionValidarNumeros(char validar[])
{

    int i=0;

    while(validar[i]!='\0')
    {

        if(validar[i]<'0'||validar[i]>'9')

            return 0;



        i++;

    }
    return 1;
}

void funcionOrdenar(EPersona pers[],int cant){

   int auxEdad,auxDni,auxEstado,i,j;
   char aux[50];





            for(i=0; i<cant-1; i++)
            {
                for(j=i+1; j<cant; j++)
                {
                    if(strcmp(pers[i].nombre,pers[j].nombre)>0)
                    {


                        strcpy(aux,pers[i].nombre);
                        strcpy(pers[i].nombre,pers[j].nombre);
                        strcpy(pers[j].nombre,aux);


                        auxEdad=pers[i].edad;
                        pers[i].edad=pers[j].edad;
                        pers[j].edad=auxEdad;

                        auxEstado=pers[i].estado;
                        pers[i].estado=pers[j].estado;
                        pers[j].estado=auxEstado;

                        auxDni=pers[i].dni;
                        pers[i].dni=pers[j].dni;
                        pers[j].dni=auxDni;

                    }

                    if(strcmp(pers[i].nombre,pers[j].nombre)==0)
                    {

                        if(pers[i].dni>pers[j].dni)
                        {

                            strcpy(aux,pers[i].nombre);
                            strcpy(pers[i].nombre,pers[j].nombre);
                            strcpy(pers[j].nombre,aux);


                            auxEdad=pers[i].edad;
                            pers[i].edad=pers[j].edad;
                            pers[j].edad=auxEdad;

                            auxEstado=pers[i].estado;
                            pers[i].estado=pers[j].estado;
                            pers[j].estado=auxEstado;

                            auxDni=pers[i].dni;
                            pers[i].dni=pers[j].dni;
                            pers[j].dni=auxDni;


                        }
                    }



                }
            }



}

void funcionImprimirOrdenados(EPersona pers[],int cant){

 int i=0;



            for(i=0; i<cant; i++)
            {
                if(pers[i].estado==1){

                    if((strlen(pers[i].nombre))<8)
                {
                    printf("%s\t\t\t", pers[i].nombre );
                }
                else{
                 printf("%s\t\t", pers[i].nombre );
                }

                printf("%d\t", pers[i].edad );
                printf("%d\t", pers[i].estado );
                printf("%d\n", pers[i].dni );
                }




            }

 }

void funcionGraficar(EPersona pers[],int cantidad){
    int i;
        int contA=0,contB=0,contC=0;
         int mayor=0;
         int j;
 for(i=0; i<cantidad; i++)
            {


                if((pers[i].edad<=18)&&(pers[i].estado==1))
                {

                    contA++;



                }
                else
                {

                    if((pers[i].edad<=35)&&(pers[i].estado==1))
                    {

                        contB++;
                    }
                    else
                    {
                        if((pers[i].edad>35)&&(pers[i].estado==1))
                            contC++;
                    }
                }
            }


            int contadores[3] = {contA, contB, contC};

            for (i = 0; i < 3; i++)
            {




                if (contadores[i] > mayor)
                    mayor = contadores[i];

            }

            for (i = mayor; i > 0; i--)
            {
                for (j = 0; j < 3; j++)
                {
                    if (contadores[j] >= i){
                         printf(" *");

                    }





                    else{

                       printf("  ");
                    }

                    printf("\t");
                }

                    printf("\n");
            }

}

