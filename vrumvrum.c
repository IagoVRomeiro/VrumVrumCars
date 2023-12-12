#include "linhas.h"


int main() {
    int opcao;
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
/*
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



                marcasAdiciona(carroCompra.marca);
                remover_linha_arquivo(OFERTAS, Criarbuffer(carroCompra));
                adicionar_linha_arquivo(ESTOQUE, Criarbuffer(carroCompra));
                adicionar_linha_arquivo(HISTORICO_COMPRAS, Criarbuffer(carroCompra));

                 printf("Carro comprado com sucesso!\n");

                break;
            }
            case 2: { //venda carro

                 Carro  carroVenda;

                carroVenda.preco = 1000;
                carroVenda.ano = 1997;
                strcpy( carroVenda.marca, "acura");
                strcpy( carroVenda.modelo, "3.0cl");
                strcpy( carroVenda.condicao,"razoavel");
                strcpy( carroVenda.combustivel,"gasolina");
                carroVenda.odometro = 300000;
                strcpy( carroVenda.status,"desconhecido");
                strcpy( carroVenda.cambio,"automatico");
                strcpy( carroVenda.tamanho,"compacto");
                strcpy( carroVenda.tipo,"coupe");
                strcpy( carroVenda.cor, "vermelho");

                
                remover_linha_arquivo(ESTOQUE, Criarbuffer(carroVenda));
                adicionar_linha_arquivo(HISTORICO_VENDAS, Criarbuffer(carroVenda));

                 char marcaDoBuffer[TAMANHO_LINHA];

                 sscanf(Criarbuffer(carroVenda), "%*[^,],%*[^,],%[^,]", marcaDoBuffer);  


                 printf("Carro vendido com sucesso!\n");                

                
                break;
            }
            case 3: { //alterar dados
                 int escolha;
                      printf("Escolha o arquivo que deseja alterar\n");
                      printf("1 = Estoque\n");
                      printf("2 = Lista de Ofertas\n");

                 scanf("%d", &escolha);


                if(escolha==1){}
                else if(escolha==2){}

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