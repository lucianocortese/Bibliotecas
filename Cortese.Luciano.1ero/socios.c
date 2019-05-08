#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "socios.h"

void hardcodeo (eAutores autores[], int tamAut, eLibros libros[], int tamLib){

    eAutores hcAutores[]=
    {
        {0, "Cortazar", "Julio"},
        {1, "Helman", "Juan"},
        {2, "Saer", "Juan Jose"},
        {3, "Alan", "Nielsen"},
        {4, "Lucia", "Cortese"},
        {5, "Brenda", "Yacoban"},
        {6, "Diego", "Lem"},
        {7, "Federico", "Dominguez"},
        {8, "Richard", "Eizykovic"},
        {9, "Silvia", "Pailhe"},

    };

    for (int i=0;i<tamAut;i++)
    {
        autores[i]=hcAutores[i];
    }

    eLibros hcLibros[]=
    {
        {0, "el lobo estepario", 9},
        {1, "el tunel", 5},
        {2, "mi planta de naranja lima", 7},
        {3, "menos que cero", 6},
        {4, "el llamado de kthulu", 5},
        {5, "aenima", 4},
        {6, "ecce homo", 3},
        {7, "matematica2", 5},
        {8, "selling england", 1},
        {9, "farenheit 451", 0},
    };

    for (int i=0;i<tamLib;i++)
    {
        libros[i]=hcLibros[i];
    }
}
void inicializarSocios (eSocios socios[], int tamSoc){
    for(int i=0; i<tamSoc; i++){
        socios[i].isEmpty=1;
    }
}
int buscarVacio (eSocios socios[], int tamSoc){
    int vacio=-1;
    for (int i=0;i<tamSoc;i++){
        if(socios[i].isEmpty == 1){
            vacio=i;
            break;
        }
    }
    return vacio;
}
int altaSocio (eSocios socios [], int tamSoc, int contId){

    int vacio;

    vacio=buscarVacio(socios, tamSoc);

    if(vacio==-1){
        printf("No hay lugar libre\n");
    }
    else{


        socios[vacio].idSocio=contId;

        getString(socios[vacio].nombreSocio, "Ingrese el nombre (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 31);

        getString(socios[vacio].apellidoSocio, "Ingrese el apellido (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 31);

        getChar(&socios[vacio].sexo, "ingrese el sexo F/M", "El sexo debe ser F o M", 'F','M');

        getVectorInt(socios[vacio].telefono, "Ingrese el telefono", "El sueldo no puede ser negativo",0, 16);

        getString(socios[vacio].email, "Ingese el email: (entre 8 y 31 caracteres)", "Error, intente nuevamente", 8, 31);

        getInt(&socios[vacio].fechaAsociado.anio, "Ingrese el año en que se unió a la empresa", "no es un numero posible", 1920, 2003);

        getInt(&socios[vacio].fechaAsociado.mes, "Ingrese el mes en que se unió a la empresa", "no es un numero posible", 1, 12);

        getInt(&socios[vacio].fechaAsociado.dia, "Ingrese el dia en que se unió a la empresa", "no es un numero posible", 1, 31);

        getInt(&socios[vacio].isEmpty, "Elija una opción 0=alta, 1=baja", "No es una opción", 0,1);

    }
    contId ++;
    return contId;
}
void ordenarPorApellido (eSocios socios[], int tamSoc){
    //ORDENA POR APELLIDO Y DESPUES NOMBRE...
    eSocios aux;
    for(int i=0; i<tamSoc-1; i++){
       for(int j=i+1; j<tamSoc;j++){

            if(strcmp(socios[i].apellidoSocio, socios[j].apellidoSocio)>0){
                aux=socios[i];
                socios [i]=socios[j];
                socios[j]=aux;
            }
            else if(strcmp(socios[i].apellidoSocio, socios[j].apellidoSocio)==0){
                if(strcmp(socios[i].nombreSocio, socios[j].nombreSocio)>0){
                    aux=socios[i];
                    socios [i]=socios[j];
                    socios[j]=aux;
                }

            }
        }
    }
}
void mostrarSocio (eSocios socios[], int ind){

    printf(" %d    %s,%s    %c   %d   %s    %d/%d/%d \n\n", socios[ind].idSocio, socios[ind].nombreSocio, socios[ind].apellidoSocio, socios[ind].sexo, socios[ind].telefono,socios[ind].email, socios[ind].fechaAsociado.dia, socios[ind].fechaAsociado.mes, socios[ind].fechaAsociado.anio);
}
void mostrarSocios(eSocios socios[], int tamSoc){
    int contador=0;
    for(int i=0; i<tamSoc; i++){
        if(socios[i].isEmpty==0)
        {
            contador++;
            break;
        }
    }
    if(contador!=0){

        printf("Legajo  -  Nombre   -   Apellido   -   Sexo   -   Sueldo   -   Fecha   -    Sector\n");
        for(int i=0; i<tamSoc; i++){
            if(socios[i].isEmpty==0)
            {
                mostrarSocio(socios, i);
            }
        }
    }

    else{
        printf("No hay empleado para mostrar\n");
    }

}
int buscarSocios (eSocios socios[], int tamSoc, int id){

    int encontrado=-1;
     for(int i=0; i<tamSoc; i++){
        if(socios[i].idSocio==id){
           encontrado=i;
           break;
        }
    }

    return encontrado;
}
void modificarSocios (eSocios socios[], int tamSoc){

    int id;
    int existe;
    int mod;

    printf("Ingrese el id del socio que desea modificar: \n");
    scanf("%d", &id);
    existe=buscarSocios(socios,tamSoc,id);

    if(existe==-1){
        printf("el empleado no existe\n");
    }
    if(existe!=-1){
    for(int i=0; i<tamSoc; i++){
        if(socios[i].idSocio==id){
           existe=i;
           break;
        }
    }
        printf("El empleado existe\n");
        mostrarSocio(socios, existe);
        printf("Elija que desea modificar\n");
        printf("1-Apellido\n");
        printf("2-Nombre\n");
        printf("3-Sexo\n");
        printf("4-Telefono\n");
        printf("5-Mail\n");
        printf("0-No hacer modificación\n");
        scanf("%d", &mod);

        switch (mod){
            case 1:
                getString(socios[id].apellidoSocio, "Ingrese el nuevo apellido (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 31);
                printf("El apellido se cambió con exito");
                break;
            case 2:
                getString(socios[id].nombreSocio, "Ingrese el nuevo nombre (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 31);
                printf("El nombre se cambió con exito \n");
                break;
            case 3:
                getChar(&socios[id].sexo, "ingrese el nuevo sexo F/M", "El sexo debe ser F o M", 'F','M');
                printf("el sexo ya fue modificado exitosamente\n");
                break;
            case 4:
                getVectorInt(socios[id].telefono, "Ingrese el nuevo telefono", "El telefono no puede ser negativo",0, 16);
                printf("El sueldo se cambió con exito");
                break;
            case 5:
                getString(socios[id].email, "Ingese el email nuevamente: (entre 8 y 31 caracteres)", "Error, intente nuevamente", 8, 31);
                break;
            case 0:
                printf("no se haran modificaciones\n");
                break;
            default:
                printf("La opcion no es correcta, intente nueva opcion\n");
                break;
        }
    }
}
void bajaSocio (eSocios socios[], int tamSoc){

    int id;
    int encontrado=-1;
    char resp;
    printf("Ingrese el ID del socio que desea dar de baja:\n\n");
    scanf("%d", &id);

    encontrado=buscarSocios(socios,tamSoc,id);

    if(encontrado==-1){
        printf("No se encontró un socio con ese ID\n");
    }
    else if (socios[encontrado].isEmpty==1){
        printf("El socio ya fue dado de baja\n");
    }
    else
    {
        printf("Se encontro el socio\n");
        mostrarSocio(socios, encontrado);
        printf("Está seguro que desea darlo de baja? S/N");
        fflush(stdin);
        scanf("%c", &resp);
        resp=toupper(resp);

            if(resp=='S'){
                socios[encontrado].isEmpty=1;
                printf("La baja se hizo con exito\n\n");
            }
            else{
                printf("No se hizo la baja\n");
            }

    }



}
void ordenarPorTitulo (eLibros libros[], int tamLib){
    //ORDENA POR APELLIDO Y DESPUES NOMBRE...
    eLibros aux;
    for(int i=0; i<tamLib-1; i++){
       for(int j=i+1; j<tamLib;j++){

            if(strcmp(libros[i].titulo, libros[j].titulo)>0){
                aux=libros[i];
                libros [i]=libros[j];
                libros[j]=aux;
            }

        }
    }
}
void mostrarLibro (eLibros libros[], int ind){

    printf(" %d    %s    %d\n", libros[ind].idLibro, libros[ind].titulo, libros[ind].idAutor);
}
void mostrarLibros(eLibros libros[], int tamLib){

    for(int i=0; i<tamLib; i++){
        mostrarLibro(libros, i);
    }
}
void ordenarAutoresPorApellido (eAutores autores[], int tamAut){
    //ORDENA POR APELLIDO Y DESPUES NOMBRE...
    eAutores aux;
    for(int i=0; i<tamAut-1; i++){
       for(int j=i+1; j<tamAut;j++){

            if(strcmp(autores[i].apellidoAutor, autores[j].apellidoAutor)>0){
                aux=autores[i];
                autores [i]=autores[j];
                autores[j]=aux;
            }
            else if(strcmp(autores[i].apellidoAutor, autores[j].apellidoAutor)==0){
                if(strcmp(autores[i].nombreAutor, autores[j].nombreAutor)>0){
                    aux=autores[i];
                    autores [i]=autores[j];
                    autores[j]=aux;
                }

            }
        }
    }
}
void mostrarAutor (eAutores autores[], int ind){

    printf(" %d    %s,%s\n", autores[ind].idAutor, autores[ind].apellidoAutor, autores[ind].nombreAutor);
}
void mostrarAutores(eAutores autores[], int tamAut){

    for(int i=0; i<tamAut; i++){
        mostrarAutor(autores, i);
    }
}
void inicializarPrestamos (ePrestamos prestamos[], int tamPre){
    for(int i=0; i<tamPre; i++){
        prestamos[i].isEmpty=1;
    }
}
int buscarVacioPres (ePrestamos prestamo[], int tamPre){
    int vacio=-1;
    for (int i=0;i<tamPre;i++){
        if(prestamo[i].isEmpty == 1){
            vacio=i;
            break;
        }
    }
    return vacio;
}
int altaPrestamos (ePrestamos prestamos [], int tamPre, int contIdPre){

    int vacio;

    vacio=buscarVacioPres(prestamos, tamPre);

    if(vacio==-1){
        printf("No hay lugar libre\n");
    }
    else{


        prestamos[vacio].idPrestamo=contIdPre;

        getInt(&prestamos[vacio].idLibro, "Ingrese el codigo del libro", "Hay un error, ingrese el codigo nuevamtente",0,9);

        getInt(&prestamos[vacio].idSocio, "Ingrese el codigo del socio", "Hay un error, ingrese el codigo nuevamtente",0,9);

        getInt(&prestamos[vacio].fechaPrestamo.anio, "Ingrese el año en que se saco el prestamo", "no es un numero posible", 1990, 2019);

        getInt(&prestamos[vacio].fechaPrestamo.mes, "Ingrese el mes en que se saco el prestamo", "no es un numero posible", 1, 12);

        getInt(&prestamos[vacio].fechaPrestamo.dia, "Ingrese el dia en que se saco el prestamo", "no es un numero posible", 1, 31);

        getInt(&prestamos[vacio].isEmpty, "Elija una opción 0=alta, 1=baja", "No es una opción", 0,1);

    }
    contIdPre ++;
    return contIdPre;
}
void informarAutorConMasLibros (eAutores autores[], int tamAut, eLibros libros[], int tamLib){
    int cont;
    int max;
    char autor[31];
    int bandera=0;

    for (int i=0;i<tamLib;i++){
        cont=0;
        for (int j=0;j<tamAut;j++){
            if (autores[i].idAutor==libros[j].idAutor){
                cont++;

                    if (cont>max || bandera==0){
                    max=cont;
                    strcpy(autor, autores[i].apellidoAutor);
                    bandera++;
                }
            }
        }
    }
    if (max>=1){
        printf("\nAutor con mas libros:\n -%s con %d libros\n", autor, max);
    }
    else{
        printf("\nNo hay nada que listar!!\n\n");
    }

}
void informarLibroMasPrestado (eLibros libros[],int tamLib, ePrestamos prestamos[], int tamPre){
    int cont;
    int max=0;
    int id=0;
    int bandera=0;
    char titulo[51];

     for (int i=0;i<tamLib;i++){
         cont=0;

         for (int j=0;j<tamPre;j++){
             if (prestamos[j].idLibro==libros[i].idLibro && prestamos[j].isEmpty==0){
                 cont++;
                 if (cont>max || bandera==0){
                     id=prestamos[j].idLibro;
                     strcpy(titulo, libros[i].titulo);
                     max=cont;
                     bandera++;
                 }
            }
        }
    }

    if(bandera>0)
    {
        printf("\nEl libro mas prestado:\n %s, prestado en %d ocasiones  %s\n\n", titulo, max);
    }
    else
    {
        printf("\nNo hay nada que mostrar!!\n\n");
    }




}
