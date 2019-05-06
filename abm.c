#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "/home/lucho/Escritorio/UTN/Parcial bibliotecas/input.h"
#include "abm.h"

void mostrarEmpleado (eEmpleados lista[], int ind, eSector sectores[]){

    printf(" %d        %s       %s          %c      %2.f       %d/%d/%d          %s\n\n\n", lista[ind].legajo, lista[ind].vNombre, lista[ind].vApellido, lista[ind].sexo, lista[ind].sueldo, lista[ind].alta.dia, lista[ind].alta.mes, lista[ind].alta.anio, sectores[(lista[ind].idSector)-1].vDescripcion);
}
void mostrarEmpleados (eEmpleados lista[], int tam, eSector sectores[]){
    int contador=0;
    for(int i=0; i<tam; i++){
        if(lista[i].isEmpty==0)
        {
            contador++;
            break;
        }
    }
    if(contador!=0){

        printf("Legajo  -  Nombre   -   Apellido   -   Sexo   -   Sueldo   -   Fecha   -    Sector\n");
        for(int i=0; i<tam; i++){
            if(lista[i].isEmpty==0)
            {
                mostrarEmpleado(lista, i, sectores);
            }
        }
    }

    else{
        printf("No hay empleado para mostrar\n");
    }

}
void inicializarEmpleados (eEmpleados lista[], int tam){
    for(int i=0; i<tam; i++){
        lista[i].isEmpty=1;
    }
}
int buscarvacio (eEmpleados lista[], int tam){
    int vacio=-1;
    for (int i=0;i<tam;i++){
        if(lista[i].isEmpty == 1){
            vacio=i;
            break;
        }
    }
    return vacio;
}
int altaEmpleado (eEmpleados lista [], int tam, int contLegajo){

    int vacio;

    vacio=buscarvacio(lista, tam);

    if(vacio==-1){
        printf("No hay lugar libre\n");
    }
    else{


        lista[vacio].legajo=contLegajo;

        getString(lista[vacio].vNombre, "Ingrese el nombre (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 51);

        getString(lista[vacio].vApellido, "Ingrese el apellido (maximo 51 caracteres):", "Se exedió en la cantidad de caracteres, pruebe nuevamente", 0, 51);

        getChar(&lista[vacio].sexo, "ingrese el sexo F/M", "El sexo debe ser F o M", 'F','M');

        getFloat(&lista[vacio].sueldo, "Ingrese el sueldo", "El sueldo no puede ser negativo",0, 200000);

        getInt(&lista[vacio].alta.anio, "Ingrese el año en que se unió a la empresa", "no es un numero posible", 1920, 2003);

        getInt(&lista[vacio].alta.mes, "Ingrese el mes en que se unió a la empresa", "no es un numero posible", 1, 12);

        getInt(&lista[vacio].alta.dia, "Ingrese el dia en que se unió a la empresa", "no es un numero posible", 1, 31);

        getInt(&lista[vacio].idSector, "Elija el sector donde pertenece \n1-RRHH\n2-Venta\n3-Compra", "no es un numero posible", 1, 3);

        getInt(&lista[vacio].isEmpty, "Elija una opción 0=alta, 1=baja", "No es una opción", 0,1);

    }
    contLegajo ++;
    return contLegajo;
}
void bajaEmpleado (eEmpleados lista[], int tam, eSector sectores[]){

    int leg;
    int encontrado=-1;
    char resp;
    printf("Ingrese el legajo del empleado que desea dar de baja:\n\n");
    scanf("%d", &leg);

    encontrado=buscarEmpleado(lista,tam,leg);

    if(encontrado==-1){
        printf("No se encontró un empleado con ese legajo\n");
    }
    else if (lista[encontrado].isEmpty==1){
        printf("El empleado ya fue dado de baja\n");
    }
    else
    {
        printf("Se encontro el empleado\n");
        mostrarEmpleado(lista, encontrado, sectores);
        printf("Está seguro que desea darlo de baja? s/n");
        __fpurge(stdin);
        scanf("%c", &resp);
        tolower(resp);

            if(resp=='s'){
                lista[encontrado].isEmpty=1;
                printf("La baja se hizo con exito\n\n");
            }
            else{
                printf("No se hizo la baja\n");
            }

    }



}
void ordenarPorApellido (eEmpleados lista[], int tam){
    //ORDENA POR APELLIDO Y DESPUES NOMBRE...
    eEmpleados aux;
    for(int i=0; i<tam-1; i++){
       for(int j=i+1; j<tam;j++){

            if(strcmp(lista[i].vApellido, lista[j].vApellido)>0){
                aux=lista[i];
                lista [i]=lista[j];
                lista[j]=aux;
            }
            else if(strcmp(lista[i].vApellido, lista[j].vApellido)==0){
                if(strcmp(lista[i].vNombre, lista[j].vNombre)>0){
                    aux=lista[i];
                    lista [i]=lista[j];
                    lista[j]=aux;
                }

            }
        }
    }
}
void modificarEmpleado (eEmpleados lista[], int tam, eSector sectores[]){

    int leg;
    int existe;
    int mod;

    printf("Ingrese el legajo del empleado que desea modificar: \n");
    scanf("%d", &leg);
    existe=buscarEmpleado(lista,tam,leg);

    if(existe==-1){
        printf("el empleado no existe\n");
    }
    if(existe!=-1){
    for(int i=0; i<tam; i++){
        if(lista[i].legajo==leg){
           existe=i;
           break;
        }
    }
        printf("El empleado existe\n");
        mostrarEmpleado(lista, existe,sectores);
        printf("Elija que desea modificar\n");
        printf("1-Apellido\n");
        printf("2-Nombre\n");
        printf("3-Sexo\n");
        printf("4-Salario\n");
        printf("5-Fecha de ingreso\n");
        printf("6-Sector\n");
        printf("0-No hacer modificación\n");
        scanf("%d", &mod);

        switch (mod){
            case 1:
                getString(lista[existe].vApellido, "Ingrese el nuevo apellido (maximo 51 caracteres):\n", "Se exedió en la cantidad de caracteres, pruebe nuevamente\n", 0, 51);
                printf("El apellido se cambió con exito");
                break;
            case 2:

                getString(lista[existe].vNombre, "Ingrese el nuevo nombre (maximo 51 caracteres):\n", "Se exedió en la cantidad de caracteres, pruebe nuevamente\n", 0, 51);
                printf("El nombre se cambió con exito \n");
                break;
            case 3:
                if (lista[existe].sexo=='F'){
                    lista[existe].sexo='M';
                }
                else{
                    lista[existe].sexo=='F';
                }
                printf("el sexo ya fue modificado exitosamente\n");
                break;
            case 4:
                getFloat(&lista[existe].sueldo, "Ingrese el nuevo sueldo\n", "El sueldo no puede ser negativo\n",0, 200000);
                printf("El sueldo se cambió con exito");
                break;
            case 5:
                getInt(&lista[existe].alta.mes, "Ingrese el mes en que se unió a la empresa\n", "no es un numero posible\n", 1, 12);
                getInt(&lista[existe].alta.dia, "Ingrese el dia en que se unió a la empresa\n", "no es un numero posible\n", 1, 31);
                getInt(&lista[existe].idSector, "Elija el sector donde pertenece \n1-RRHH\n2-Venta\n3-Compra\n", "no es un numero posible\n", 1900, 2003);
                printf("la fecha se cambió con exito");
                break;
            case 6:
                getInt(&lista[existe].idSector, "Elija el sector donde pertenece \n1-RRHH\n2-Venta\n3-Compra\n", "no es un numero posible\n", 1, 3);
                printf("El nuevo sector se modifico con exito\n");
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
int buscarEmpleado (eEmpleados lista[], int tam, int leg){

    int encontrado=-1;
     for(int i=0; i<tam; i++){
        if(lista[i].legajo==leg){
           encontrado=i;
           break;
        }
    }

    return encontrado;
}
void hardcodeo (eEmpleados lista[], int tamEmpl, eSector sectores[], int tamSect, eMenu carta[], int tamMenu){
    inicializarEmpleados(lista, tamEmpl);

    eEmpleados hardcodeoEmp[]=
    {
        {0, "Luciano", "Cortese", 'M', 32000, {16,12,2002}, 1,0},
        {1, "Juan", "Quintas", 'F', 41000, {6,07,2001}, 2, 0},
        {2, "Camila", "Oberman", 'F', 23000, {5,06,2003}, 4, 0},
        {3, "Alan", "Nielsen", 'M', 19000, {25,03,2009}, 3, 0},
        {4, "Lucia", "Cortese", 'F', 27500, {14,9,2010}, 5, 0},
        {5, "Brenda", "Yacoban", 'M', 22000, {16,11,2003},2,0},
        {6, "Diego", "Lem", 'M', 17000, {18,02,1996}, 4, 0},
        {7, "Federico", "Dominguez", 'M', 28000, {14,03,2009}, 3, 0},
        {8, "Richard", "Eizykovic", 'M', 27500, {22,10,2010}, 5, 0},
        {9, "Adriana", "Pailhe", 'F', 26000, {7,8,2003},2,0},

    };

    for (int i=0;i<tamEmpl;i++)
    {
        lista[i]=hardcodeoEmp[i];
    }

    eSector hardcodeoSec[]=
    {
        {1, "RRHH"},
        {2, "Compra"},
        {3, "Logistica"},
        {4, "Venta"},
        {5, "Tecnica"},
    };

    for (int i=0;i<tamSect;i++)
    {
        sectores[i]=hardcodeoSec[i];
    }

    eMenu hardcodeoMenu[]=
    {
        {1, "Guiso", 120.00},
        {2, "Pizza chica", 95.50},
        {3, "Canelones", 100.00},
        {4, "Milanesa con pure", 130.00},
        {5, "Tacos", 70.00},
        {6, "Empanadas", 20.00},
        {7, "Sanguches", 45.00},
        {8, "Burritos", 75.00},
        {9, "Asado", 150.00},
        {10, "Pastel de papa", 85.00},
    };

    for (int i=0;i<tamMenu;i++)
    {
        carta[i]=hardcodeoMenu[i];
    }
}
void inicializarAlmuerzo (eAlmuerzo almuerzos[], int tamAlm){
    for(int i=0;i<tamAlm;i++){
        almuerzos[i].isEmpty=1;
    }
}
int buscarAlmLibre (eAlmuerzo almuerzos[], int tamAlm){
    int almLibre=-1;
    for(int i=0; i<tamAlm; i++){
        if(almuerzos[i].isEmpty==1){
            almLibre=i;
            break;
        }
    }
    return almLibre;
}
void altaAlmuerzo (eEmpleados emp[],eSector sec[], eMenu carta[], int tamMenu, eAlmuerzo almuerzos[], int tamAlm){

    char continuar;
    int leg;
    int almLibre;

    almLibre=buscarAlmLibre(almuerzos,tamAlm);

    if(almLibre<0){
        printf("No hay mas almuerzos disponibles\n");
    }
    else{
        getInt(&leg, "Ingrese legajo del empleado:", "Ese legajo no existe, intente nuevamente.", 1,1000);
        printf("Se ha encontrado este legajo: ");
        mostrarEmpleado(emp, leg, sec);
        getChar(&continuar, "Desea continuar? S/N", "No es una opción valida, marque S o N", 'S', 'N');

        if(continuar=='N'){

            printf("Operación cancelada\n");

        }
        else{

            if(emp[leg].isEmpty==1){
                printf("El legajo no pertenece a un empleado activo");
            }
            else{


                almuerzos[almLibre].legajoEmp=leg;
                for(int i=1; i<=10; i++){
                    printf("%d - %s\n", i, carta[i].vDescripcion);
                }
                getInt(&almuerzos[almLibre].codigoMenu, "Ingrese el codigo del almuerzo", "El almuerzo ingresado no es correcto",1,10 );
                getInt(&almuerzos[almLibre].fechaAlm.anio, "Ingrese el año del almuerzo: (2000/2019)", "El año no es valido", 2000,2019);
                getInt(&almuerzos[almLibre].fechaAlm.mes, "Ingrese el mes del almuerzo: ", "El mes no es valido", 1,12);
                getInt(&almuerzos[almLibre].fechaAlm.dia, "Ingrese el dia del almuerzo: ", "El dia no es valido", 1,31);
                almuerzos[almLibre].isEmpty=0;

            }

        }

    }
}
void mostrarAlmuerzo(eEmpleados emp[], eSector sec[], eMenu carta[], eAlmuerzo almuerzos[], int tamAlm){


    for(int i=0; i<tamAlm;i++){

        if(almuerzos[i].isEmpty==0 && emp[almuerzos[i].legajoEmp].isEmpty==0 ){
        printf("%d, %s %s, %d/%d/%d, %s, $%2.f\n", i, emp[almuerzos[i].legajoEmp].vApellido, emp[almuerzos[i].legajoEmp].vNombre, almuerzos[i].fechaAlm.dia,almuerzos[i].fechaAlm.mes ,almuerzos[i].fechaAlm.anio, carta[almuerzos[i].codigoMenu].vDescripcion, carta[almuerzos[i].codigoMenu].importe );
        }

    }

}
