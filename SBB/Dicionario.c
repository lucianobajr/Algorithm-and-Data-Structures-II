#include "Dicionario.h"

void EE(TipoApontador *Ap)
{
  TipoApontador Ap1;
  Ap1 = (*Ap)->Esq;
  (*Ap)->Esq = Ap1->Dir;
  Ap1->Dir = *Ap;
  Ap1->BitE = Vertical;
  (*Ap)->BitE = Vertical;
  *Ap = Ap1;
}
void ED(TipoApontador *Ap)
{
  TipoApontador Ap1, Ap2;
  Ap1 = (*Ap)->Esq;
  Ap2 = Ap1->Dir;
  Ap1->BitD = Vertical;
  (*Ap)->BitE = Vertical;
  Ap1->Dir = Ap2->Esq;
  Ap2->Esq = Ap1;
  (*Ap)->Esq = Ap2->Dir;
  Ap2->Dir = *Ap;
  *Ap = Ap2;
}
void DD(TipoApontador *Ap)
{
  TipoApontador Ap1;
  Ap1 = (*Ap)->Dir;
  (*Ap)->Dir = Ap1->Esq;
  Ap1->Esq = *Ap;
  Ap1->BitD = Vertical;
  (*Ap)->BitD = Vertical;
  *Ap = Ap1;
}
void DE(TipoApontador *Ap)
{
  TipoApontador Ap1, Ap2;
  Ap1 = (*Ap)->Dir;
  Ap2 = Ap1->Esq;
  Ap1->BitE = Vertical;
  (*Ap)->BitD = Vertical;
  Ap1->Esq = Ap2->Dir;
  Ap2->Dir = Ap1;
  (*Ap)->Dir = Ap2->Esq;
  Ap2->Esq = *Ap;
  *Ap = Ap2;
}

void IInsere(TipoRegistro x, TipoApontador *Ap,
             TipoInclinacao *IAp, short *Fim)
{
  if (*Ap == NULL)
  {
    *Ap = (TipoApontador)malloc(sizeof(TipoNo));
    *IAp = Horizontal;
    (*Ap)->Reg = x;
    (*Ap)->BitE = Vertical;
    (*Ap)->BitD = Vertical;
    (*Ap)->Esq = NULL;
    (*Ap)->Dir = NULL;
    *Fim = FALSE;
    return;
  }
  if (x.Chave < (*Ap)->Reg.Chave){
    IInsere(x, &(*Ap)->Esq, &(*Ap)->BitE, Fim);
    if (*Fim)
      return;
    if ((*Ap)->BitE != Horizontal)
    {
      *Fim = TRUE;
      return;
    }
    if ((*Ap)->Esq->BitE == Horizontal)
    {
      EE(Ap);
      *IAp = Horizontal;
      return;
    }
    if ((*Ap)->Esq->BitD == Horizontal){
      ED(Ap);
      *IAp = Horizontal;
    }
    return;
  }
  if (x.Chave <= (*Ap)->Reg.Chave){
    printf("Erro: Chave ja esta na arvore\n");
    *Fim = TRUE;
    return;
  }
  IInsere(x, &(*Ap)->Dir, &(*Ap)->BitD, Fim);
  if (*Fim)
    return;
  if ((*Ap)->BitD == Vertical){
    *Fim = TRUE;
    return;
  }
  if ((*Ap)->Dir->BitD == Horizontal){
    DD(Ap);
    *IAp = Horizontal;
    return;
  }
  if ((*Ap)->Dir->BitE == Horizontal){
    DE(Ap);
    *IAp = Horizontal;
  }
}

void Insere(TipoRegistro x, TipoApontador *Ap)
{
  short Fim;
  TipoInclinacao IAp;
  IInsere(x, Ap, &IAp, &Fim);
}

void Inicializa(TipoApontador *Dicionario)
{
  *Dicionario = NULL;
}

