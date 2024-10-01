//Tomas Muñoz Licciardello
//Matias Padula
//Grupo 17
#ifndef LISTA_OP_H_INCLUDED
#define LISTA_OP_H_INCLUDED
#include <string.h>
#include <conio.h>
#define MAX 111
#define INFINITO 99999999
#include "prestador.h"

typedef struct
{   prestador prestadores[MAX];//LSO
    int ultimo;//contiene el ultimo elemento de la estructura
} LSO;

void iniciar_LSO(LSO *lista)
{
    lista->prestadores[0].DNI=INFINITO;
    lista->ultimo=-1;
}

int alta_LSO(LSO *lista, prestador x)
{
    int aux,inf;
    int posicion;
    if(!localizar_LSO(lista,obtener_DNI(x),&posicion))
    {
        aux=lista->ultimo;
        while(posicion<=aux)
        {
            lista->prestadores[aux+1]=lista->prestadores[aux];
            aux--;
        }
        lista->prestadores[posicion]=x;
        lista->ultimo++;
        //inf=lista->ultimo+1;
        lista->prestadores[lista->ultimo+1].DNI=INFINITO;
        return 1;
    }
        else
    {
        return -1;
    }
}

int mostrar_LSO(LSO lista) {
    int i;
    int tecla;
    int pagina_actual = 0;
    int total_paginas = (lista.ultimo / 2) + 1;

    if (lista.ultimo == -1) {
        printf("No hay elementos en la estructura.\n");
        printf("Presione Enter para volver al menu.\n");
        getchar();
        getchar();
        system("cls");
        return 0;
    } else {
        while (1) {
            system("cls");
            printf("Pagina %d de %d\n\n", pagina_actual + 1, total_paginas);

            if (pagina_actual * 2 <= lista.ultimo) {
                printf("Elemento %d de %d\n", pagina_actual * 2 + 1, lista.ultimo + 1);
                mostrar_prestador(lista.prestadores[pagina_actual * 2]);
            }
            if (pagina_actual * 2 + 1 <= lista.ultimo) {
                printf("Elemento %d de %d\n", pagina_actual * 2 + 2, lista.ultimo + 1);
                mostrar_prestador(lista.prestadores[pagina_actual * 2 + 1]);
            }

            if (pagina_actual < total_paginas - 1) {
                printf("\nPresione Enter para continuar, Backspace para regresar, Esc para salir");
            } else {
                printf("\nPresione Backspace para regresar, Esc para salir");
            }

            tecla = _getch();

            if (tecla == 13) {
                if (pagina_actual < total_paginas - 1) {
                    pagina_actual++;
                }
            } else if (tecla == 8) {
                if (pagina_actual > 0) {
                    pagina_actual--;
                }
            } else if (tecla == 27) {
                system("cls");
                break;
            }
        }
    }
    return 0;
}



int evocar_LSO(LSO lista, int x, prestador *aux)
{
    int pos;
    if(localizar_LSO(&lista,x,&pos)){
        strcpy(aux->celular,obtener_celular(lista.prestadores[pos]));
        aux->DNI=obtener_DNI(lista.prestadores[pos]);
        strcpy(aux->domicilio,obtener_domicilio(lista.prestadores[pos]));
        strcpy(aux->email,obtener_email(lista.prestadores[pos]));
        strcpy(aux->nom_y_ape,obtener_nom_y_ape(lista.prestadores[pos]));
        strcpy(aux->servicios,obtener_servicios(lista.prestadores[pos]));
        return 1;
    }
    else
    {
        return 0;
    }
}
int baja_LSO(LSO *lista, int x)
{
    int decision;
    int posicion;
    int aux, aux_INF;
    if(localizar_LSO(lista,x,&posicion))
    {
        mostrar_prestador(lista->prestadores[posicion]);
        printf("Es este el prestador que quiere eliminar?\n");
        printf("1- Si 2- No: ");
        scanf("%d", &decision);
        if(decision==2)
        {
            return 0;
        }
        else
        {
            aux=posicion;
            while(aux<lista->ultimo)
            {
                lista->prestadores[aux]=lista->prestadores[aux+1];
                aux++;
            }
            aux_INF=lista->ultimo;
            lista->prestadores[aux_INF+1].DNI=0;
            lista->prestadores[lista->ultimo].DNI=INFINITO;
            lista->ultimo--;
            printf("Borrado exitoso\n");
            return 1;
        }
    }
    else
    {
        return -1;
    }

}

int modificar_LSO(LSO *lista, int dni) {
    int posicion;
    if(localizar_LSO(lista,dni,&posicion)){
        printf("Los datos asociados a ese prestador son: \n");
        mostrar_prestador(lista->prestadores[posicion]);
        fflush(stdin);
        printf("A continuacion ingrese los siguientes datos: \n");
        printf("Nombre y Apellido: ");
        fgets(lista->prestadores[posicion].nom_y_ape, sizeof(lista->prestadores[posicion].nom_y_ape), stdin);
        printf("Servicio: ");
        fgets(lista->prestadores[posicion].servicios, sizeof(lista->prestadores[posicion].servicios), stdin);
        printf("Domicilio: ");
        fgets(lista->prestadores[posicion].domicilio, sizeof(lista->prestadores[posicion].domicilio), stdin);
        printf("Email: ");
        fgets(lista->prestadores[posicion].email, sizeof(lista->prestadores[posicion].email), stdin);
        printf("Celular: ");
        fgets(lista->prestadores[posicion].celular, sizeof(lista->prestadores[posicion].celular), stdin);
        return 1;
    }
    else{
        return -1;
    }
}

int localizar_LSO(LSO *lista,int x,int *pos)
{
    int c=0;
    while(lista->prestadores[c].DNI<x)//mientras que este dentro de la estructura y el DNI de la lista sea distinto al que buscamos
    {
        c++;
    }
    *pos=c;
    return (x==lista->prestadores[c].DNI);
}
#endif // LISTA_OP_H_INCLUDED
