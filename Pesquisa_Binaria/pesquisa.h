#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 11

typedef struct TipoRegistro
{
  long Chave;
  /* outros componentes */
} TipoRegistro;

typedef struct TipoTabela
{
  TipoRegistro Item[MAXN];
  int n;
} TipoTabela;

typedef struct
{
  TipoRegistro *itens_arquivo;
  int quantidade_arquivo;
} arquivo;
TipoTabela *Inicializa();
void Insere(arquivo *arq, TipoTabela *T);
int Binaria(long x, TipoTabela *T);
void Arquivo(arquivo *arq);
void menu(arquivo *arq, TipoTabela *T);
void Imprime(TipoTabela *T);
void print_menu();
void QuickSort(TipoTabela *T, int n);
void particao(int left, int right, int *i, int *j, TipoTabela *T);
void ordena(int left, int right, TipoTabela *T);