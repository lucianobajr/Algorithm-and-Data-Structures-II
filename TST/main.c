#include "tst.h"

int main()
{
    TSTNode *root = NULL;

    insert(&root, "JavaScript");
    insert(&root, "ReactJs");
    insert(&root, "NodeJs");
    insert(&root, "Flutter");

    printf("Bora Percorrer a TST\n");
    traverseTST(root);

    printf("\nResultados da Pesquisa por Tecnologias\n");
    searchTST(root, "ReactJs") ? printf("Encontrado\n") : printf("Não Encontrado\n");
    searchTST(root, "NodeJs") ? printf("Encontrado\n") : printf("Não Encontrado\n");
    searchTST(root, "Flutter") ? printf("Encontrado\n") : printf("Não Encontrado\n");

    return 0;
}