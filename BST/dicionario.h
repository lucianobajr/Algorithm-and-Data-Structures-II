#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TipoRegistro
{
  int chave;
} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
  TipoRegistro reg;
  TipoApontador esq, dir;
} TipoNo;

typedef struct
{
  TipoRegistro *itens_arquivo;
  int quantidade_arquivo;
} arquivo;

typedef struct TipoCelula *TApontadorFila;

typedef int TipoChave;

typedef struct TipoCelula {
 TipoNo no;
  TApontadorFila Prox;
} TipoCelula;

typedef struct TipoFila {
  TApontadorFila Frente, Tras;
} TipoFila;

typedef TipoApontador TipoDicionario;

void inicializa(TipoApontador *Dicionario);
void insere(TipoRegistro x, TipoApontador *p);
void antecessor(TipoApontador q, TipoApontador *r);
void retira(TipoRegistro x, TipoApontador *p);
void ordem(TipoApontador p);
void preordem(TipoApontador p);
void posordem(TipoApontador p);
int altura(TipoApontador p);
void pesquisa(TipoRegistro *x, TipoApontador *p);
void Arquivo(arquivo *arq);
void print_menu();
void menu(arquivo *arq, TipoApontador Dicionario);

/*FILA*/
void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(TipoNo x, TipoFila *Fila);
void Desenfileira(TipoFila *Fila, TipoNo *Item);
void auxEnfileira(TipoApontador p ,TipoFila fila);
void Imprime(TipoFila Fila);