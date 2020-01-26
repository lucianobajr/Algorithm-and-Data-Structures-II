#include "pesquisa.h"
TipoTabela *Inicializa()
{
  TipoTabela *T = (TipoTabela *)malloc(sizeof(TipoTabela));
  T->n = 0;
  return T;
}

void Insere(arquivo *arq, TipoTabela *T)
{
  for (int i = 0; i < arq->quantidade_arquivo; i++)
  {
    T->Item[i].Chave = arq->itens_arquivo[i].Chave;
    T->n++;
  }
}

void QuickSort(TipoTabela *T, int n)
{
  ordena(0, n - 1, T);
}

void ordena(int left, int right, TipoTabela *T)
{
  int i, j;
  particao(left, right, &i, &j, T);

  if (left < j)
    ordena(left, j, T);

  if (i < right)
    ordena(i, right, T);
}

void particao(int left, int right, int *i, int *j, TipoTabela *T)
{
  *i = left;
  *j = right;
  TipoRegistro pivot = T->Item[(*i + *j) / 2];
  TipoRegistro aux;
  do
  {

    while (pivot.Chave > T->Item[*i].Chave)
    {
      (*i)++;
    }
    while (pivot.Chave < T->Item[*j].Chave)
    {
      (*j)--;
    }

    if (*i <= *j)
    {

      aux = T->Item[*i];
      T->Item[*i] = T->Item[*j];
      T->Item[*j] = aux;
      (*i)++;
      (*j)--;
    }
  } while (*i <= *j);
}

int Binaria(long x, TipoTabela *T)
{
  int i, Esq, Dir;
  if (T->n == 0)
    return 0;
  else
  {
    Esq = 1;
    Dir = T->n;
    do
    {
      i = (Esq + Dir) / 2;
      if (x > T->Item[i].Chave)
        Esq = i + 1;
      else
        Dir = i - 1;
    } while (x != T->Item[i].Chave && Esq <= Dir);
    if (x == T->Item[i].Chave)
      return i;
    else
      return 0;
  }
}

void Imprime(TipoTabela *T)
{
  int i;
  for (i = 0; i < T->n; i++)
  {
    printf("%ld\n", T->Item[i].Chave);
  }
}
void Arquivo(arquivo *arq)
{
  FILE *teste;
  int tamanho_vet, i = 0, cont = 0;
  char nome[30];
  TipoTabela copia;
  printf("Digite o nome do arquivo para o caso de teste (Na mesma pasta e com .txt) = ");
  fgets(nome, 30, stdin);
  nome[strlen(nome) - 1] = '\0';
  teste = fopen(nome, "r");
  if (teste == NULL)
  {
    printf("dando erro");
  }
  else
  {
    fscanf(teste, "%d", &tamanho_vet);
    TipoTabela *aux = (TipoTabela *)malloc(tamanho_vet * sizeof(TipoTabela));
    if (aux == NULL)
    {
      printf("ERRO");
    }

    while (!feof(teste))
    {
      fscanf(teste, "%ld", &copia.Item[i].Chave);
      aux->Item[i].Chave = copia.Item[i].Chave;
      i++;
    }
    arq->itens_arquivo = aux->Item;
    arq->quantidade_arquivo = tamanho_vet;
    fclose(teste);
    i--;
  }
}

void menu(arquivo *arq, TipoTabela *T)
{
  int resposta;
  Arquivo(arq);
  do
  {
    print_menu();
    scanf("%d", &resposta);
    if (resposta == 1)
    {

      T = Inicializa();
      Insere(arq, T);
      QuickSort(T, T->n);
    }
    if (resposta == 3)
    {
      Imprime(T);
    }
    if (resposta == 2)
    {
      int busca;
      printf("Digite o valor que deseja procurar:");
      scanf("%d", &busca);
      printf("\n O item se encontrar na posição %d do Array\n", Binaria(busca, T));
    }
  } while (resposta != 0);
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
  printf("Digite (1) Inserir os itens no TipoTabela (2) para fazer a busca de um item no array");
  for (i = 0; i < 47; i++)
  {
    fputs(" ", stdout);
  }
  printf("|");
  printf("\n|           ");
  for (i = 0; i < 7; i++)
  {
    fputs(" ", stdout);
  }

  printf(" (3) para imprimir os itens do TipoTabela e Qualquer número diferente dos anteriores para fechar o programa.");
  for (i = 0; i < 37; i++)
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