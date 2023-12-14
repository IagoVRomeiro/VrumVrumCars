#define OFERTAS "veiculos_ofertas.csv"
#define ESTOQUE "estoque.csv"
#define HISTORICO_COMPRAS "historico-compras.csv"
#define MARCAS "marcas.csv"
#define HISTORICO_VENDAS "historico-vendas.csv"

#include "carro.h"


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
    rename("temporario.txt", nome_arquivo); }

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

void removerLinhaPorMarca(const char *nomeArquivoEstoque, char *nomeArquivoMarcas) {
    FILE *estoque = fopen(nomeArquivoEstoque, "r");
    FILE *marcas = fopen(nomeArquivoMarcas, "r");
    FILE *temporario = fopen("temp.csv", "w");

    if (estoque == NULL || marcas == NULL || temporario == NULL) {
        perror("Falha ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    char bufferEstoque[TAMANHO_LINHA];
    char bufferMarcas[TAMANHO_LINHA];

    while (fgets(bufferMarcas, TAMANHO_LINHA, marcas) != NULL) {
        char *token = strtok(bufferMarcas, "=");
        if (token != NULL) {
            // extrair a marca do arquivo marcas.csv
            char *marca = strtok(NULL, "=");
            strtok(marca, " :");
            
            // Verificar se a marca está presente no arquivo estoque.csv
            int marcaEncontrada = 0;
            rewind(estoque);
            while (fgets(bufferEstoque, TAMANHO_LINHA, estoque) != NULL) {
                char *tokenEstoque = strtok(bufferEstoque, ",");
                tokenEstoque = strtok(NULL, ",");
                if (tokenEstoque != NULL && strcmp(tokenEstoque, marca) == 0) {
                    marcaEncontrada = 1;
                    break;
                }
            }

            // Se a marca não for encontrada em estoque.csv, remover a linha
            if (!marcaEncontrada) {} 
            else {fputs(bufferMarcas, temporario);}
        }
    }

    fclose(estoque);
    fclose(marcas);
    fclose(temporario);

    remove(nomeArquivoMarcas);
    rename("temp.csv", nomeArquivoMarcas);
}

void marcasAdiciona(char *marca) {

FILE *arquivoMarcas = fopen(MARCAS, "a+");
    if (arquivoMarcas == NULL) {
        perror("falha em abrir arquivo");
        exit(EXIT_FAILURE);
    }

    char buffer[TAMANHO_LINHA];
    int marcaEncontrada = 0;

    while (fgets(buffer, TAMANHO_LINHA, arquivoMarcas) != NULL) {
        if (strstr(buffer, marca) != NULL) {
            marcaEncontrada = 1;
            break;
        }
    }


    if (!marcaEncontrada) {
        float taxa;
        printf("Digite a taxa de venda para a marca %s: ", marca);
        scanf("%f", &taxa);

        fprintf(arquivoMarcas, "%s = taxa: %.2f\n", marca, taxa);
    }
         fclose(arquivoMarcas);
}

void exibirConteudo(FILE *arquivo) {
    char ch;
    rewind(arquivo);

    while ((ch = fgetc(arquivo)) != EOF) {
        printf("%c", ch);
    }

    printf("\n");
}

void editarArquivoCSV() {
    char nome_arquivo[TAMANHO_LINHA];

    printf("Escolha o arquivo CSV que deseja editar:\n");
    printf("1. %s\n", MARCAS);
    printf("2. %s\n", ESTOQUE);
    printf("Digite o numero correspondente: ");

    int escolha;
    scanf("%d", &escolha);

    // Limpar o buffer do teclado
    while (getchar() != '\n');

    FILE *arquivo;

    switch (escolha) {
        case 1:
            strcpy(nome_arquivo, MARCAS);
            break;
        case 2:
            strcpy(nome_arquivo, ESTOQUE);
            break;
        default:
            printf("Escolha invalida. Saindo...\n");
            return;
    }

    arquivo = fopen(nome_arquivo, "r+");
    if (arquivo == NULL) {
        perror("Falha ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Exibir o conteúdo atual do arquivo
    printf("Conteudo atual do arquivo %s:\n", nome_arquivo);
    exibirConteudo(arquivo);

    // Permitir ao usuário editar o conteúdo
    printf("Edite o conteudo. Pressione Ctrl+D (ou Ctrl+Z no Windows) para encerrar a ediçao:\n");

    char buffer[TAMANHO_LINHA];
    fseek(arquivo, 0, SEEK_SET); // Voltar ao início do arquivo antes da edição

    while (fgets(buffer, TAMANHO_LINHA, stdin) != NULL) {
        fputs(buffer, arquivo);
    }

    // Solicitar ao usuário se deseja salvar as alterações
    printf("Pressione Enter para salvar as alteraçoes, ou qualquer outra tecla para sair sem salvar: ");
    char salvar;
    scanf("%c", &salvar);

    if (salvar == '\n') {
        printf("Salvando as alteraçoes...\n");
        fflush(arquivo); // Descarregar o buffer antes de fechar o arquivo
    } else {
        printf("Alteraçoes descartadas. Saindo sem salvar.\n");
    }

    // Fechar o arquivo
    fclose(arquivo);
}

void exibirHistorico(const char *arquivo) {
    FILE *arquivoCSV = fopen(arquivo, "r");

    if (arquivoCSV == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", arquivo);
        return;
    }

    char linha[TAMANHO_LINHA];

    // Imprime o cabeçalho
    if (fgets(linha, TAMANHO_LINHA, arquivoCSV) != NULL) {
        printf("Historico de %s:\n", arquivo);
        printf("%s", linha);
    }

    // Imprime as linhas de dados
    while (fgets(linha, TAMANHO_LINHA, arquivoCSV) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivoCSV);
}