void EsqCurto(TipoApontador *Ap, short *Fim)
{ /* Folha esquerda retirada => arvore curta na altura esquerda */
  TipoApontador Ap1;
  if ((*Ap)->BitE == Horizontal)
  {
    (*Ap)->BitE = Vertical;
    *Fim = TRUE;
    return;
  }
  if ((*Ap)->BitD == Horizontal)
  {
    Ap1 = (*Ap)->Dir;
    (*Ap)->Dir = Ap1->Esq;
    Ap1->Esq = *Ap;
    *Ap = Ap1;
    if ((*Ap)->Esq->Dir->BitE == Horizontal)
    {
      DE(&(*Ap)->Esq);
      (*Ap)->BitE = Horizontal;
    }
    else if ((*Ap)->Esq->Dir->BitD == Horizontal)
    {
      DD(&(*Ap)->Esq);
      (*Ap)->BitE = Horizontal;
    }
    *Fim = TRUE;
    return;
  }
  (*Ap)->BitD = Horizontal;
  if ((*Ap)->Dir->BitE == Horizontal)
  {
    DE(Ap);
    *Fim = TRUE;
    return;
  }
  if ((*Ap)->Dir->BitD == Horizontal)
  {
    DD(Ap);
    *Fim = TRUE;
  }
}

void DirCurto(TipoApontador *Ap, short *Fim)
{ /* Folha direita retirada => arvore curta na altura direita */
  TipoApontador Ap1;
  if ((*Ap)->BitD == Horizontal)
  {
    (*Ap)->BitD = Vertical;
    *Fim = TRUE;
    return;
  }
  if ((*Ap)->BitE == Horizontal)
  {
    Ap1 = (*Ap)->Esq;
    (*Ap)->Esq = Ap1->Dir;
    Ap1->Dir = *Ap;
    *Ap = Ap1;
    if ((*Ap)->Dir->Esq->BitD == Horizontal)
    {
      ED(&(*Ap)->Dir);
      (*Ap)->BitD = Horizontal;
    }
    else if ((*Ap)->Dir->Esq->BitE == Horizontal)
    {
      EE(&(*Ap)->Dir);
      (*Ap)->BitD = Horizontal;
    }
    *Fim = TRUE;
    return;
  }
  (*Ap)->BitE = Horizontal;
  if ((*Ap)->Esq->BitD == Horizontal)
  {
    ED(Ap);
    *Fim = TRUE;
    return;
  }
  if ((*Ap)->Esq->BitE == Horizontal)
  {
    EE(Ap);
    *Fim = TRUE;
  }
}

void Antecessor(TipoApontador q, TipoApontador *r, short *Fim)
{
  if ((*r)->Dir != NULL)
  {
    Antecessor(q, &(*r)->Dir, Fim);
    if (!*Fim)
      DirCurto(r, Fim);
    return;
  }
  q->Reg = (*r)->Reg;
  q = *r;
  *r = (*r)->Esq;
  free(q);
  if (*r != NULL)
    *Fim = TRUE;
}

void IRetira(TipoRegistro x, TipoApontador *Ap, short *Fim)
{
  TipoNo *Aux;
  if (*Ap == NULL)
  {
    printf("Chave nao esta na arvore\n");
    *Fim = TRUE;
    return;
  }
  if (x.Chave < (*Ap)->Reg.Chave)
  {
    IRetira(x, &(*Ap)->Esq, Fim);
    if (!*Fim)
      EsqCurto(Ap, Fim);
    return;
  }
  if (x.Chave > (*Ap)->Reg.Chave)
  {
    IRetira(x, &(*Ap)->Dir, Fim);
    if (!*Fim)
      DirCurto(Ap, Fim);
    return;
  }
  *Fim = FALSE;
  Aux = *Ap;
  if (Aux->Dir == NULL)
  {
    *Ap = Aux->Esq;
    free(Aux);
    if (*Ap != NULL)
      *Fim = TRUE;
    return;
  }
  if (Aux->Esq == NULL)
  {
    *Ap = Aux->Dir;
    free(Aux);
    if (*Ap != NULL)
      *Fim = TRUE;
    return;
  }
  Antecessor(Aux, &Aux->Esq, Fim);
  if (!*Fim)
    EsqCurto(Ap, Fim); /* Encontrou chave */
}

void Retira(TipoRegistro x, TipoApontador *Ap)
{
  short Fim;
  IRetira(x, Ap, &Fim);
}

