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

typedef TipoApontador TipoDicionario;

void inicializa(TipoApontador *Dicionario);
void insere(TipoRegistro x, TipoApontador *p);
void antecessor(TipoApontador q, TipoApontador *r);
void retira(TipoRegistro x, TipoApontador *p);
void central(TipoApontador p);
void pesquisa(TipoRegistro *x, TipoApontador *p);
void Arquivo(arquivo *arq);
void print_menu();
void menu(arquivo *arq, TipoApontador Dicionario);