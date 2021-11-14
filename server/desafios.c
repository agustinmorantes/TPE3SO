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

#define COUNT     100
void desafio12() {
    printf("me conoces\n\n");

    //Seed
    rand_val(time(NULL));

    for(int i = 0; i < COUNT; i++)
        printf("%f ", norm(0, 1));

    fflush(stdout);
}
