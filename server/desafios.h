#define DESAFIO_COUNT 12

typedef void (*DesafioFunc)();

typedef struct {
    char* pass;
    DesafioFunc setup;
} Desafio;

void desafio1();
void desafio2();
void desafio3();
void desafio10();
void desafio12();

static Desafio desafios[DESAFIO_COUNT] = {
    {"entendido", (DesafioFunc)desafio1},
    {"https://www.youtube.com/watch?v=dQw4w9WgXcQ", (DesafioFunc)desafio2}, // Imagen
    {"42", (DesafioFunc)desafio3}, //EBADF
    {}, //strings:277
    {}, //.RUN_ME
    {}, //Filter error
    {}, //Fondo en negro
    {}, //Latex
    {"chin_chu_lan_cha", (DesafioFunc)desafio10}, //quine.c
    {}, //b gdme
    {"normal", (DesafioFunc)desafio12}, //normal
};
