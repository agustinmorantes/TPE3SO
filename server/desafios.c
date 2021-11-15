#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "normal.h"

void desafio1() {
    printf("----------DESAFIO 1----------\n");
    printf("eNtEnDiDo?\n");
}

void desafio2() {
    printf("----------DESAFIO 2----------\n");
    printf("The Wire S1E5\n");
    printf("5295 888 6288\n");
}

void desafio3() {
    printf("----------DESAFIO 3----------\n");
    printf("https://ibb.co/V9wwL6v\n");
}

void desafio4() {
    printf("----------DESAFIO 4----------\n");
    write(13, ".............................................................La respuesta es 42, como siempre", 94);
    perror("Write");
}

void desafio5() {
    printf("strings:48\n");
}

void desafio6() {
    printf("SECTION .custom\n");
}

double randNormalize(void) {
    return rand() / ( (double) RAND_MAX + 1);
}

int randInt(int izq, int der) {
    return (int)(randNormalize() * (der - izq + 1) + izq);
}

void desafio7() {
    printf("filter error\n\n");
    char * respuesta = "efghnowejnfpie";
    char * options = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
    char error[100];
    
    srand((int)time(NULL));

    int random;
    for (int i = 0; i < 100; i++) {
        random = randInt(0,62);
        error[i] = options[random];
    }
    
    int i,j;
    for (i = 0, j = 0; i < 100 && j < 15;) {
        random = rand();
        if (random > RAND_MAX/2) {
            fprintf(stdout,"%c",respuesta[j++]);
            fflush(stdout);
        } else {
            fprintf(stderr,"%c",error[i++]);
        }
    }

    if (i < 100)
        fprintf(stderr,"%s",&error[i]);
    

    if (j < 15)
        printf("%s",&respuesta[i]);

    putchar('\n');
}

void desafio8() {
    printf("----------DESAFIO 8----------\n");
    printf("SPOILER ALERT\n");
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
}

void desafio9() {
    printf("latexme\n");
    char * eq = "y=2+2";
    printf("Si\n%s\nEntonces\ny = ", eq);
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

int gdbme();
void desafio11() {
    printf("----------DESAFIO 11----------\n");
    printf("b gdbme\n");
    if (gdbme())
        printf("La respuesta es socotroco\n");
    
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
