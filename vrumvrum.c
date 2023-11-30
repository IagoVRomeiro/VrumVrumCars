#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_LINHA 50
#define OFERTAS "veiculos_ofertas.cmd"
#define ESTOQUE "estoque.cmd"
#define HISTORICO_COMPRAS "historico-compra.cmd"
#define MARCAS "marcas.cmd"

typedef struct {
    float preco;
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

void remover_linha_arquivo( char *nome_arquivo,  char *remover_linha) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("falha em abrir removedor de linha");
        exit(EXIT_FAILURE);
    }

    FILE *arquivo_temporario = fopen("temporario.txt", "w");
    if (arquivo_temporario == NULL) {
        perror("falha em criar arquivo temporario");
        exit(EXIT_FAILURE);
    }

    char buffer[TAMANHO_LINHA];

    while (fgets(buffer, TAMANHO_LINHA, arquivo) != NULL) {
        if (strstr(buffer, remover_linha) == NULL) {
            fputs(buffer, arquivo_temporario);
        }
    }

    fclose(arquivo);
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

int main() {
    int opcao;
    char buffer[TAMANHO_LINHA];

    do {
        printf("\nMenu:\n");
        printf("1. Comprar\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Carro carroCompra;

                printf("Digite os dados do carro que deseja comprar:\n");
                printf("Preco: ");
                scanf("%f", &carroCompra.preco);
                printf("Ano: ");
                scanf("%d", &carroCompra.ano);
                printf("Marca: ");
                scanf("%s", carroCompra.marca);
                printf("Modelo: ");
                scanf("%s", carroCompra.modelo);
                printf("Condicao: ");
                scanf("%s", carroCompra.condicao);
                printf("Combustivel: ");
                scanf("%s", carroCompra.combustivel);
                printf("Odometro: ");
                scanf("%d", &carroCompra.odometro);
                printf("Status: ");
                scanf("%s", carroCompra.status);
                printf("Cambio: ");
                scanf("%s", carroCompra.cambio);
                printf("Tamanho: ");
                scanf("%s", carroCompra.tamanho);
                printf("Tipo: ");
                scanf("%s", carroCompra.tipo);
                printf("Cor: ");
                scanf("%s", carroCompra.cor);


                snprintf(buffer, TAMANHO_LINHA, "%.2f,%d,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s\n",
                         carroCompra.preco, carroCompra.ano, carroCompra.marca, carroCompra.modelo,
                         carroCompra.condicao, carroCompra.combustivel, carroCompra.odometro,
                         carroCompra.status, carroCompra.cambio, carroCompra.tamanho,
                         carroCompra.tipo, carroCompra.cor);


                remover_linha_arquivo(OFERTAS, buffer);

                adicionar_linha_arquivo(ESTOQUE, buffer);

                adicionar_linha_arquivo(HISTORICO_COMPRAS, buffer);

                float taxa;
                printf("Digite a taxa de venda para a marca %s: ", carroCompra.marca);
                scanf("%f", &taxa);
                atualizar_marca(carroCompra.marca, taxa);

                printf("Carro comprado com sucesso!\n");

                break;
            }

            case 8:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 8);

    return 0;
}