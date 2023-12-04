
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_LINHA 50
#define OFERTAS "veiculos_ofertas.cmd"
#define ESTOQUE "estoque.cmd"
#define HISTORICO_COMPRAS "historico-compras.cmd"
#define MARCAS "marcas.cmd"
#define HISTORICO_VENDAS "historico-vendas.cmd"

void remover_linha_arquivo(char *nome_arquivo, char *remover_linha) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("falha em abrir removedor de linha");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_temporario = fopen("temporario.txt", "w");
    if (arquivo_temporario == NULL) {
        perror("falha em criar arquivo temporario");
        fclose(arquivo);  // Feche o arquivo principal antes de sair
        exit(EXIT_FAILURE);
    }

    char buffer[TAMANHO_LINHA];
    int linhaRemovida = 0;  // Flag para verificar se a linha foi removida com sucesso

    while (fgets(buffer, TAMANHO_LINHA, arquivo) != NULL) {
        if (strstr(buffer, remover_linha) == NULL) {
            fputs(buffer, arquivo_temporario);
        } else {
            linhaRemovida = 1;
        }
    }

    fclose(arquivo);
    fclose(arquivo_temporario);

    // Remova o arquivo original e renomeie o temporário apenas se uma linha foi removida
    if (linhaRemovida) {
        remove(nome_arquivo);
        if (rename("temporario.txt", nome_arquivo) != 0) {
            perror("falha ao renomear arquivo temporario");
            exit(EXIT_FAILURE);
        }

    remove(nome_arquivo);
    rename("temporario.txt", nome_arquivo);
}
}
void adicionar_linha_arquivo( char *nome_arquivo,  char *adicionar_linha) {
    FILE *arquivo = fopen(nome_arquivo, "a");
    if (arquivo == NULL) {
        perror("falha em abrir arquivo");
        exit(EXIT_FAILURE);
    }

    fputs(adicionar_linha, arquivo);
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
