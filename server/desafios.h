#define DESAFIO_COUNT 11

typedef void (*DesafioFunc)();

typedef struct {
    char* pass;
    DesafioFunc setup;
} Desafio;

void desafio1();
void desafio2();
void desafio3();
void desafio7();
void desafio9();

static Desafio desafios[DESAFIO_COUNT] = {
    {"entendido", (DesafioFunc)desafio1},
    {"https://www.youtube.com/watch?v=dQw4w9WgXcQ", (DesafioFunc)desafio2}, // Imagen
    {"42", (DesafioFunc)desafio3}, //EBADF
    {}, //strings:277
    {}, //.RUN_ME
    {"efghnowejnfpie",(DesafioFunc)desafio7}, //Filter error
    {}, //Fondo en negro
    {"4", (DesafioFunc)desafio9}, //Latex
    {}, //quine.c
    {}, //b gdme
    {}, //normal
};
