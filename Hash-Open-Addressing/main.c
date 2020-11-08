#include "hash.h"

void main()
{
  int resposta, i = 0;
  do
  {
    print_menu();
    scanf("%d", &resposta);
    if (resposta == 1)
    {
      continue;
      //operações de dicionario
    }
    if (resposta == 3)
    {
      
      //central do TAD Dicionario
    }
    if (resposta == 4)
    {
     
    
      //central do TAD Dicionario
    }
    if (resposta == 2)
    {
      printf("Digite o  valor de registro que deseja procurar:");
     

      
      //busca do TAD Dicionario
    }
  } while (resposta != 0);
  // int i = 0;
  // Inicializa(Tabela);

  // GeraPesos(p);
  // LerPalavra(Elemento.Chave, N);
  // while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  // {
  //   Insere(Elemento, p, Tabela);
  //   LerPalavra(Elemento.Chave, N);
  // }

  // printf("Tabela apos insercao:\n");
  // Imprime(Tabela);

  // printf("Pesquisar :  ");
  // LerPalavra(Elemento.Chave, N);
  // while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  // {
  //   i = Pesquisa(Elemento.Chave, p, Tabela);
  //   if (i < M)
  //     printf("sucesso na posicao %d \n", i);
  //   else
  //     printf("pesquisa sem sucesso \n");
  //   printf("Pesquisar :  ");
  //   LerPalavra(Elemento.Chave, N);
  // }

  // printf("Retirar seguintes chaves:\n");
  // LerPalavra(Elemento.Chave, N);
  // while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  // {
  //   Retira(Elemento.Chave, p, Tabela);
  //   LerPalavra(Elemento.Chave, N);
  // }

  // printf("Tabela apos retiradas:\n");
  // Imprime(Tabela);

  // printf("Inserir de novo os elementos seguintes:\n");
  // LerPalavra(Elemento.Chave, N);
  // while (strcmp(Elemento.Chave, "aaaaaaaaaa") != 0)
  // {
  //   Insere(Elemento, p, Tabela);
  //   LerPalavra(Elemento.Chave, N);
  // }

  // printf("Tabela apos novas insercoes:\n");
  // Imprime(Tabela);
}

void print_menu()
{
  int i;
  fputs(" ", stdout);
  for (i = 0; i < 163; i++)
  {
    fputs("_", stdout);
  }
  printf("\n|");
  for (i = 0; i < 163; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n|");
  for (i = 0; i < 80; i++)
  {
    fputs(" ", stdout);
  }
  printf("MENU");
  for (i = 0; i < 79; i++)
  {
    fputs(" ", stdout);
  }
  printf("|");
  printf("\n");
  printf("|");
  for (i = 0; i < 163; i++)
  {
    fputs("_", stdout);
  }
  printf("|\n|");
  for (i = 0; i < 163; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n|           ");
  for (i = 0; i < 21; i++)
  {
    fputs(" ", stdout);
  }
  printf("Digite (1) Inserir Palavra (2) para fazer a busca de um item no Árvore");
  for (i = 0; i < 42; i++)
  {
    fputs(" ", stdout);
  }
  printf("|");
  printf("\n|           ");
  for (i = 0; i < 7; i++)
  {
    fputs(" ", stdout);
  }

  printf(" (3) para imprimir os itens do TipoDicionario  (4) para Imprimir a Altura e Qualquer número diferente dos anteriores para fechar o programa.");
  for (i = 0; i < 5; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n");

  printf("|");
  for (i = 0; i < 163; i++)
  {
    fputs("_", stdout);
  }
  printf("|");
  printf("\n");
  printf("------------->");
  fflush(stdin);
}