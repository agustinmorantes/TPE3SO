#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "normal.h"

void desafio1() {
    printf("PRIMER DESAFIO\n");
    printf("eNtEnDiDo?\n");
}

void desafio2() {
    printf("https://ibb.co/V9wwL6v\n");
}

void desafio3() {
    printf("Bueno este es igual al suyo\n");
    write(13, ".............................................................La respuesta es 42, como siempre", 94);
}

void desafio10() {
    if(system("gcc quine.c -o quine") != 0) {
        printf("No se encuentra quine.c valido\n");
        return;
    }

    if(system("./quine > quine.out") != 0) {
        printf("Error al ejecutar quine\n");
        return;
    }

    FILE* diffOut;
    if((diffOut = popen("diff -a quine.c quine.out", "r")) == NULL) {
        perror("Error al ejecutar diff");
        remove("quine.out");
        return;
    }

    char c;
    while((c = fgetc(diffOut)) != EOF)
        putchar(c);

    if(pclose(diffOut) != 0) {
        printf("\n=========================================\n");
        printf("El output de quine no coincide con quine.c\n");
        remove("quine.out");
        return;
    }

    remove("quine.out");

    printf("La respuesta es: chin_chu_lan_cha\n");
}

#define NORM_COUNT     100
void desafio12() {
    printf("me conoces\n\n");

    //Seed
    rand_val(time(NULL));

    for(int i = 0; i < NORM_COUNT; i++)
        printf("%f ", norm(0, 1));

    fflush(stdout);
}
