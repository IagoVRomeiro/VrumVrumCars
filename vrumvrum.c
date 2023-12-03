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

//compra
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

//venda
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
void obter_data_hora_atual(char *buffer, int tamanho_buffer) {
    time_t tempo_registrado;
    struct tm *tempoinfo;

    time(&tempo_registrado);
    tempoinfo = localtime(&tempo_registrado);

    strftime(buffer, tamanho_buffer, "%Y-%m-%d %H:%M:%S", tempoinfo);
}


int main() {
    int opcao;
    char buffer[TAMANHO_LINHA];

    do {
        printf("\nMenu:\n");
        printf("1. Comprar\n");          
        printf("2. Venda\n");
        printf("3. Alterar Dados");
        printf("4. Backup");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: { //compra carro
                Carro carroCompra;

                printf("Digite os dados do carro que deseja comprar:\n");
                printf("Preco: ");
                scanf("%d", &carroCompra.preco);
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


                snprintf(buffer, TAMANHO_LINHA, "%d,%d,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s\n",
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
            case 2: { //venda carro

        Carro carroVenda;

        printf("Digite os dados do carro que deseja vender:\n");
        printf("Marca: ");
        scanf("%s", carroVenda.marca);
        printf("Modelo: ");
        scanf("%s", carroVenda.modelo);

        char data_hora[TAMANHO_LINHA]; 

        obter_data_hora_atual(data_hora, TAMANHO_LINHA);
        vender_carro(&carroVenda);

        printf("Carro vendido com sucesso em %s!\n", data_hora);
            }
            case 3: { //alterar dados
            }
            case 4: { //backup
            } 
            case 5: { //sair
            } 
            
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 5);

    return 0;
}