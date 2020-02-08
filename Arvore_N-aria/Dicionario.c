#include "Dicionario.h"

Pont criaNovoNo(TipoChave ch)
{
  Pont novo = (Pont)malloc(sizeof(NO));
  novo->primFilho = NULL;
  novo->proxIrmao = NULL;
  novo->chave = ch;
  return (novo);
}

Pont inicializa(TipoChave ch)
{
  return (criaNovoNo(ch));
}
bool insere(Pont raiz, TipoChave novaChave, TipoChave chavePai)
{
  Pont pai = buscaChave(chavePai, raiz);
  if (!pai)
    return (false);
  Pont filho = criaNovoNo(novaChave);
  Pont p = pai->primFilho;
  if (!p)
    pai->primFilho = filho;
  else
  {
    while (p->proxIrmao)
      p = p->proxIrmao;
    p->proxIrmao = filho;
  }
  return (true);
}

void exibirArvore(Pont raiz)
{
  if (raiz == NULL)
    return;
  printf("%d(", raiz->chave);
  Pont p = raiz->primFilho;
  while (p)
  {
    exibirArvore(p);
    p = p->proxIrmao;
  }
  printf(")");
}

Pont buscaChave(TipoChave ch, Pont raiz)
{
  if (raiz == NULL)
    return NULL;
  if (raiz->chave == ch)
    return raiz;
  Pont p = raiz->primFilho;
  while (p)
  {
    Pont resp = buscaChave(ch, p);
    if (resp)
      return (resp);
    p = p->proxIrmao;
  }
  return (NULL);
}
