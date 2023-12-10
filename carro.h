#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linhas.h"

typedef struct {
    int preco;
    int ano;
    char marca[TAMANHO_LINHA];
    char modelo[TAMANHO_LINHA];
    char condicao[TAMANHO_LINHA];
    char combustivel[TAMANHO_LINHA];
    int odometro;
    char status[TAMANHO_LINHA];
    char cambio[TAMANHO_LINHA];
    char tamanho[TAMANHO_LINHA];
    char tipo[TAMANHO_LINHA];
    char cor[TAMANHO_LINHA];
} Carro;

