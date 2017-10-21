#define _GNU_SOURCE
#include<string.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


#define ESC 27



int agregarPelicula(EMovie movie)
{

    FILE  *bin;

    int cant;
    int auxChar;

    if ((bin = fopen("bin.dat","rb+"))==NULL)
    {
        if ((bin = fopen("bin.dat","wb+"))==NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }

    do
    {



        getLength("INGRESE EL TITULO: ","ERROR: PUEDE INGRESAR ENTRE 0 Y 20 CARACTERES!!!!",&movie,0,21);

        getString("INGRESE EL GENERO: ","ERROR: SOLO PUEDE INGRESAR LETRAS","ERROR: PUEDE INGRESAR ENTRE 0 Y 20 CARACTERES!!!!",&movie, 0, 20);

        getInt("INGRESE LA DURACION DE LA PELICULA EN MINUTOS: ","ERROR: SOLO PUEDE INGRESAR NUMEROS ENTEROS","ERROR: PUEDE INGRESAR VALORES ENTRE 1 Y 500 !!!!",&movie, 1, 500);

        getDescription("INGRESE UNA DESCRIPCION: ","ERROR: PUEDE INGRESAR ENTRE 0 Y 50 CARACTERES!!!!",&movie,0,50);

        getPuntaje("INGRESE EL PUNTAJE DEL 1 AL 10: ","ERROR: SOLO PUEDE INGRESAR NUMEROS ENTEROS","ERROR: PUEDE INGRESAR VALORES ENTRE 1 Y 10 !!!!",&movie, 1, 10);

        getUrl("INGRESE EL LINK: ","ERROR: PUEDE INGRESAR ENTRE 0 Y 50 CARACTERES!!!!",&movie,0,50);


        printf("\nSEGURO DESEA AGREGAR ESTA PELICULA:\n%s\t%s\t%d\t%s\t%d\t%s\nELIJA S/N:",movie.titulo,movie.genero,movie.duracion,movie.descripcion,movie.puntaje,movie.linkImagen);


        auxChar=getch();




        if(auxChar!='s'&&auxChar!='S')
        {

            system("cls");
            return 0;
        }


        fflush(stdin);
        fseek(bin, 0L, SEEK_END);
        fwrite(&movie, sizeof(movie), 1, bin);

        printf("\nPresione ESC para terminar");
    }
    while((getche())!=ESC);

    rewind(bin);


    printf("\n\n\n***************LISTADO DEL ARCHIVO******************\n\n\n");
    while(!feof(bin))
    {
        cant = fread(&movie,sizeof(EMovie),1,bin);


        if(cant!=1)
        {
            if(feof(bin))
            {
                break;
            }
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }

        fflush(stdin);
        printf("\n%s\t%s\t%d\t%s\t%d\t%s",movie.titulo,movie.genero,movie.duracion,movie.descripcion,movie.puntaje,movie.linkImagen);



    }

    fclose(bin);
    getch();

    system("cls");
    return 1;

}


void getString(char message[],char errorMensaje[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit)
{
    char auxString[256];
    int auxInt;


    while(1)
    {

        if(!functionValidString(message,auxString))
        {

            printf("%s",errorMensaje);
            printf("\n");
            system("pause");
            system("cls");
            continue;

        }


        auxInt=strlen(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");

            continue;

        }


        strcpy(movie->genero,auxString);

        break;
    }



}
int functionValidString(char mensaje[],char str[])
{


    int i=0;


    printf("\n%s",mensaje);
    fflush(stdin);
    scanf("%s",str);

    while(str[i]!='\0')
    {

        if((str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]!='\n')&&(str[i]!=' '))

            return 0;



        i++;

    }
    return 1;
}



/// ************************************FUNCION getLength**************************************
void getLength(char Message[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit)
{
    char auxString[500];
    int auxInt;



    while(1)
    {
        printf("%s ",Message);
        fflush(stdin);
        scanf("%[^\n]",auxString);

        auxInt=strlen(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");

            continue;




        }

        strupr(auxString);

        strcpy(movie->titulo,auxString);
        break;


    }


}

///*******************************FUNCION getDescription*************************************
void getDescription(char Message[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit)
{
    char auxString[500];
    int auxInt;



    while(1)
    {
        printf("%s ",Message);
        fflush(stdin);
        scanf("%[^\n]",auxString);

        auxInt=strlen(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");

            continue;




        }



        strcpy(movie->descripcion,auxString);
        break;


    }


}

///****************************************FUNCION getInt******************************************
void getInt(char message[],char errorMensaje[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit)
{

    char auxString[256];
    int auxInt;


    while(1)
    {

        if(!funcionValidarNumeros(message,auxString))
        {


            printf("%s",errorMensaje);
            printf("\n");
            system("pause");
            system("cls");
            continue;


        }


        auxInt=atoi(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");


            continue;
        }

        movie->duracion=auxInt;
        break;

    }


}


int funcionValidarNumeros(char mensaje[],char validar[])
{

    int i=0;

    printf("\n%s",mensaje);
    fflush(stdin);
    scanf("%s",validar);

    while(validar[i]!='\0')
    {

        if(validar[i]<'0'||validar[i]>'9')

            return 0;



        i++;

    }
    return 1;
}

///************************************FUNCION getPuntaje*******************************************
void getPuntaje(char message[],char errorMensaje[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit)
{

    char auxString[256];
    int auxInt;


    while(1)
    {




        if(!funcionValidarNumeros(message,auxString))
        {


            printf("%s",errorMensaje);
            printf("\n");
            system("pause");
            system("cls");
            continue;


        }

        auxInt=atoi(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");


            continue;

        }


        movie->puntaje=auxInt;
        break;


    }


}

///************************************FUNCION getUrl*************************************************
void getUrl(char Message[],char eMessage[],EMovie *movie, int lowLimit, int hiLimit)
{
    char auxString[500];
    int auxInt;



    while(1)
    {
        printf("%s ",Message);
        fflush(stdin);
        scanf("%[^\n]",auxString);

        auxInt=strlen(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");

            continue;




        }



        strcpy(movie->linkImagen,auxString);
        break;


    }


}


///*************************FUNCION getMenu**************************************
int getMenu(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit)
{

    char auxString[256];
    int auxInt;


    while(1)
    {

        if(!funcionValidarNumeros(message,auxString))
        {


            printf("%s",errorMensaje);
            printf("\n");
            system("pause");
            system("cls");
            continue;

        }

        auxInt=atoi(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");


            continue;



        }

        return auxInt;


    }


}

///*************************************FUNCION (2) borrarPelicula**************************************
int borrarPelicula(EMovie movie,EMovie auxMovie)
{


    FILE  *f,*bin;
    int found=0;
    char auxPeli[20];



    bin=fopen("bin.dat","rb");

    if ((f=fopen("auxbin.dat","wb"))==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    fflush(stdin);
    getAuxLength("INGRESE EL TITULO a buscar: ","ERROR: PUEDE INGRESAR ENTRE 0 Y 20 CARACTERES!!!!",auxPeli,0,21);

    while ((fread(&movie, sizeof(EMovie), 1, bin)) != NULL)
    {
        if (strcmp (auxPeli, movie.titulo) == 0)
        {
            printf("EL TITULO FUE ENCONTRADO Y SERA ELIMINADO.\n\n");
            found=1;
        }
        else
        {
            fwrite(&movie, sizeof(movie), 1, f);
        }
    }

    if (! found)
    {
        printf("EL TITULO NO FUE ENCONTRADO: %s\n\n", auxMovie.titulo);
        return 0;
    }

    fclose(bin);
	fclose(f);

	remove("bin.dat");


	rename("auxbin.dat", "bin.dat");

    return 1;
}


///************************************************FUNCION getAuxLength**********************************
void getAuxLength(char Message[],char eMessage[],char auxPeli[], int lowLimit, int hiLimit)
{
    char auxString[500];
    int auxInt;



    while(1)
    {
        printf("%s ",Message);
        fflush(stdin);
        scanf("%[^\n]",auxString);

        auxInt=strlen(auxString);

        if(auxInt < lowLimit || auxInt > hiLimit)
        {

            printf("%s",eMessage);
            printf("\n");
            system("pause");
            system("cls");

            continue;




        }


        strupr(auxString);
        strcpy(auxPeli,auxString);
        break;


    }


}
///*********************************************FUNCION generarPagina********************************************
void generarPagina(EMovie movie, char nombre[])
{

    FILE  *f,*bin;

    bin=fopen("bin.dat","r");

    int cant;

    if ((f=fopen(nombre,"w"))==NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }


    fprintf(f,"<!DOCTYPE html>\n<!-- Template by Quackit.com -->\n<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n<meta name='viewport' content='width=device-width, initial-scale=1'>\n<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n<title>Lista peliculas</title>\n<!-- Bootstrap Core CSS -->\n<link href='css/bootstrap.min.css' rel='stylesheet'>\n<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n<link href='css/custom.css' rel='stylesheet'>\n<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n<!--[if lt IE 9]>\n<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n<![endif]-->\n</head>\n<body>\n<div class='container'>\n<div class='row'>\n");



    while(!feof(bin))
    {
        cant = fread(&movie, sizeof(EMovie), 1, bin);
        if(cant!=1)
        {
            if(feof(bin))
                break;
            else
            {
                printf("No leyo el ultimo registro");
                break;
            }
        }
        fprintf(f," <article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='%s' alt=''>\n</a>\n<h3>\n<a href='#'>%s</a>\n</h3>\n<ul>\n<li>Genero:%s</li>\n<li>Puntaje:%d</li>\n<li>Duracion:%d</li>\n</ul>\n<p>%s</p>\n</article>", movie.linkImagen,movie.titulo,movie.genero,movie.puntaje,movie.duracion,movie.descripcion);
    }
    fprintf(f,"</div>\n<!-- /.row -->\n</div>\n<!-- /.container -->\n<!-- jQuery -->\n<script src='js/jquery-1.11.3.min.js'></script>\n<!-- Bootstrap Core JavaScript -->\n<script src='js/bootstrap.min.js'></script>\n<!-- IE10 viewport bug workaround -->\n<script src='js/ie10-viewport-bug-workaround.js'></script>\n<!-- Placeholder Images -->\n<script src='js/holder.min.js'></script>\n</body>\n</html>\n");

    _fcloseall( );
    getch();
}

