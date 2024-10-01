//Tomas Muñoz Licciardello
//Matias Padula
//Grupo 17
#include <stdio.h>
#include <stdlib.h>
#include "lista_op.h"
#define MAX 111
int memorizar(LSO *lista){
    FILE *file;
    prestador aux;
    int i=0;
    file = fopen("Prestadores.txt","r");
    if(file == NULL){
        printf("No hay ningun archivo.\n");
        return 0;
    }
    else
    {
        while(!feof(file) && lista->ultimo!=MAX-2){
            fscanf(file,"%d\n",&aux.DNI);
            fgets(aux.nom_y_ape,sizeof(aux.nom_y_ape),file);
            fgets(aux.servicios,sizeof(aux.servicios),file);
            fgets(aux.domicilio,sizeof(aux.domicilio),file);
            fgets(aux.email,sizeof(aux.email),file);
            fgets(aux.celular,sizeof(aux.celular),file);
            if(alta_LSO(lista,aux)==-1){
                i++;
            }
        }
        printf("Hay %d prestadores repetidos en el archivo.\n", i);
    }
    fclose(file);
}

int main()
{
    LSO list;
    int opcion,DNI_evocar;
    iniciar_LSO(&list);
    prestador alta;
    prestador modificar;
    prestador evocar;
    int seleccion, dni, posicion, resultado;
    char nomyape[80], servicio[120], domicilio[80],email[50],celular[30];
    while(opcion!=7)
    {
        printf("-----------------SISTEMA DE PRESTADORES---------------------\n");
        printf("[1]Memorizar los datos\n");
        printf("[2]Cargar un dato\n");
        printf("[3]Eliminar un dato\n");
        printf("[4]Modificar los datos de una persona\n");
        printf("[5]Consultar los datos de una persona\n");
        printf("[6]Mostrar estructura\n");
        printf("[7]Salir\n");
        printf("\nIngrese una opcion: ");
        while(scanf("%d", &opcion) != 1 || (opcion < 1 || opcion > 7)) {
            fflush(stdin);
            printf("\nError: Debe ingresar un numero valido.");
            printf("\nIntentelo nuevamente: ");
    }

        switch (opcion){
        case 1:
            if(list.ultimo==MAX-2){
                printf("La lista esta llena no se pueden cargar mas datos.\n");
                printf("\nPresione enter para volver al menu.\n");
                getchar();
                getchar();
                system("cls");
            }
            else
            {
                memorizar(&list);
                printf("\nPresione enter para volver al menu.\n");
                getchar();
                getchar();
                system("cls");
            }
        break;
        case 2:
            if(list.ultimo==MAX-2){
                printf("La lista esta llena, si desea cargar un nuevo prestador, debe eliminar otro de la lista.\n");
            }
            else
            {
                printf("Ingrese los datos del prestador: \n");
                do {
                    printf("DNI: ");
                    resultado = scanf("%d", &alta.DNI);
                    while (getchar() != '\n');

                    if (resultado != 1 || alta.DNI < 0 || alta.DNI >= 99999999) {
                        printf("Ingrese un DNI valido.\n");
                        resultado = 0;
                    }
                } while (resultado == 0);

                fflush(stdin);
                printf("Nombre y Apellido: ");
                fgets(nomyape, sizeof(nomyape), stdin);
                strcpy(alta.nom_y_ape, nomyape);
                printf("Servicio: ");
                fgets(servicio, sizeof(servicio), stdin);
                strcpy(alta.servicios, servicio);
                printf("Domicilio: ");
                fgets(domicilio, sizeof(domicilio), stdin);
                strcpy(alta.domicilio, domicilio);
                printf("Email: ");
                fgets(email, sizeof(email), stdin);
                strcpy(alta.email, email);
                printf("Celular: ");
                fgets(celular, sizeof(celular), stdin);
                strcpy(alta.celular, celular);
                if(alta_LSO(&list, alta)==-1){
                    printf("El prestador con ese DNI ya esta cargado");
                };
            }
            printf("\nPresione enter para volver al menu.\n");
            getchar();
            getchar();
            system("cls");
        break;

        case 3:
            if(list.ultimo==-1){
                printf("La lista esta vacia no puede dar de baja a ningun prestador aun.\n\n");
                printf("Enter para continuar.");
                getchar();
                getchar();
                system("cls");
            }
            else
            {
                printf("Ingrese el DNI del prestador que quiere dar de baja: ");
                scanf("%d",&seleccion);
                if(seleccion >= 99999999 || seleccion < 0){
                    printf("No puede ingresar un numero mayor o igual a 99999999\n");
                    printf("Presione enter para volver al menu.\n");
                    getchar();
                    system("cls");
                }
                else
                {
                     if(baja_LSO(&list,seleccion)==-1){
                        printf("El DNI ingresado no pertenece a ningun prestador de la lista.\n");
                        printf("Presione enter para volver al menu.\n");
                        getchar();
                        getchar();
                        system("cls");
                    }
                    else
                    {
                        printf("Presione enter para volver al menu.\n");
                        getchar();
                        getchar();
                        system("cls");
                    }
                   /* else
                    {
                        printf("\nBorrado exitoso.\n\n");
                        printf("Presione enter para volver al menu.\n");
                    }*/
                }
            }
        break;
        case 4:
        if(list.ultimo==-1){
            printf("La lista esta vacia, no se  puede modificar a ningun prestador aun.");
            getchar();
        }
        else
        {
            printf("Ingrese el DNI del prestador a modificar: \n");
            do {
                    printf("DNI: ");
                    resultado =  scanf("%d", &dni);;
                    while (getchar() != '\n');

                    if (resultado != 1 || dni < 0 || dni >= 99999999) {
                        printf("Ingrese un DNI valido, no se pueden ingresar DNI mas grandes o iguales a 99999999.\n");
                        resultado = 0;
                    }
                } while (resultado == 0);
            if (modificar_LSO(&list, dni)==-1) {
                printf("La persona con ese DNI no está en la estructura.\n");
            } else {
                printf("La carga se ha realizado correctamente. ");
            }
        }
            printf("Presione enter para volver al menu.\n");
            getchar();
            getchar();
            system("cls");
        break;
        case 5:
            incializar_prestador(&evocar);
            if(list.ultimo==-1){
                printf("La lista esta vacia, no se puede consultar sobre ningun prestador por ahora.\n");
                printf("Presione enter para volver al menu.\n");
                getchar();
                getchar();
                system("cls");
            }
            else
            {
                printf("Ingrese el DNI del prestador al cual esta buscando.\n");
                do {
                    printf("DNI: ");
                    resultado =  scanf("%d", &DNI_evocar);;
                    while (getchar() != '\n');

                    if (resultado != 1 || DNI_evocar < 0 || DNI_evocar >= 99999999) {
                        printf("Ingrese un DNI valido, no se pueden ingresar DNI mas grandes o iguales a 99999999.\n");
                        resultado = 0;
                    }
                } while (resultado == 0);
                if(!evocar_LSO(list,DNI_evocar,&evocar))
                {
                    printf("La persona con ese DNI no esta en la estructura.\n");
                    printf("Presione enter para volver al menu.\n");
                    getchar();
                    system("cls");
                }
                else
                {
                    mostrar_prestador(evocar);
                    getchar();
                    printf("Presione enter para volver al menu.\n");
                    getchar();
                    system("cls");

                }
            }
        break;
        case 6:
            if(list.ultimo==-1){
                printf("La lista esta vacia no se puede mostrar ningun prestador aun.\n");
                printf("Presione enter para volver al menu.\n");
                getchar();
                getchar();
                system("cls");
            }
            else
            {
                mostrar_LSO(list);
            }
        break;
      }
   }
    return 0;
}
