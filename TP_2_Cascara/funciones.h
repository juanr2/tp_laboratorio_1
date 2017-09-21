#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[],int cant);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni,int cant);


/** \brief valida la cadena de caracteres
 *
 * \param array de caracteres
 * \return retorna 0 si la cadena contiene otros caracteres además de números y 1 si esta formado solo por numeros.
 *
 */

int funcionValidarNumeros(char[]);

/** \brief valida la cadena de caracteres
 *
 * \param array de caracteres
 * \return retorna 0 si la cadena contiene otros caracteres además de letras y 1 si esta formado solo por letras.
 *
 */

int funcionValidar(char[]);


/** \brief ordena la estructura según dos criterios
 *
 * \param pers array de estructura de la personas
 * \param cant es la cantidad de datos
 * \return no retorna nada
 *
 */


void funcionOrdenar(EPersona pers[],int cant);

/** \brief funcion recibe array y cantidad de elementos y los imprime en pantalla

 *
 * \param pers es el array de personas
 * \param cant es la cantidad de datos
 * \return la funcion no devuelve nada
 *
 */

void funcionImprimirOrdenados(EPersona pers[],int cant);

/** \brief funcion imprime un grafico de barras
 *
 * \param pers es el array de personas
 * \param cant representa la cantidad de elementos
 * \return la funcion no retorna nada
 *
 */

void funcionGraficar(EPersona pers[],int cantidad);

#endif // FUNCIONES_H_INCLUDED
