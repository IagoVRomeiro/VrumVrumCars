# VrumVrumCars

Trabalho de AED1

Trabalho Prático: Sistema de compra e venda de veículos
Objetivo: O objetivo deste trabalho é desenvolver um sistema para gerenciar uma loja de veículos em
linguagem C. O programa terá funcionalidades que permitirão o controle do estoque, registro de
compras e vendas e acompanhamento do desempenho da loja.

1. Introdução
A loja VrumVrum compra carros de instituições financeiras (recuperados em processos judiciais por
inadimplência) e vende para clientes. Para facilitar a aquisição de veículos, a loja possui acesso a um
Sistema Web das instituições financeiras que cadastram os veículos em oferta. Os veículos ofertados
são exportados em um arquivo de texto veiculos_oferta.csv.
A partir desse arquivo, a loja pode optar em efetivar a compra do veículo ofertado, inserindo dados
do veículo no arquivo veiculos_estoque.csv. Uma vez o veículo adquirido, a loja poderá vender esse
veículo, removendo os dados do veículo do arquivo veiculos_estoque.csv. As transações de compra e
venda devem ser registradas também respectivamente nos arquivos historico_compras.csv e
historicos_vendas.csv
Você foi contratado para desenvolver um sistema de gerenciamento de compras e vendas
considerando as ofertas disponíveis e os detalhes desse sistema são apresentados a seguir.

2. Funcionalidades
2.1 Compra de veículos
Seu sistema deve permitir que a loja efetue a compra de veículos a partir das ofertadas disponíveis no
arquivo veiculos_oferta.csv. Sempre que um compra é efetuada, os dados do veículo são removidos
do arquivo veiculos_oferta.csv e adicionados em um arquivo veiculos_estoque.csv, com o novo preço
de venda pretendido. Os veículos no arquivo veiculos_estoque.csv, devem ser mantidos ordenados
em ordem alfabética por marca, e veículos da mesma marca são mantidos ordenados em ordem
alfabética por modelo. Além disso, a compra deve ser registrada no histórico de compras da empresa,
no arquivo "historico_compras.csv". Todo registro de compra deve conter data e hora atual.
Um arquivo marcas.csv deverá ser mantido com as marcas dos veículos em estoque. Além da marca,
esse arquivo deve armazenar um valor de taxa aplicável, a partir de 0%, que será aplicado no momento
da venda, conforme detalhado na seção 2.3.
Caso a loja não possua outros veículos da mesma marca em estoque, é necessário adicionar a marca
no arquivo marcas.csv. Caso a loja venda o último veículo da marca do estoque, será necessário
remover o veículo do arquivo marcas.csv.

2.2 Venda de veículos
Seu sistema também deve permitir a venda de veículos. Sempre que uma venda for efetuada, ela deve
ser registrada no arquivo historico_vendas.csv e o veículo adquirido deve ser removido do arquivo
veiculos_estoque.csv. Todo registro de venda deve conter data e hora atual.

2.3 Taxas
A VrumVrum Cars possui taxas específicas para cada marca a serem aplicadas no valor de seus
veículos. Como essa taxa varia ao longo do tempo, o preço do veículo no arquivo veiculos_estoque.csv
é considerado o preço base. O preço final para o consumidor (que deve ser mostrado ao se pesquisar
um veículo para venda), é o preço base multiplicado pela taxa aplicada. Cada marca de veículo contém
uma taxa percentual, registrada no arquivo “marcas.csv”. A taxa aplicada deverá ser informada pelo
usuário no cadastro ou alteração da marca.

2.4 Alteração de dados
É necessário considerar a possibilidade de um veículo ter sido cadastrado com algum dado errado,
assim como a taxa de uma marca de veículos pode variar. Portanto, o sistema deve permitir alterar os
dados de um veículo, não apenas no momento de sua compra, mas a qualquer momento após ser
adquirido. Também deve ser possível alterar taxas já cadastradas no arquivo “marcas.csv”.

2.5 Filtros de busca
Nas opções de compra, venda e alteração de dados de um veículo, uma busca deve ser feita no(s)
arquivo(s) correspondente(s). Ao realizar uma busca, seu sistema deve permitir que o usuário
pesquise por marca, modelo, cor etc. Dessa maneira, o sistema deve permitir adicionar e remover
filtros de busca.

2.6 Ordenação
Sempre que uma busca é realizada no sistema, os resultados encontrados devem ser exibidos em uma
ordem específica. No caso de compras e vendas de veículos, deve-se ter uma opção para ordenar pelo
(a) veículo mais barato, (b) veículo mais caro ou (c) ordenado por marca e modelo em ordem alfabética
(ignorando maiúsculas e minúsculas), em que veículos da mesma marca são ordenados pelo modelo.

2.7 Relatórios de compras e vendas
O sistema deve conter uma opção para gerar um relatório do extrato de compras e vendas de um
período determinado (datas de início e fim) e o saldo final considerando somente este período. O
usuário deve escolher se o relatório será exibido na tela ou escrito em um arquivo específico.

2.8 Backup
Para proteger os dados de eventuais falhas, o programa deve efetuar um backup de todos os arquivos
em formato binários quando solicitado pelos usuários, em uma subpasta chamada “backup”. O
programa deverá também permitir a exclusão dos arquivos de backup.

4. Especificações
• Seu programa deve ser implementado em C. Outras linguagens não serão aceitas.
• Seu programa deve ser conter um menu com opções que permitam realizar as funcionalidades
descritas. O programa só deve parar sua execução quando o usuário escolher a opção “Sair” no
menu. Sempre que o programa voltar ao menu, a tela de saída deve ser limpa.
• Seu programa deve modelar a solução com uma struct Veiculo e uma struct Marca.
• Seu programa deve tratar entradas e/ou comportamentos inesperados do sistema. Somente em
último caso (espera-se que em nenhum) o programa irá terminar sua execução em decorrência
de algum erro.
• É estritamente proibido ler/manter todos os dados de quaisquer arquivos na memória. Quando
alguma informação é necessária, deve-se ler cada arquivo no máximo linha a linha, mantendo
somente aqueles que forem usados na saída/escrita.
• A inclusão de novas funcionalidades é permitida, desde que estas estejam na linguagem C e não
alterem as funcionalidades da Seção 2 deste documento.
• O trabalho deverá ser feito individualmente ou em dupla, sendo recomendado que seja feito em
dupla.
• Entrevista: cada dupla será entrevistada pelo professor e a nota será individualmente calculada.
Os alunos deverão preparar no computador em laboratório, o projeto e código-fonte para a
entrevista. A data e horário da entrevista serão definidas pelo professor e comunicada aos
alunos.
• Entrega: a entrega do trabalho será definida na tarefa no Canvas. Os alunos deverão entregar o
código-fonte comentado.

5. Informações adicionais
• Função para identificar data e hora atual: https://devdocs.io/c/chrono/localtime
• Informações sobre como limpar a tela de saída (prompt de comando):
https://www.geeksforgeeks.org/clear-console-c-language/
• Função para alterar o tamanho de um vetor dinamicamente alocado:
https://devdocs.io/c/memory/realloc
