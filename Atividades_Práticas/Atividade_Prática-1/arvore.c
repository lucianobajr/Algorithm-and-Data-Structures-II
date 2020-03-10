#include "arvore.h"

void inicializa(TipoApontador *Dicionario)
{
  *Dicionario = NULL;//raiz da árvore
}

void insere(TipoRegistro x, TipoApontador *p)
{ if (*p == NULL)//caso esteja vazio ensira na raiz
  {
    *p = (TipoApontador)malloc(sizeof(TipoNo));
    (*p)->reg = x;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (x.nota < (*p)->reg.nota)
  { insere(x, &(*p)->esq);
    return;
  }
  if (x.nota > (*p)->reg.nota){
      insere(x, &(*p)->dir);
      return;
  } 
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
  if (x.nota < (*p)->reg.nota)
  {
    retira(x, &(*p)->esq);
    return;
  }
  if (x.nota > (*p)->reg.nota)
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

int countStudent(TipoApontador p,int *count){
  if (p != NULL){
    countStudent(p->esq,count);
    (*count)++;
    countStudent(p->dir,count);
  }
}

int maiorNota(TipoApontador p) 
{ 
    if (p == NULL) 
      return 0; 

    int maior = p->reg.nota; 
    int eres = maiorNota(p->esq); 
    int dres = maiorNota(p->dir); 
    if (eres > maior) 
      maior = eres; 
    if (dres > maior) 
      maior = dres; 
    return maior; 
} 

int menorNota(TipoApontador p ) 
{ 
    if (p == NULL) 
      return 20; 
  
    int menor = p->reg.nota; 
    int lres = menorNota(p->esq); 
    int rres = menorNota(p->dir); 
    if (lres < menor) 
      menor = lres; 
    if (rres < menor) 
      menor = rres; 
    return menor; 
} 

//percurso--transvercialização--ordem/infixa   (pré e pós)
void ordem(TipoApontador p)//ordem decrescente
{
  if (p != NULL){
    ordem(p->dir);
    printf("%s - %d - %d\n",p->reg.nome, p->reg.matricula,p->reg.nota);
    ordem(p->esq);
  }
}


void preordem(TipoApontador p)
{
  if (p != NULL){
    printf("%d\n", p->reg.nota);
    preordem(p->esq);
    preordem(p->dir);
  }
}

void posordem(TipoApontador p)
{
  if (p != NULL){
    posordem(p->esq);
    posordem(p->dir);
    printf("%d\n", p->reg.nota);
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

void pesquisa(TipoRegistro *x, TipoApontador *p)
{
  if (*p == NULL)
  {
    printf("Erro: Registro nao esta presente na arvore\n");
    return;
  }
  if (x->nota < (*p)->reg.nota)
  {
    pesquisa(x, &(*p)->esq);
    return;
  }
  if (x->nota > (*p)->reg.nota)
    pesquisa(x, &(*p)->dir);
  else
    *x = (*p)->reg;
}

void Arquivo(TipoApontador *p)
{
  FILE *teste;
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
    while (!feof(teste))
    {
      fscanf(teste,"%s - %d - %d",copia.nome,&copia.matricula,&copia.nota);
      insere(copia,p); 
    }
    fclose(teste);
  }
}

void menu(TipoApontador Dicionario)
{
  TipoRegistro search;
  int teste;
  int resposta, i = 0;
  inicializa(&Dicionario);
  Arquivo(&Dicionario);
  do
  {
    print_menu();
    scanf("%d", &resposta);
    if (resposta == 1)
    {
      printf("%d",menorNota(Dicionario));
      //operações de dicionario
    }
    if (resposta == 3)
    {
        int count =0;
        ordem(Dicionario);
        countStudent(Dicionario,&count);
        printf("%d alunos matriculados\n",count);
      //central do TAD Dicionario
    }
    if (resposta == 2)
    {
      printf("Digite o  valor de registro que deseja procurar:");
      scanf("\n%d", &search.nota);

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