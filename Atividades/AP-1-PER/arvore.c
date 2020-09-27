#include "arvore.h"

/*---------------------OPERAÇÕES BÁSICAS---------------------*/
void inicializa(TipoApontador *Dicionario)
{
  *Dicionario = NULL; //raiz da árvore
}

void insere(TipoRegistro x, TipoApontador *p)
{
  if (*p == NULL) //caso esteja vazio ensira na raiz
  {
    *p = (TipoApontador)malloc(sizeof(TipoNo));
    (*p)->reg = x;
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (x.nota <= (*p)->reg.nota)
  {
    insere(x, &(*p)->esq);
    return;
  }
  if (x.nota >= (*p)->reg.nota)
  {
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

void preordem(TipoApontador p)
{
  if (p != NULL)
  {
    printf("%d\n", p->reg.nota);
    preordem(p->esq);
    preordem(p->dir);
  }
}

void posordem(TipoApontador p)
{
  if (p != NULL)
  {
    posordem(p->esq);
    posordem(p->dir);
    printf("%d\n", p->reg.nota);
  }
}

int altura(TipoApontador p)
{
  if (p == NULL)
  {
    return -1;
  }
  else
  {
    int he = altura(p->esq);
    int hd = altura(p->dir);
    if (he < hd)
      return hd + 1;
    else
      return he + 1;
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
/*---------------------FIM OPERAÇÕES---------------------*/

/*---------------------FUNÇÕES PEDIDAS---------------------*/
void ordem(TipoApontador p) //ordem decrescente
{
  if (p != NULL)
  {
    ordem(p->dir);
    printf("%s - %d - %s - %d\n", p->reg.nome, p->reg.matricula, p->reg.grupo, p->reg.nota);
    ordem(p->esq);
  }
}

int countStudent(TipoApontador p, int *count)
{
  if (p != NULL)
  {
    countStudent(p->esq, count);
    (*count)++;
    countStudent(p->dir, count);
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

int menorNota(TipoApontador p)
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

void countMediaProva(int *media, TipoApontador p)
{
  if (p != NULL)
  {
    countMediaProva(media, p->esq);
    if (p->reg.nota == MEDIA_PROVA)
    {
      (*media)++;
    }
    countMediaProva(media, p->dir);
  }
}

void agroup()
{
  char nome1[6] = "Grupo1";
  char nome2[6] = "Grupo2";
  if (nome1[5] > nome2[5])
    printf("1>>>>>>>\n");
  else
    printf("2>>>>>>>\n");
}

void inicializaGrupo(TipoApontadorGrupo *Dicionario)
{
  *Dicionario = NULL; //raiz da árvore
}

void insereGrupo(int *nota, char *nome, TipoApontadorGrupo *p)
{
  if (*p == NULL) //caso esteja vazio ensira na raiz
  {
    *p = (TipoApontadorGrupo)malloc(sizeof(TipoNoGrupo));
    (*p)->reg.nota = *nota;
    (*p)->reg.nome[0] = nome[0];
    (*p)->reg.nome[1] = nome[1];
    (*p)->reg.nome[2] = nome[2];
    (*p)->reg.nome[3] = nome[3];
    (*p)->reg.nome[4] = nome[4];
    (*p)->reg.nome[5] = nome[5];
    (*p)->esq = NULL;
    (*p)->dir = NULL;
    return;
  }
  if (nome[5] == (*p)->reg.nome[5])
  {
    (*p)->reg.nota = (*p)->reg.nota + *nota;
  }
  if (nome[5] < (*p)->reg.nome[5])
  {
    insereGrupo(nota, nome,&(*p)->esq);
    return;
  }
  if (nome[5] > (*p)->reg.nome[5])
  {
    insereGrupo(nota, nome, &(*p)->dir);
    return;
  }
}

void ordemGrupo(TipoApontadorGrupo g) //ordem decrescente
{

  if (g != NULL)
  {
    ordemGrupo(g->dir);
    printf("%s - %d\n", g->reg.nome, g->reg.nota);
    ordemGrupo(g->esq);
  }
}

/*-------------------FIM FUNÇÕES PEDIDAS---------------------*/

void Arquivo(TipoApontador *p, TipoApontadorGrupo *g)
{
  FILE *teste;
  char nome[30];
  TipoRegistro copia;
  TipoRegistroGrupo copiaGrupo;
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
      fscanf(teste, "%s - %d - %s - %d", copia.nome, &copia.matricula, copia.grupo, &copia.nota);

      insere(copia, p);
      insereGrupo(&copia.nota, copia.grupo,g);
    }
    fclose(teste);
  }
}

void menu(TipoApontador Dicionario, TipoApontadorGrupo DicionarioGrupo)
{
  TipoRegistro search;
  int teste;
  int resposta;
  inicializa(&Dicionario);
  inicializaGrupo(&DicionarioGrupo);
  Arquivo(&Dicionario, &DicionarioGrupo);
  do
  {
    print_menu();
    scanf("%d", &resposta);
    if (resposta == 1)
    {
      ordem(Dicionario);
    }
    if (resposta == 2)
    {
      int count = 0;
      countStudent(Dicionario, &count);
      printf("\n%d alunos matriculados\n\n\n", count);
    }
    if (resposta == 3)
    {
      printf("\n A menor nota obtida foi: %d\n", menorNota(Dicionario));
    }
    if (resposta == 4)
    {
      printf("\n A maior nota obtida foi: %d\n", maiorNota(Dicionario));
    }
    if (resposta == 5)
    {
      int media = 0;
      countMediaProva(&media, Dicionario);
      printf("\n O número de alunos que obtiveram média na prova foi: %d\n", media);
    }
    if (resposta == 6)
    {

      ordemGrupo(DicionarioGrupo);
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
  for (i = 0; i < 26; i++)
  {
    fputs(" ", stdout);
  }
  printf("Digite (1) Exibir os alunos matriculados (2) para exibir o número de alunos da disciplina");
  for (i = 0; i < 37; i++)
  {
    fputs(" ", stdout);
  }
  printf("|");
  printf("\n|           ");
  for (i = 0; i < 32; i++)
  {
    fputs(" ", stdout);
  }

  for (i = 0; i < 120; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n");

  printf("|");

  for (i = 0; i < 43; i++)
  {
    fputs(" ", stdout);
  }

  printf(" (3) para Exibir a menor nota obtida  (4) para exibir a maior nota obtida");
  for (i = 0; i < 47; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n");

  printf("|");

  for (i = 0; i < 163; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n");

  printf("|");

  for (i = 0; i < 33; i++)
  {
    fputs(" ", stdout);
  }
  printf("(5) para Exibir o número de alunos com média na prova (6) Grupo com maiores notas e ");
  for (i = 0; i < 46; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n");

  printf("|");
  for (i = 0; i < 163; i++)
  {
    fputs(" ", stdout);
  }
  printf("|\n");

  printf("|");
  for (i = 0; i < 50; i++)
  {
    fputs(" ", stdout);
  }
  printf("Qualquer número diferente dos anteriores para fechar o programa.");
  for (i = 0; i < 49; i++)
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