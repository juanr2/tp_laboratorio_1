

/** \brief recibe un número y lo carga
 *
 * \param num es el numero que recibe la función.
 * \return el valor del número que recibe
 *
 */
float funcionCargar()
{

    float num;

    printf("Ingrese el operando correspondiente: ");
    scanf("%f",&num);

    return num;

}



float funcionSuma(float num1, float num2){

float result;

result=num1+num2;

return result;

}

float funcionResta (float num1,float num2){

    float result;

    result=num1-num2;

    return result;



}


float funcionDivision(float num1,float num2){

int result;

if (num2==0){

    printf("ERROR: EL DIVISOR NO PUEDE SER IGUAL A CERO\n");
    printf("Por favor: cambie el valor del segundo operando y vuelva a realizar la operacion\n  ");

}








return result;;




}

float funcionMultiplicacion(float num1,float num2){

    int result;

    result=num1*num2;

    return result;


}



int funcionFactorial(int num){

int factorial=1;
int i;

for(i=num;i>0;i--){

   factorial=factorial*i;

}



return factorial;

}




