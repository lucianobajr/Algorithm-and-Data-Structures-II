#include "dicionario.h"

/*------------------------------FILA-----------------------------------*/

void FFVazia(TipoFila *Fila)
{ Fila->Frente = (TApontadorFila) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
} 

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); } 

void Enfileira(TipoNo x, TipoFila *Fila)
{ Fila->Tras->Prox = (TApontadorFila) malloc(sizeof(TipoCelula));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->no = x;
  Fila->Tras->Prox = NULL;
} 

void Desenfileira(TipoFila *Fila, TipoNo *Item)
{ TApontadorFila q;
  if (Vazia(*Fila)) { printf("Erro fila esta vazia\n"); return; }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->no;
  free(q);
} 

void Imprime(TipoFila Fila)
{ TApontadorFila Aux;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL) 
    { ordem(&Aux->no);
      Aux = Aux->Prox;
    }
}

/*----------------------------END--FILA--------------------------------*/

void inicializa(TipoApontador *Dicionario)
{
  *Dicionario = NULL;//raiz da árvore
}

void insere(TipoRegistro x, TipoApontador *p)
{
  if (*p == NULL)//caso esteja vazio ensira na raiz
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

//percurso--transvercialização--ordem/infixa   (pré e pós)
void ordem(TipoApontador p)
{
  if (p != NULL){
    ordem(p->esq);
    printf("%d\n", p->reg.chave);
    ordem(p->dir);
  }
}


void preordem(TipoApontador p)
{
  if (p != NULL){
    printf("%d\n", p->reg.chave);
    preordem(p->esq);
    preordem(p->dir);
  }
}

void posordem(TipoApontador p)
{
  if (p != NULL){
    posordem(p->esq);
    posordem(p->dir);
    printf("%d\n", p->reg.chave);
  }
}

int altura(TipoApontador p){
    if(p == NULL){
      return -1;
    }
    else{
      int he = altura(p->esq);
      int hd = altura(p->dir);
      if(he < hd)
        return hd+1;
      else return he+1;  
    }
}

/*Algoritmo Busca por largura
  -função que recebe raiz e a fila como parâmetro --->certo
  -Declara nó auxiliar  --> certo
  -se nó != NULL então -->
    -Enfileira nó-->
    -enquanto fila !=  vazia
      -desinfileira nó e armazena no nó auxiliar 
      -imprime a chave do nó auxiliar
      -se nó auxiliar tem filho a esquerda != NULL então
        -enfileira filho a esquerda
      -se nó auxiliar tem filho direita ! = NULL
        -enfileira filho a direita
    -fim enquanto
  -fim se 
*/



void largura(TipoApontador p,TipoFila fila){
  TipoNo aux;
  FFVazia(&fila);
  if(p!=NULL){
    Enfileira(*p,&fila);
    while(!Vazia(fila)){
      Desenfileira(&fila,p);
      aux = *p;
      printf("%d\n",aux.reg.chave);
      if(aux.esq!=NULL){
        Enfileira(*aux.esq,&fila);
      }
      if(aux.dir!=NULL){
        Enfileira(*aux.dir,&fila);
      }
    }
  }
}

void pesquisa(TipoRegistro *x, TipoApontador *p)
{
  if (*p == NULL)
  {
    printf("Erro: Registro nao esta presente na arvore\n");
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
  TipoRegistro copia;
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
    TipoRegistro *aux = (TipoRegistro *)malloc(tamanho_vet * sizeof(TipoRegistro));
    if (aux == NULL)
    {
      printf("ERRO");
    }

    while (!feof(teste))
    {
      fscanf(teste, "%d", &copia.chave);
      aux[i].chave = copia.chave;
      i++;
    }
    arq->itens_arquivo = aux;
    arq->quantidade_arquivo = tamanho_vet;
    fclose(teste);
    i--;
  }
}

void menu(arquivo *arq, TipoApontador Dicionario)
{
  TipoRegistro search;
  int teste;
  int resposta, i = 0;
  Arquivo(arq);
  inicializa(&Dicionario);
  while (i != arq->quantidade_arquivo)
  {
    insere(arq->itens_arquivo[i], &Dicionario);
    i++;
  }
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
      TipoFila fila;
      largura(Dicionario,fila);
      //central do TAD Dicionario
    }
    if (resposta == 2)
    {
      printf("Digite o  valor de registro que deseja procurar:");
      scanf("\n%d", &search.chave);

      pesquisa(&search, &Dicionario);
      //busca do TAD Dicionario
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
  printf("Digite (1) Inserir os itens no TipoDicionario (2) para fazer a busca de um item no Árvore");
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

  printf(" (3) para imprimir os itens do TipoDicionario e Qualquer número diferente dos anteriores para fechar o programa.");
  for (i = 0; i < 33; i++)
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