void Pesquisa(TipoRegistro *x, TipoApontador *p)
{
  if (*p == NULL)
  {
    printf("Erro: Registro nao esta presente na arvore\n");
    return;
  }
  if (x->Chave < (*p)->Reg.Chave)
  {
    Pesquisa(x, &(*p)->Esq);
    return;
  }
  if (x->Chave > (*p)->Reg.Chave)
    Pesquisa(x, &(*p)->Dir);
  else
    *x = (*p)->Reg;
}

void Testa1(TipoApontador p, int nivel, int *NivelFolhas, short *PrimeiraFolha)
{
  if (p == NULL)
    return;
  if (*PrimeiraFolha)
    if (*NivelFolhas < nivel)
      *NivelFolhas = nivel;
  if (p->Esq == NULL && p->Dir == NULL)
  {
    if (*PrimeiraFolha == TRUE)
      *PrimeiraFolha = FALSE;
    else
    {
      if (nivel != *NivelFolhas)
      {
        printf("Erro: Folhas em niveis diferentes\n");
        exit(1);
      }
    }
  }
  if (p->BitE == Horizontal)
    Testa1(p->Esq, nivel, NivelFolhas, PrimeiraFolha);
  else
    Testa1(p->Esq, nivel + 1, NivelFolhas, PrimeiraFolha);
  if (p->BitD == Horizontal)
    Testa1(p->Dir, nivel, NivelFolhas, PrimeiraFolha);
  else
    Testa1(p->Dir, nivel + 1, NivelFolhas, PrimeiraFolha);
}

void Testa2(TipoApontador p, int *NivelFolhas, short *PrimeiraFolha)
{
  if (p == NULL)
    return;
  if (p->Esq != NULL)
  {
    if (p->Reg.Chave < p->Esq->Reg.Chave)
    {
      printf("Erro: %d < que filho a esquerda \n", p->Reg.Chave);
      exit(1);
    }
    Testa2(p->Esq, NivelFolhas, PrimeiraFolha);
  }
  if (p->Dir == NULL)
    return;
  if (p->Reg.Chave > p->Dir->Reg.Chave)
  {
    printf("Erro: %d > que filho a direita \n", p->Reg.Chave);
    exit(1);
  }
  Testa2(p->Dir, NivelFolhas, PrimeiraFolha);
}

void Testa(TipoApontador Arvore)
{
  int NivelFolhas = 0;
  short PrimeiraFolha = TRUE;
  Testa1(Arvore, 1, &NivelFolhas, &PrimeiraFolha);
  Testa2(Arvore, &NivelFolhas, &PrimeiraFolha);
}

double rand0a1()
{
  double resultado = (double)rand() / RAND_MAX; /* Dividir pelo maior inteiro */
  if (resultado > 1.0)
    resultado = 1.0;
  return resultado;
}

void Permut(int *A, int n)
{ /* Obtem permutacao randomica dos numeros entre 1 e n */
  int i, j, b;
  for (i = n; i >= 1; i--)
  {
    j = (int)(i * rand0a1() + 1);
    b = A[i - 1];
    A[i - 1] = A[j - 1];
    A[j - 1] = b;
  }
}

int altura(TipoApontador p){
    if(p == NULL){
      return -1;
    }
    else{
      int he = altura(p->Esq);
      int hd = altura(p->Dir);
      if(he < hd)
        return hd+1;
      else return he+1;  
    }
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
      fscanf(teste, "%d", &copia.Chave);
      aux[i].Chave = copia.Chave;
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
  Inicializa(&Dicionario);
  while (i != arq->quantidade_arquivo)
  {
    Insere(arq->itens_arquivo[i], &Dicionario);
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
      central(Dicionario);
      //central do TAD Dicionario
    }
    if (resposta == 4)
    {
      int height = altura(Dicionario);
      printf("\n ALTURA = %d\n",height);
      //central do TAD Dicionario
    }
    if (resposta == 2)
    {
      printf("Digite o  valor de registro que deseja procurar:");
      scanf("\n%d", &search.Chave);

      Pesquisa(&search, &Dicionario);
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

  printf(" (3) para imprimir os itens do TipoDicionario  (4) para Imprimir a Altura e Qualquer número diferente dos anteriores para fechar o programa.");
  for (i = 0; i < 5; i++)
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
void central(TipoApontador p)
{
  if (p == NULL)
    return;
  central(p->Esq);
  printf("%d\n", p->Reg.Chave);
  central(p->Dir);
}