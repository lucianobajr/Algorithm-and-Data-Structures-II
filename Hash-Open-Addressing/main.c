#include "hash.h"

int main()
{
  int i = 0;
  Inicializa(Tabela);

  GeraPesos(p);
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  {
    Insere(Elemento, p, Tabela);
    LerPalavra(Elemento.Chave, N);
  }

  printf("Tabela apos insercao:\n");
  Imprime(Tabela);

  printf("Pesquisar :  ");
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  {
    i = Pesquisa(Elemento.Chave, p, Tabela);
    if (i < M)
      printf("sucesso na posicao %d \n", i);
    else
      printf("pesquisa sem sucesso \n");
    printf("Pesquisar :  ");
    LerPalavra(Elemento.Chave, N);
  }

  printf("Retirar seguintes chaves:\n");
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  {
    Retira(Elemento.Chave, p, Tabela);
    LerPalavra(Elemento.Chave, N);
  }

  printf("Tabela apos retiradas:\n");
  Imprime(Tabela);

  printf("Inserir de novo os elementos seguintes:\n");
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  {
    Insere(Elemento, p, Tabela);
    LerPalavra(Elemento.Chave, N);
  }

  printf("Tabela apos novas insercoes:\n");
  Imprime(Tabela);
  return 0;
}