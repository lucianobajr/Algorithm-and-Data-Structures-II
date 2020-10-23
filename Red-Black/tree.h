#include <stdio.h>
#include <stdlib.h>

//CLRS 
//Insertion and Deletion in a Red Black Tree
enum type {RED,BLACK};

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    enum type color;
};

struct Queue
{
    struct Node* data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear = NULL;

int isempty();
void dequeue();
struct Node* pfront();
void enqueue(struct Node* data);
void levelorder(struct Node* root);
void LeftRotate(struct Node** T,struct Node** x);
void RightRotate(struct Node** T,struct Node** x);
void RB_insert_fixup(struct Node** T, struct Node** z);
struct Node* RB_insert(struct Node* T,int data);
void preorder(struct Node* root);
struct Node* Tree_minimum(struct Node* node);
void RB_delete_fixup(struct Node** T, struct Node** x);
void RB_transplat(struct Node** T, struct Node** u,struct Node** v);
struct Node* RB_delete(struct Node *T,struct Node* z);
struct Node* BST_search(struct Node* root, int x);