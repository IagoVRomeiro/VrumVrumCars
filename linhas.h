
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_LINHA 50
#define OFERTAS "veiculos_ofertas.csv"
#define ESTOQUE "estoque.csv"
#define HISTORICO_COMPRAS "historico-compras.csv"
#define MARCAS "marcas.csv"
#define HISTORICO_VENDAS "historico-vendas.csv"

void remover_linha_arquivo(char *nome_arquivo, char *remover_linha) {
    // FILE *arquivocsv = fopen(nome_arquivo, "r"); 
    FILE *arquivocsv = fopen(OFERTAS, "r");
    if (arquivocsv == NULL) {
        perror("falha em abrir removedor de linha");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_temporario = fopen("temporario.txt", "w");
    if (arquivo_temporario == NULL) {
        perror("falha em criar arquivo temporario");
        fclose(arquivocsv);  // Feche o arquivo principal antes de sair
        exit(EXIT_FAILURE);
    }

    char buffer[TAMANHO_LINHA];
    int linhaRemovida = 0;  // Flag para verificar se a linha foi removida com sucesso

    FILE *arquivo_registro = fopen("registro.txt", "a+");
    if (arquivo_registro == NULL) {
        perror("falha em criar arquivo temporario");
        fclose(arquivocsv);  // Feche o arquivo principal antes de sair
        exit(EXIT_FAILURE);
    }


    while (fgets(buffer, TAMANHO_LINHA, arquivocsv) != NULL) {
        if (strstr(buffer, remover_linha) == NULL) {
            fputs(buffer, arquivo_temporario);
            linhaRemovida = 1;
        }
    }

    fclose(arquivocsv);
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
/* venda
void vender_carro(Carro *carroVenda) {
    
    FILE *arquivo_estoque = fopen(ESTOQUE, "r");
    if (arquivo_estoque == NULL) {
        perror("Falha em abrir arquivo de estoque");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_temporario = fopen("temporario.txt", "w");
    if (arquivo_temporario == NULL) {
        perror("Falha em criar arquivo temporario");
        fclose(arquivo_estoque);
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_historico = fopen(HISTORICO_VENDAS, "a");
    if (arquivo_historico == NULL) {
    perror("Falha em abrir arquivo de histórico de vendas");
    exit(EXIT_FAILURE);
}

    char buffer[TAMANHO_LINHA];
    int carroVendido = 0;

    while (fgets(buffer, TAMANHO_LINHA, arquivo_estoque) != NULL) {
        if (strstr(buffer, carroVenda->marca) != NULL && strstr(buffer, carroVenda->modelo) != NULL) {
            carroVendido = 1;

            // registrar a venda
            char data_hora[TAMANHO_LINHA];
            obter_data_hora_atual(data_hora, TAMANHO_LINHA);
            snprintf(buffer, TAMANHO_LINHA, "%s,%s,%s,%d\n", data_hora, carroVenda->marca, carroVenda->modelo, carroVenda->preco);
            adicionar_linha_arquivo(HISTORICO_VENDAS, buffer);
        } else {
            fputs(buffer, arquivo_temporario);
        }
    }

    fclose(arquivo_estoque);
    fclose(arquivo_temporario);

    if (!carroVendido) {
        printf("Carro não encontrado no estoque.\n");
        remove("temporario.txt");
        return;
    }

    remove(ESTOQUE);
    if (rename("temporario.txt", ESTOQUE) != 0) {
        perror("Falha ao renomear arquivo temporario");
        exit(EXIT_FAILURE);
    }
}
*/