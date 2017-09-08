#include<stdio.h>

/** \brief recibe una cadena char y verifica si contiene solo numeros.
 *
 * \param str es una cadena char
 * \return 0 si la cadena char tiene otros caracteres además de numeros y 1 si contiene solo numeros
 *
 */
int funcionValidar(char str[])
{
    int i=0;

    while(str[i]!='\0')
    {



        if((str[i]<'0'||str[i]>'9')&&(str[i]!='.'))



            return 0;
        i++;


    }

    return 1;



}

/** \brief recibe dos numeros y calcula la suma
 *
 * \param num1 numero cargado por el usuario
 * \param num2 segundo numero cargado por el usuario
 * \return valor correspondiente a la suma de los dos parámetros que recibe la funcion
 *
 */



float funcionSuma(float num1, float num2)
{

    float result;

    result=num1+num2;

    return result;

}



/** \brief recibe dos parametros y calcula la resta
 *
 * \param num1 numero cargado por el usuario
 * \param num2 segundo numero cargado por el usuario
 * \return retorna el valor de la resta de ambos parametros.
 *
 */

float funcionResta (float num1,float num2)
{

    float result;

    result=num1-num2;

    return result;



}

/** \brief recibe dos valores , calcula la division.
 * \param num1 numero cargado por el usuario.
 * \param num2 segundo numero cargado por el usuario
 * \return el valor result que corresponde al resultado.
 *
 */

float funcionDivision(float num1,float num2)
{

    float result;


    result=num1/num2;


    return result;
}



/** \brief recibe dos numero y calcula el producto de ambos
 *
 * \param num1 numero cargado por el usuario.
 * \param num2 segundo numero cargado por el usuario
 * \param
 * \return retorna el valor del resultado del producto de ambos parámetros.
 *
 */

float funcionMultiplicacion(float num1,float num2)
{

    float result;

    result=num1*num2;

    return result;


}


/** \brief recibe un numero y calcula su factorial
 *
 * \param num es el numero cargado por el usuario en la primera posicion
 * \param
 * \return retorna el valor del factorial
 *
 */

long int funcionFactorial(int num)
{

    int factorial=1;
    int i;

    for(i=num; i>0; i--)
    {

        factorial=factorial*i;

    }



    return factorial;

}


/** \brief recibe los valores de las banderas cargadas en el menu main,, y permite o impide que las funciones se lleven a cabo
 *
 * \param banderaUno corresponde a la bandera cargada en la opcion uno del menu main
 * \param banderaDos corresponde a la segunda bandera cargada en el main.
 * \return 0 si no se cargo el primer operador, el segundo o ambos. y retorna 1 si ambos operadores fueron cargados
 *
 */

int funcionFlag(int banderaUno,int banderaDos)
{

    int retorno=0;
    if(banderaUno==1&&banderaDos==1)
    {

        retorno=1;
    }
    else
    {

        printf("ERROR: DEBE CARGAR DOS OPERADORES\n ");

    }

    return retorno;

}


