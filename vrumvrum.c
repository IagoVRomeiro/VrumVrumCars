#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "carro.h"

#define TAMANHO_LINHA 50
#define OFERTAS "veiculos_ofertas.cmd"
#define ESTOQUE "estoque.cmd"
#define HISTORICO_COMPRAS "historico-compras.cmd"
#define MARCAS "marcas.cmd"
#define HISTORICO_VENDAS "historico-vendas.cmd"





int main() {
    int opcao;
    char buffer[TAMANHO_LINHA];

    do {
        printf("\nMenu:\n");
        printf("1. Comprar\n");          
        printf("2. Venda\n");
        printf("3. Alterar Dados\n");
        printf("4. Backup\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: { //compra carro
                Carro carroCompra;

                printf("Digite os dados do carro que deseja comprar:\n");
                printf("Preco: ");
                /*
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
                */
                carroCompra.preco = 1000;

                carroCompra.ano = 1997;
                strcpy(carroCompra.marca, "acura");

                strcpy(carroCompra.modelo, "3.0cl");
               
                strcpy(carroCompra.condicao,"razoavel");
             
                strcpy(carroCompra.combustivel,"gasolina");
               
                carroCompra.odometro = 300000;
               
                strcpy(carroCompra.status,"desconhecido");
            
                strcpy(carroCompra.cambio,"automatico");
              
                strcpy(carroCompra.tamanho,"compacto");
               
                strcpy(carroCompra.tipo,"coupe");
              
                strcpy(carroCompra.cor, "vermelho");

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

        printf("Carro vendido com sucesso em %s!\n", data_hora);
                        break;
            }
            case 3: { //alterar dados
                        break;
            }
            case 4: { //backup
                        break;
            } 
            case 5: { //sair
                        break;
            } 
            
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 5);

    return 0;
}