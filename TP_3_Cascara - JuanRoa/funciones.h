#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie,EMovie auxMovie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie movie, char nombre[]);

/**
* \brief Solicita un número al usuario y lo valida
* \param message Es el mensaje a ser mostrado
* \param errorMensaje mensaje en caso de existencia de un caracter que no sea numerico
* \param eMessage Es el mensaje a ser mostrado en caso de error de extension del string
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return devuelve un numero entero validado
*
*/
int getMenu(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit);


/** \brief solicita la carga de un dato por pantalla, evalua su extensión y lo carga en un campo pertenciente a un puntero de estructura
 *
 * \param char Message mensaje que solicita la carga.
 * \param char eMessage mensaje de error
 * \param emovie *movie puntero a estructura
 * \param int lowLimit valor minimo de carga
 * \param int highLimit valor maximio de carga
 * \return no retorna nada.
 *
 */
void getLength(char Message[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit);


/** \brief solicita la carga de un dato por pantalla, evalua su extensión y lo carga en un campo pertenciente a un puntero auxiliar de estructura
 *
 * \param char Message mensaje que solicita la carga.
 * \param char eMessage mensaje de error
 * \param emovie *movie puntero a estructura
 * \param int lowLimit valor minimo de carga
 * \param int highLimit valor maximio de carga
 * \return no retorna nada.
 *
 */
void getAuxLength(char Message[],char eMessage[],char auxPeli[], int lowLimit, int hiLimit);


/** \brief solicita la carga de un dato por pantalla, evalua su extensión y lo carga en un campo pertenciente a un puntero de estructura
 *
 * \param char Message mensaje que solicita la carga.
 * \param char eMessage mensaje de error
 * \param emovie *movie puntero a estructura
 * \param int lowLimit valor minimo de carga
 * \param int highLimit valor maximio de carga
 * \return no retorna nada.
 *
 */
void getString(char message[],char errorMensaje[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit);
int functionValidString(char mensaje[],char str[]);


/** \brief solicita la carga de un dato por pantalla, evalua su extensión y lo carga en un campo pertenciente a un puntero de estructura
 *
 * \param char Message mensaje que solicita la carga.
 * \param char eMessage mensaje de error
 * \param emovie *movie puntero a estructura
 * \param int lowLimit valor minimo de carga
 * \param int highLimit valor maximio de carga
 * \return no retorna nada.
 *
 */
void getDescription(char Message[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit);


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return devuelve un numero entero validado
*
*/
void getInt(char message[],char errorMensaje[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit);


int funcionValidarNumeros(char mensaje[],char validar[]);

/** \brief solicita la carga de un dato por pantalla, evalua su extensión y lo carga en un campo pertenciente a un puntero de estructura
 *
 * \param char Message mensaje que solicita la carga.
 * \param char eMessage mensaje de error
 * \param emovie *movie puntero a estructura
 * \param int lowLimit valor minimo de carga
 * \param int highLimit valor maximio de carga
 * \return no retorna nada.
 *
 */
void getPuntaje(char message[],char errorMensaje[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit);


/** \brief solicita la carga de un dato por pantalla, evalua su extensión y lo carga en un campo pertenciente a un puntero de estructura
 *
 * \param char Message mensaje que solicita la carga.
 * \param char eMessage mensaje de error
 * \param emovie *movie puntero a estructura
 * \param int lowLimit valor minimo de carga
 * \param int highLimit valor maximio de carga
 * \return no retorna nada.
 *
 */
void getUrl(char Message[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit);



#endif // FUNCIONES_H_INCLUDED
