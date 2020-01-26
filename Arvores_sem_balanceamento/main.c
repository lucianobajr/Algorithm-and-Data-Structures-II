#include "dicionario.h"

int main()
{
  TipoDicionario Dicionario;
  TipoRegistro x;
  arquivo *arq;
  inicializa(&Dicionario);
  scanf("%d", &x.chave);
  while (x.chave > 0)
  {
    insere(x, &Dicionario);
    scanf("%d", &x.chave);
  }
  central(Dicionario);
}