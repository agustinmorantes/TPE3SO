#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

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

void desafio9() {
    printf("latexme\n");
    char * eq = "y=2+2";
    printf("Si\n%s\nEntonces\ny = ", eq);
}
