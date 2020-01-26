#include "dicionario.h"

void inicializa(TipoApontador *Dicionario)
{
  *Dicionario = NULL;
}

void insere(TipoRegistro x, TipoApontador *p)
{
  if (*p == NULL)
  {
    *p = (TipoApontador)malloc(sizeof(TipoNo));
    (*p)->reg = x;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (x.chave < (*p)->reg.chave)
  {
    insere(x, &(*p)->esq);
    return;
  }
  if (x.chave > (*p)->reg.chave)
    insere(x, &(*p)->dir);
  else
    printf("Erro:Registro já existe na árvore\n");
}

void antecessor(TipoApontador q, TipoApontador *r)
{
  if ((*r)->dir != NULL)
  {
    antecessor(q, &(*r)->dir);
    return;
  }
  q->reg = (*r)->reg;
  q = *r;
  *r = (*r)->esq;
  free(q);
}

void retira(TipoRegistro x, TipoApontador *p)
{
  TipoApontador aux;
  if (*p == NULL)
  {
    printf("Erro:Registro não está na arvore\n");
    return;
  }
  if (x.chave < (*p)->reg.chave)
  {
    retira(x, &(*p)->esq);
    return;
  }
  if (x.chave > (*p)->reg.chave)
  {
    retira(x, &(*p)->dir);
    return;
  }
  if ((*p)->dir == NULL)
  {
    aux = *p;
    *p = (*p)->esq;
    free(aux);
  }
  if ((*p)->esq != NULL)
  {
    antecessor(*p, &(*p)->esq);
    return;
  }
  aux = *p;
  *p = (*p)->dir;
  free(aux);
}

void central(TipoApontador p)
{
  if (p == NULL)
    return;
  central(p->esq);
  printf("%d\n", p->reg.chave);
  central(p->dir);
}

void pesquisa(TipoRegistro *x, TipoApontador *p)
{
  if (*p == NULL)
  {
    printf("Erro:Registro não está presente na árvore\n");
    return;
  }
  if (x->chave < (*p)->reg.chave)
  {
    pesquisa(x, &(*p)->esq);
    return;
  }
  if (x->chave > (*p)->reg.chave)
    pesquisa(x, &(*p)->dir);
  else
    *x = (*p)->reg;
}

void Arquivo(arquivo *arq)
{
  FILE *teste;
  int tamanho_vet, i = 0, cont = 0;
  char nome[30];
  int copia;
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
    int *aux = (int *)malloc(tamanho_vet * sizeof(int));
    if (aux == NULL)
    {
      printf("ERRO");
    }

    while (!feof(teste))
    {
      fscanf(teste, "%ld", &copia);
      aux[i] = copia;
      i++;
    }
    arq->itens_arquivo = aux;
    arq->quantidade_arquivo = tamanho_vet;
    fclose(teste);
    i--;
  }
}