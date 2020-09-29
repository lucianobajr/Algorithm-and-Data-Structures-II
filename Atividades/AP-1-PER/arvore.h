#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEDIA_PROVA 5

typedef struct TipoRegistro
{
  char nome[10];  
  int matricula;
  char grupo[20];
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


typedef struct TipoRegistroGrupo
{
  char nome[10];  
  int nota; 
} TipoRegistroGrupo;

typedef struct TipoNoGrupo *TipoApontadorGrupo;

typedef struct TipoNoGrupo
{
  TipoRegistroGrupo reg;
  TipoApontadorGrupo esq, dir;
} TipoNoGrupo;


typedef TipoApontadorGrupo TipoDicionarioGrupo;

void inicializaGrupo(TipoApontadorGrupo *Dicionario);
void insereGrupo(int *nota, char *nome, TipoApontadorGrupo *p);


void inicializa(TipoApontador *Dicionario);
void insere(TipoRegistro x, TipoApontador *p);
void antecessor(TipoApontador q, TipoApontador *r);
void retira(TipoRegistro x, TipoApontador *p);
void ordem(TipoApontador p);
void preordem(TipoApontador p);
void posordem(TipoApontador p);
int altura(TipoApontador p);
void pesquisa(TipoRegistro *x, TipoApontador *p);
void Arquivo(TipoApontador *p,TipoApontadorGrupo *g);
void print_menu();
void menu(TipoApontador Dicionario,TipoApontadorGrupo DicionarioGrupo);    
int countStudent(TipoApontador p,int *count);
int maiorNota(TipoApontador p); 
int menorNota(TipoApontador p);
void countMediaProva(int *media,TipoApontador p);
void ordemGrupo(TipoApontadorGrupo g);