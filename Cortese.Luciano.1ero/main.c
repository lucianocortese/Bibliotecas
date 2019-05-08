#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "socios.h"
#define TAM_SOC 10
#define TAM_LIB 10
#define TAM_AUT 10
#define TAM_PRE 10



int main()
{

    eAutores autores[TAM_AUT];
    eLibros libros[TAM_LIB];
    eSocios socios [TAM_SOC];
    ePrestamos prestamos[TAM_PRE];

    inicializarSocios(socios, TAM_SOC);
    inicializarPrestamos (prestamos, TAM_PRE);

    int menu;
    int contId=0;
    int contIdPre=0;
    char continuar='N';
    hardcodeo (autores, 10, libros, 10);



    do{

    printf("--------- ABM biblioteca-------\n");
    printf("1- Alta socio \n");
    printf("2- Modificar socio \n");
    printf("3- Baja socio \n");
    printf("4- Listar socios \n");
    printf("5- Listar libros \n");
    printf("6- Listar autores \n");
    printf("7- Alta prestamos\n");
    printf("0- salir\n");

        getInt(&menu, "Ingrese una opcion: ", "No es una opcion valida, intente nuevamente",0,8);

        switch (menu){
            case 1:
                contId=altaSocio(socios, TAM_SOC, contId);
                break;
            case 2:
                modificarSocios(socios,TAM_SOC);
                break;
            case 3:
                bajaSocio(socios,TAM_SOC);
                break;
            case 4:
                ordenarPorApellido(socios,TAM_SOC);
                mostrarSocios (socios,TAM_SOC);
                break;
            case 5:
                ordenarPorTitulo (libros, TAM_LIB);
                mostrarLibros(libros, TAM_LIB);
                break;
            case 6:
                ordenarAutoresPorApellido(autores,TAM_AUT);
                mostrarAutores(autores, TAM_AUT);
                break;
            case 7:
                contIdPre=altaPrestamos(prestamos, TAM_PRE, contIdPre);
                break;
            case 8:
                informarLibroMasPrestado (libros, TAM_LIB,  prestamos, TAM_PRE);
                break;
            case 0:
                getChar(&continuar, "Desea salir? (S/N)", "No es una opcion valida, probemos nuevamente", 'S', 'N');
                break;
                }
    }while (continuar=='N');

    return 0;
}

