#define DESAFIO_COUNT 11

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
    {"https://www.youtube.com/watch?v=dQw4w9WgXcQ", (DesafioFunc)desafio2}, // Imagen
    {"42", (DesafioFunc)desafio3}, //EBADF
    {}, //strings:277
    {}, //.RUN_ME
    {}, //Filter error
    {}, //Fondo en negro
    {}, //Latex
    {}, //quine.c
    {}, //b gdme
    {}, //normal
};
