#include <stdio.h>
#include <stdbool.h>

struct libro
{
    int isbn;
    char *nombre;
    char *autor;
    int paginas;
    float precio;

};


struct libro *libreria;
short seguimos = 1;
char *a;
char *endptr;
int numCampos = 5; 
int n = 0;

int main(){
    while(seguimos){
        printf("¿Quieres introducir un libro?: 0 o 1");
        scanf("%s", &a);
        long val = strtol(a, &endptr, 10);
        if (&endptr != "\0"){
            printf("mal escrito, prueba otra vez");
            continue;
        } 
        if (val != 1 && val != 0){
            printf("escriu soles un 1 o un 0 xe");
            continue;
        }
        if (val == 0) {
            printf("acabamos");
            break;
        }

        printf("Introduce ISBN:");
        scanf("%s", &a);
        //introducimos libro
        libreria[n].autor
    
    
   

    }


}
