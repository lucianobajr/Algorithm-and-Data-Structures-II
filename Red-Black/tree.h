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

struct Node* pfront()
{
    struct Node* data ;
    data = front->data;
    return data;
}
