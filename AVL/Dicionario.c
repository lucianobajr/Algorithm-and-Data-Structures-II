#include "Dicionario.h"
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node *newNode(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // novo nó é adicionado inicialmente na folha
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key)
{
    /* 1. Execute a inserção normal de BST */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Chaves iguais não são permitidas no BST
        return node;

    /* 2. Atualize a altura desse nó ancestral */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Obtenha o fator de equilíbrio deste nó ancestral para verificar se este nó se tornou desequilibrado */
    int balance = getBalance(node);

    // Se este nó ficar desequilibrado, então
    //existem 4 casos
    // Caixa esquerda esquerda
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Caso Direita direita
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Caso esquerda direita
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso direita esquerda
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* retornar o ponteiro do nó (inalterado) */
    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    /* encontra raiz mais a esquerda */
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int key)
{
    //ETAPA 1: EXECUTAR  PADRÃO BST  DE EXCLUIR

    if (root == NULL)
        return root;

    // Se a chave a ser excluída for menor que a
    // chave da raiz, então ela fica na subárvore esquerda
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // Se a chave a ser excluída for maior que a
    // chave da raiz, então ela fica na subárvore direita
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // // se a chave for igual à chave da raiz, então
    // este é o nó a ser excluído
    else
    {
        // nós com somente um filho ou sem filhos
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            // Caso sem filhos
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else               // caso de um filho
                *root = *temp; //Copia o conteudo
                               // do filho nao vazio
            free(temp);
        }
        else
        {
            // Nó com dois filhos: em ordem
            // sucessor
            Node *temp = minValueNode(root->right);

            // CCopie os dados do sucessor da ordem de entrada neste nó
            root->key = temp->key;

            // Excluir o sucessor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // se a arvore tem apenas um nó então retorna
    if (root == NULL)
        return root;

    // PASSO 2: ATUALIZAÇÃO DA ALTURA DO NÓ ATUAL
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // ETAPA 3: OBTENHA O FATOR DE EQUILÍBRIO DESTE NÓ
    // verifique se este nó ficou desequilibrado)
    int balance = getBalance(root);

    // Se esse nó ficar desequilibrado, haverá 4 casos

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}