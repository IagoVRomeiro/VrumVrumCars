#include "linhas.h"


int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Comprar\n");          
        printf("2. Venda\n");
        printf("3. Alterar Dados\n");
        printf("4. Exibir Compras e Vendas\n");
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
    scanf(" %[^\n]s", carroCompra.marca);

    printf("Modelo: ");
    scanf(" %[^\n]s", carroCompra.modelo);

    printf("Condicao: ");
    scanf(" %[^\n]s", carroCompra.condicao);

    printf("Combustivel: ");
    scanf(" %[^\n]s", carroCompra.combustivel);

    printf("Odometro: ");
    scanf("%d", &carroCompra.odometro);

    printf("Status: ");
    scanf(" %[^\n]s", carroCompra.status);

    printf("Cambio: ");
    scanf(" %[^\n]s", carroCompra.cambio);

    printf("Tamanho: ");
    scanf(" %[^\n]s", carroCompra.tamanho);

    printf("Tipo: ");
    scanf(" %[^\n]s", carroCompra.tipo);

    printf("Cor: ");
    scanf(" %[^\n]s", carroCompra.cor);

                marcasAdiciona(carroCompra.marca);
                remover_linha_arquivo(OFERTAS, Criarbuffer(carroCompra));
                adicionar_linha_arquivo(ESTOQUE, Criarbuffer(carroCompra));
                adicionar_linha_arquivo(HISTORICO_COMPRAS, Criarbuffer(carroCompra));

                printf("Carro comprado com sucesso!\n");

                break;
            }
            case 2: { //venda carro

                 Carro  carroVenda;
            printf("Digite os dados do carro que deseja vender:\n");
            printf("Preco: ");
            scanf("%d", &carroVenda.preco);

            printf("Ano: ");
            scanf("%d", &carroVenda.ano);

            printf("Marca: ");
            scanf(" %[^\n]s", carroVenda.marca);

            printf("Modelo: ");
            scanf(" %[^\n]s", carroVenda.modelo);

            printf("Condicao: ");
            scanf(" %[^\n]s", carroVenda.condicao);

            printf("Combustivel: ");
            scanf(" %[^\n]s", carroVenda.combustivel);

            printf("Odometro: ");
            scanf("%d", &carroVenda.odometro);

            printf("Status: ");
            scanf(" %[^\n]s", carroVenda.status);

            printf("Cambio: ");
            scanf(" %[^\n]s", carroVenda.cambio);

            printf("Tamanho: ");
            scanf(" %[^\n]s", carroVenda.tamanho);

            printf("Tipo: ");
            scanf(" %[^\n]s", carroVenda.tipo);

            printf("Cor: ");
            scanf(" %[^\n]s", carroVenda.cor);

                remover_linha_arquivo(ESTOQUE, Criarbuffer(carroVenda));
                adicionar_linha_arquivo(HISTORICO_VENDAS, Criarbuffer(carroVenda));
                removerLinhaPorMarca(ESTOQUE, MARCAS);

                printf("Carro vendido com sucesso!\n");                

                break;
            }
            case 3: { //alterar dados
                 editarArquivoCSV();
                 break;
            }    
            case 4: { //exibir historico vendas e compras
                 exibirHistorico(HISTORICO_COMPRAS);
                 exibirHistorico(HISTORICO_VENDAS);
                 break;
            } 
            case 5: {  
             printf("Saindo do programa...\n");
                break;
             }
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);
    return 0;
}

