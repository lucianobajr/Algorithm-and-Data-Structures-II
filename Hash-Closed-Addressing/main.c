#include "hash.h"

int main(int argc, char *argv[])
{
  Inicializa(Tabela);
  GeraPesos(p);
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaa") != 0)
  {
    Insere(Elemento, p, Tabela);
    LerPalavra(Elemento.Chave, N);
  }
  printf("Tabela apos insercao:\n");
  Imprime(Tabela);
  printf("Pesquisar :  ");
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaa") != 0)
  {
    i = Pesquisa(Elemento.Chave, p, Tabela);
    if (i == NULL)
      printf("pesquisa sem sucesso \n");
    else
      printf("sucesso \n");
    printf("Pesquisar :  ");
    LerPalavra(Elemento.Chave, N);
  }
  printf("Retirar seguintes chaves:\n");
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaa") != 0)
  {
    Retira(Elemento, p, Tabela);
    LerPalavra(Elemento.Chave, N);
  }
  printf("Tabela apos retiradas:\n");
  Imprime(Tabela);
  printf("Inserir de novo os elementos seguintes:\n");
  LerPalavra(Elemento.Chave, N);
  while (strcmp(Elemento.Chave, "aaaaaa") != 0)
  {
    Insere(Elemento, p, Tabela);
    LerPalavra(Elemento.Chave, N);
  }
  printf("Tabela apos novas insxercoes:\n");
  Imprime(Tabela);
  return 0;
}
