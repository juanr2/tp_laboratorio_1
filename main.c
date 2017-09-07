#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>




int main()
{
    char opcion;
    int intOption,i;
    char seguir='s';
    int flagOp1=0,flagOp2=0,r;
    float primerOperando=0, segundoOperando=0;
    char str[100];

    printf("\n\n***********************CALCULADORA***********************\n\n");
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=%f)\n",primerOperando);
        printf("2- Ingresar 2do operando (B=%f)\n", segundoOperando);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");


        printf("\n\nELIJA UNA OPCION: ");
        fflush(stdin);
        opcion=getche();
        printf("\n");

        while(opcion < '1' || opcion > '9')
        {
            printf("Error: debe seleccionar una opcion entre 1 y 9.\n");
            printf("\n\nELIJA UNA OPCION: ");
            fflush(stdin);
            opcion=getche();
            printf("\n");

        }


        switch(opcion)
        {
        case '1':



            printf("INGRESE EL PRIMER OPERANDO:");
            fflush(stdin);
            scanf("%s",str);

            while(funcionValidar(str)==0)
            {

                printf("ERROR: EL VALOR CARGADO NO CORRESPONDE A UN NUMERO\n");
                printf("CARGUE UN NUEVO NUMERO: ");
                fflush(stdin);
                scanf("%s",str);
            }

            printf("CARGA EXITOSA");


            fflush(stdin);
            primerOperando=atof(str);

        flagOp1=1;


        break;
    case '2':
            printf("INGRESE EL SEGUNDO OPERANDO:");
            fflush(stdin);
            scanf("%s",str);

            while(funcionValidar(str)==0)
            {

                printf("ERROR: EL VALOR CARGADO NO CORRESPONDE A UN NUMERO\n");
                printf("CARGUE UN NUEVO NUMERO: ");
                fflush(stdin);
                scanf("%s",str);
            }

            printf("CARGA EXITOSA");


            fflush(stdin);
            segundoOperando=atof(str);


        flagOp2=1;

        break;
    case '3':
        r=funcionFlag(flagOp1,flagOp2);

        if(r==1)
        {

            printf("\nLa suma entre %f y %f es : %f\n\n",primerOperando,segundoOperando,funcionSuma(primerOperando,segundoOperando));


        }
        system("pause");
        break;
    case '4':

        r=funcionFlag(flagOp1,flagOp2);

        if(r==1)
        {


            printf("\nLa resta entre %f y %f es : %f\n\n",primerOperando,segundoOperando,funcionResta(primerOperando,segundoOperando));

        }

        system("pause");
        break;
    case '5':

        r=funcionFlag(flagOp1,flagOp2);

        if(r==1)
        {

            funcionDivision(primerOperando,segundoOperando);

        }

        system("pause");
        break;
    case '6':
        r=funcionFlag(flagOp1,flagOp2);

        if(r==1)
        {

            printf("\nLa multiplicacion entre %f y %f es : %f\n\n",primerOperando,segundoOperando,funcionMultiplicacion(primerOperando,segundoOperando));
        }
        system("pause");
        break;
    case '7':

        if(flagOp1==1)
        {
            printf("el factorial es : %d\n",funcionFactorial(primerOperando));
        }
        else
        {

            printf("Error: debe cargar un valor para el operador uno");
        }


        system("pause");
        break;
    case '8':
        r=funcionFlag(flagOp1,flagOp2);

        if(r==1)
        {
            printf("\nLa suma entre %f y %f es : %f\n\n",primerOperando,segundoOperando,funcionSuma(primerOperando,segundoOperando));
            printf("\nLa resta entre %f y %f es : %f\n\n",primerOperando,segundoOperando,funcionResta(primerOperando,segundoOperando));
            funcionDivision(primerOperando,segundoOperando);
            printf("\nLa multiplicacion entre %f y %f es : %f\n\n",primerOperando,segundoOperando,funcionMultiplicacion(primerOperando,segundoOperando));

        }
        if(flagOp1==1)
        {
            printf("el factorial es : %d\n",funcionFactorial(primerOperando));
        }
        else
        {

            printf("Error: el factorial no se puede calcular porque debe cargar un valor para el operador uno");
        }
        system("pause");
        break;
    case '9':
        seguir = 'n';
        break;
    }
    system("cls");

}
return 0;

}




