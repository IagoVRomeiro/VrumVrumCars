#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_LINHA 200
#define OFERTAS "veiculos_ofertas.csv"
#define ESTOQUE "estoque.csv"
#define HISTORICO_COMPRAS "historico-compras.csv"
#define MARCAS "marcas.csv"
#define HISTORICO_VENDAS "historico-vendas.csv"

void remover_linha_arquivo(char *nome_arquivo, const char *remover_linha) {
    FILE *arquivocsv = fopen(nome_arquivo, "r");
    if (arquivocsv == NULL) {
        perror("falha em abrir arquivo principal");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_temporario = fopen("temporario.txt", "w");
    if (arquivo_temporario == NULL) {
        perror("falha em criar arquivo temporario");
        fclose(arquivocsv);
        exit(EXIT_FAILURE);
    }

    char buffer[TAMANHO_LINHA];

    while (fgets(buffer, TAMANHO_LINHA, arquivocsv) != NULL) {
        if (strstr(buffer, remover_linha) == NULL) {
            fputs(buffer, arquivo_temporario);
        }
    }

    fclose(arquivocsv);
    fclose(arquivo_temporario);

    remove(nome_arquivo);  
    rename("temporario.txt", nome_arquivo); 
}
void adicionar_linha_arquivo( char *nome_arquivo,  char *adicionar_linha) {
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        perror("falha em abrir arquivo");
        exit(EXIT_FAILURE);
    }

    fputs(adicionar_linha, arquivo);
    fputs("\n", arquivo);
    fclose(arquivo);
}
void atualizar_marca( char *marca, float taxa) {
    FILE *arquivo = fopen(MARCAS, "a+");
    if (arquivo == NULL) {
        perror("falha em abrir arquivo");
        exit(EXIT_FAILURE);
    }

    char buffer[TAMANHO_LINHA];
    int marcaEncontrada = 0;

    while (fgets(buffer, TAMANHO_LINHA, arquivo) != NULL) {
        if (strstr(buffer, marca) != NULL) {
            marcaEncontrada = 1;
            break;
        }
    }

    if (!marcaEncontrada) {
        
        fprintf(arquivo, "%s %.2f\n", marca, taxa);
    }

    fclose(arquivo);
}
void obter_data_hora_atual(char *buffer, unsigned int tamanho_buffer) {
    time_t tempo_registrado;
    struct tm *tempoinfo;

    time(&tempo_registrado);
    tempoinfo = localtime(&tempo_registrado);

    strftime(buffer, tamanho_buffer, "%Y-%m-%d %H:%M:%S", tempoinfo);
}




