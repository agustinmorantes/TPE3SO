#define DESAFIO_COUNT 3

typedef void (*DesafioFunc)();

typedef struct {
    char* pass;
    DesafioFunc setup;
} Desafio;

void desafio1();
void desafio2();
void desafio3();

static Desafio desafios[DESAFIO_COUNT] = {
    {"entendido", (DesafioFunc)desafio1},
    {"https://www.youtube.com/watch?v=dQw4w9WgXcQ", (DesafioFunc)desafio2},
    {"coto", (DesafioFunc)desafio3}
};
