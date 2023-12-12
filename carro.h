#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_LINHA 200

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

char* Criarbuffer(Carro carro) {
    char *buffer = (char *)malloc(TAMANHO_LINHA);
    if (buffer == NULL) {
        perror("Falha ao alocar memória para buffer");
        exit(EXIT_FAILURE);
    }

    snprintf(buffer, TAMANHO_LINHA, "%d,%d,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s\n",
             carro.preco, carro.ano, carro.marca, carro.modelo,
             carro.condicao, carro.combustivel, carro.odometro,
             carro.status, carro.cambio, carro.tamanho,
             carro.tipo, carro.cor);

    return buffer;
}