#include "tree.h"

int main(int argc, char *argv[])
{ TipoRegistro x;
  TipoPagina *D;
  Inicializa(&D);
  printf("Chave: ");
  scanf("%ld%*[^\n]", &x.Chave);
  getchar();
  while (x.Chave != 0) 
    { Insere(x, &D);
      Imprime(D); printf("Chave: ");
      scanf("%ld%*[^\n]", &x.Chave);
      getchar();
    }
  Testa(D);
  printf("Chave: ");
  scanf("%ld%*[^\n]", &x.Chave);
  getchar();
  while (x.Chave != 0) 
    { Retira(x.Chave, &D);
      Imprime(D);
      printf("Chave: ");
      scanf("%ld%*[^\n]", &x.Chave);
      getchar();
    }
  Testa(D);
  return 0;
}