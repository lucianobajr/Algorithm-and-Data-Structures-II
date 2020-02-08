#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define true 1
#define false 0

typedef int TipoChave;

typedef struct no
{
  TipoChave chave;
  struct no *primFilho;
  struct no *proxIrmao;
} NO;

typedef NO *Pont;

Pont criaNovoNo(TipoChave ch);
Pont inicializa(TipoChave ch);
bool insere(Pont raiz, TipoChave novaChave, TipoChave chavePai);
void exibirArvore(Pont raiz);
Pont buscaChave(TipoChave ch, Pont raiz);