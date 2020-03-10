#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoRegistro
{
  char nome[10];  
  int matricula;
  int nota; 
} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
  TipoRegistro reg;
  TipoApontador esq, dir;
} TipoNo;

typedef struct TipoCelula *TApontadorFila;

typedef int TipoChave;

typedef struct TipoCelula {
 TipoNo no;
  TApontadorFila Prox;
} TipoCelula;

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
void Arquivo(TipoApontador *p);
void print_menu();
void menu(TipoApontador Dicionario);    
int countStudent(TipoApontador p,int *count);
int maiorNota(TipoApontador p); 
int menorNota(TipoApontador p);