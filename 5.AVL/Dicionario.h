#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
// An AVL tree node 
typedef struct Node * TNode;
typedef struct Node{ 
    int key; 
    TNode left; 
    TNode right; 
    int height; 
}Node ; 


//Uma função utilitária para obter no máximo dois números inteiros
int max(int a, int b); 

//Função utilizada para obter a altura de uma árvore
int height(Node *N);

/* Função auxiliar que aloca um novo nó com a chave fornecida e NULL ponteiros esquerdo e direito. */
Node* newNode(int key);

// Uma função utilitária para girar à direita a subárvore enraizada em y
Node *rightRotate(Node *y);

// Uma função utilitária para girar à esquerda a subárvore enraizada em x
Node *leftRotate(Node *x);

// Fator de  Balanceamento do Nó N
int getBalance(Node *N);

  
/*Função recursiva para inserir uma chave na subárvore enraizada  com 
o nó e retorna a nova raiz da subárvore.*/
Node* insert(Node* node, int key);

/* Dada uma árvore de pesquisa binária não vazia, retorne o nó com o valor 
mínimo da chave encontrado nessa árvore. Observe que a árvore inteira não precisa ser
    procurou. */
Node * minValueNode(Node* node);

/* Função recursiva para excluir um nó com a chave fornecida da subárvore 
com raiz especificada. Retorna raiz de a subárvore modificada.*/
 Node* deleteNode(Node* root, int key);

//imprime de acordo com a ordem de inserção
void preOrder(Node *root);