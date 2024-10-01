//Tomas Muñoz Licciardello
//Matias Padula
//Grupo 17
#ifndef PRESTADOR_H_INCLUDED
#define PRESTADOR_H_INCLUDED
#include <string.h>
#define NYA 80
#define SER 120
#define DOM 80
#define EMA 50
#define CEL 30
typedef struct{
    int DNI;
    char nom_y_ape[NYA];
    char servicios[SER];
    char domicilio[DOM];
    char email[EMA];
    char celular[CEL];//cadena numeros enteros
}prestador;

void incializar_prestador(prestador *x){
    strcpy(x->celular,"");
    strcpy(x->nom_y_ape,"");
    strcpy(x->servicios,"");
    strcpy(x->email,"");
    strcpy(x->domicilio,"");
    x->DNI=0;
}

void cargar_celular(char c[],prestador *b){
    strcpy(b->celular,c);
}

void cargar_nom_y_ape(char n[], prestador *b){
    strcpy(b->nom_y_ape,n);
}

void cargar_DNI(int dni, prestador *b){
    b->DNI = dni;
}

void cargar_servicios(char s[], prestador *b){
    strcpy(b->servicios,s);
}

void cargar_email(char e[], prestador *b){
    strcpy(b->email,e);
}

void cargar_domicilio(char d[], prestador *b){
    strcpy(b->domicilio,d);
}

char* obtener_celular(prestador b){
    char *n;
    n=(char*)malloc(sizeof(char)*CEL);
    if(n!=NULL){
        strcpy(n,b.celular);
    }
    return n;
}

char* obtener_nom_y_ape(prestador b){
    char *n;
    n=(char*)malloc(sizeof(char)*NYA);
    if(n!=NULL){
        strcpy(n,b.nom_y_ape);
    }
    return n;
}

char* obtener_domicilio(prestador b){
    char *n;
    n=(char*)malloc(sizeof(char)*DOM);
    if(n!=NULL){
        strcpy(n,b.domicilio);
    }
    return n;
}

char* obtener_servicios(prestador b){
    char *n;
    n=(char*)malloc(sizeof(char)*SER);
    if(n!=NULL){
        strcpy(n,b.servicios);
    }
    return n;
}

char* obtener_email(prestador b){
    char *n;
    n=(char*)malloc(sizeof(char)*EMA);
    if(n!=NULL){
        strcpy(n,b.email);
    }
    return n;
}

int obtener_DNI(prestador b){
    return b.DNI;
}
//preguntar si se puede imprimir en esta funcion
void mostrar_prestador (prestador p){
    printf("------------------------------------------\n");
    printf("DNI: %d\n",obtener_DNI(p));
    printf("Nombre y Apellido: %s",obtener_nom_y_ape(p));
    printf("Servicio: %s",obtener_servicios(p));
    printf("Domicilio: %s",obtener_domicilio(p));
    printf("Email: %s",obtener_email(p));
    printf("Celular: %s",obtener_celular(p));
    printf("------------------------------------------\n");
}

/*char* MostrarMarcayModelo (vehiculo b){
    char *n;
    n=(char*)malloc(sizeof(char)*NOMB);
    if (n!=NULL)
        strcpy(n,b.MarcayModelo);
    return n;
}

int M*/
#endif // PRESTADOR_H_INCLUDED
