#include <cstdio>
#include <iostream>

using namespace std;

class Carro {
  public: string marca, modelo, condicao, combustivel, status, cambio, tamanho, tipo, cor; 
  int preco, ano, odometro;
};

class MarcaTaxa{
  public: string marca;
  int taxa;
};

//funções
void LerCarros() {}

void ComprarCarros() {}

void VenderCarros() {}

void RegistrarCompra() {}

void RegistrarVenda() {}

void PesquisarCarros() {}

void AlterarCarros() {}

void OrdernarAlfabetico() {}

int main() {
  FILE *veiculos_ofertas;
  veiculos_ofertas = fopen("veiculos_ofertas.csv", "r+");

  if (veiculos_ofertas != NULL) {

    Carro *carro = new Carro();

    // preco,ano,marca,modelo,condicao,combustivel,odometro,status,cambio,tamanho,tipo,cor

       fscanf(veiculos_ofertas, "%d,%d,%s,%s,%s,%s,%s,%d,%s,%s,%s,%s",
         &carro->preco, &carro->ano, carro->marca, carro->modelo, carro->condicao, carro->combustivel, 
         carro->odometro, carro->status, carro->cambio, carro->tamanho, carro->tipo, carro->cor);
  }

