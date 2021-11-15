#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void desafio8() {
    printf("----------DESAFIO 8----------\n");
    printf("SPOILER ALERT\n");
    printf("\033[30;40mLa respuesta es BUmyYq5XxXGt\033[0m\n");
}

int gdbme();
void desafio11() {
    printf("----------DESAFIO 11----------\n");
    printf("b gdbme\n");
    if (gdbme())
        printf("La respuesta es socotroco\n");
    
}