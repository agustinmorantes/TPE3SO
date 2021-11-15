#define DESAFIO_COUNT 12

typedef void (*DesafioFunc)();

typedef struct {
    char* pass;
    DesafioFunc setup;
} Desafio;

void desafio1();
void desafio2();
void desafio3();
void desafio4();
void desafio5();
void desafio6();
void desafio7();
void desafio8();
void desafio9();
void desafio10();
void desafio11();
void desafio12();

static Desafio desafios[DESAFIO_COUNT] = {
    {"entendido", (DesafioFunc)desafio1},
    {"itba", (DesafioFunc)desafio2}, //Telefono
    {"rickroll", (DesafioFunc)desafio3}, // Imagen
    {"42", (DesafioFunc)desafio4}, //EBADF
    {}, //strings:277
    {}, //.RUN_ME
    {"efghnowejnfpie",(DesafioFunc)desafio7}, //Filter error
    {"BUmyYq5XxXGt", (DesafioFunc)desafio8}, //Fondo en negro
    {"4", (DesafioFunc)desafio9}, //Latex
    {"chin_chu_lan_cha", (DesafioFunc)desafio10}, //quine.c
    {"socotroco", (DesafioFunc)desafio11}, //b gdme
    {"normal", (DesafioFunc)desafio12}, //normal
};
