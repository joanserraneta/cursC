#include <stdio.h>
#include <stdbool.h>
#include <ctype.h> // Para isalpha()
#include <stdlib.h>

struct libro
{
    int isbn;
    char *nombre;
    char *autor;
    int paginas;
    float precio;

};
struct libro *libreria = NULL;
int numLibros = 0;
short seguimos = 1;
char *a;
char *endptr;
int numCampos = 5; 
int n = 0;

//if error then = 1
int sonLetras(char *palabra){
    for(int i = 0; palabra[i] != '\n'; i++){
        if (!isalpha(palabra[i])){
           return 1;
        }

    }
    return 0;
}

int introLibro(){

    char *sisbn;
    char *snombre;
    char *ssautor;
    char *spaginas;
    char *sprecio;
    
    int error=0;
    struct libro lib;
    sisbn = (char *)malloc(20 * sizeof(char));
    printf("Introduce ISBN:\n");
    scanf("%s", sisbn);
    //introducimos libro
    long entr = strtol(sisbn, &endptr, 10);
    if (*endptr != '\0'){
        printf("ISBN mal escrito, prueba otra vez\n");
        error = 1;
    } 
    else if (entr <= 0){
        printf("Has puesto un isbn negativo\n");
        error =  2;
    }
    snombre = (char *)malloc(20 * sizeof(char));
    printf("Introduce nombre:\n");
    scanf("%s", snombre);
    if(!sonLetras(snombre)){
        printf("no has escrito un nombre\n");
        error = 1;
    }
    ssautor = (char *)malloc(20 * sizeof(char));
    printf("Introduce autor:");
    scanf("%s", ssautor);
    if(!sonLetras(ssautor)){
        printf("no has escrito un autor\n");
        error = 1;
    }
    spaginas = (char *)malloc(20 * sizeof(char));
    printf("Introduce paginas:");
    scanf("%s", spaginas);
    long pags = strtol(spaginas, &endptr, 10);
    if (*endptr != '\0'){
        printf("paginas mal escrito, prueba otra vez\n");
        error = 1;
    } 
    else if (entr <= 0){
        printf("Has puesto un paginas negativo\n");
        error =  2;
    }
    sprecio = (char *)malloc(20 * sizeof(char));
    printf("Introduce precio:");
    scanf("%s", sprecio);
    float prec = strtof(sisbn, &endptr);
    if (*endptr != '\0'){
        printf("precio mal escrito, prueba otra vez\n");
        error = 1;
    } 
    else if (entr <= 0){
        printf("Has puesto precio en negativo\n");
        error =  2;
    }

    if (error == 0){
        lib.paginas= pags;
        lib.nombre = snombre;
        lib.isbn = entr;
        lib.precio = prec;
        lib.autor = ssautor;
    }
    numLibros++;
    libreria= (struct libro *)realloc(libreria, numLibros * sizeof(struct libro));
    libreria[numLibros-1] = lib;
}

int main(){
    while(seguimos){
        printf("¿Quieres introducir un libro?: 0 o 1 \n");
        a = (char *)malloc(10 * sizeof(char));
        scanf("%s", a);
        long val = strtol(a, &endptr, 10);
        if (*endptr != '\0'){
            printf("mal escrito, prueba otra vez\n");
            continue;
        } 
        if (val != 1 && val != 0){
            printf("escriu soles un 1 o un 0 xe\n");
            continue;
        }
        if (val == 0) {
            printf("acabamos\n");
            break;
        }else{
            introLibro();
            }
    }
}
