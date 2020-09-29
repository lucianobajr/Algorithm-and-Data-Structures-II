#include "tst.h"

// cria Nó da TST
TSTNodePointer newNode(char data)
{
    TSTNode *temp = (struct TSTNode *)malloc(sizeof(TSTNode));
    temp->character = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}

// insere uma nova palavra na TST
void insert(TSTNodePointer *root, char *word)
{
    // Caso Base: Árvore está vazia
    if (!(*root))
        *root = newNode(*word);

    // Se o caractere atual da palavra for menor que o caractere da raiz,
    // insira esta palavra na subárvore esquerda da raiz
    if ((*word) < (*root)->character)
        insert(&((*root)->left), word);

    // Se o caractere atual da palavra for maior do que o caractere da raiz, 
    // então insira esta palavra na subárvore direita da raiz
    else if ((*word) > (*root)->character)
        insert(&((*root)->right), word);

    // Se o caractere atual da palavra for igual ao caractere da raiz,
    else
    {
        if (*(word + 1))
            insert(&((*root)->eq), word + 1);

        // último caractere da palavra
        else
            (*root)->isEndOfString = 1;
    }
}

// Percorre TST
void traverseTSTUtil(TSTNodePointer root, char *buffer, int depth)
{
    if (root)
    {
        // Primeira percorra a subárvore esquerda
        traverseTSTUtil(root->left, buffer, depth);

        // Armazene o caráter deste nó
        buffer[depth] = root->character;
        if (root->isEndOfString)
        {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
        }

        // Percorre subárvore do meio
        traverseTSTUtil(root->eq, buffer, depth + 1);

        // Finalmente, Percorre a subárvore direita
        traverseTSTUtil(root->right, buffer, depth);
    }
}

// Função principal pra percorrer TST
// Encapsula traverseTSTUtil()
void traverseTST(TSTNodePointer root)
{
    char buffer[MAX];
    traverseTSTUtil(root, buffer, 0);
}

// Função para pesquisar uma determinada palavra no TST
int searchTST(TSTNodePointer root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->character)
        return searchTST(root->left, word);

    else if (*word > (root)->character)
        return searchTST(root->right, word);

    else
    {
        if (*(word + 1) == '\0')
            return root->isEndOfString;

        return searchTST(root->eq, word + 1);
    }
}