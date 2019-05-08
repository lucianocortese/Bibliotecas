#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int flag=-1;
    int entero;

    do{
        printf("%s\n",message);
        scanf("%d", &entero);

        if( (entero>=lowLimit) && (entero<=hiLimit) ){
            flag=0;
            printf("El numero fue cargado con exito\n\n");
            *input=entero;
        }
        else{
            printf("%s\n", eMessage);
        }
    }while (flag==-1);

    return flag;
}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int flag=-1;

    do{
        float decim;
        printf("%s\n",message);
        scanf("%f", &decim);
            if(decim>=lowLimit && decim<=hiLimit){

                    flag=0;
                    printf("El numero fue cargado con exito\n\n");
                    *input=decim;
                }
            else{
                    printf("%s\n",eMessage);

                }
    }while (flag==-1);

    return flag;
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int flag=-1;

    do{
        char letra;
        printf("%s\n",message);
        __fpurge(stdin);
        scanf("%c", &letra);
        __fpurge(stdin);
        letra=toupper(letra);
            if (letra==lowLimit || letra==hiLimit)
            {
                flag=0;
                *input=letra;
                printf("El caracter fue cargado con exito \n\n");

            }
            else{
                printf("%s\n",eMessage);
                }
    }while (flag==-1);

    return flag;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int flag=-1;


    do{
        char string[hiLimit];
        int largo;

        printf("%s\n", message);
        setbuf(stdin, NULL);
        gets(string);
        largo=strlen(string);

            if(largo>=lowLimit&&largo<=hiLimit){
                printf("La cadena fue cargado con exito \n\n");
                flag=0;
                strcpy(input, string);
            }
            else{
                printf("%s\n", eMessage);
            }

        }while (flag==-1);


    return flag;
}

int getVectorInt(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int flag=-1;


    do{
        char vec[hiLimit];
        int largo;

        printf("%s\n", message);
        setbuf(stdin, NULL);
        gets(vec);
        largo=strlen(vec);

            if(largo>=lowLimit&&largo<=hiLimit){
                printf("El vector fue cargado con exito \n\n");
                flag=0;
                strcpy(input, vec);
            }
            else{
                printf("%s\n", eMessage);
            }

        }while (flag==-1);


    return flag;
}
