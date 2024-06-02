#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000

typedef struct Node
{
  int data;
  int lchild;
  int rchild;
} Node;

typedef Node *bst;

// Implementing Implicit Indexing
// LC = 2i+1;
// RC = 2i-1;

void init_bst(bst *t);
void insert_bst(bst *t, int data);

void non_rec_inorder(bst *t);
void non_rec_preorder(bst *t);
void non_rec_postorder(bst *t);

void level_wise(bst *t);

int isComplete(bst *t);

// Queue implementation for level order traversal
typedef struct Queue
{
  int size;
  int front;
  int rear;
  int *indices;
} Queue;

void init_q(Queue *q, int size);
int isqFull(Queue *q);
int isqEmpty(Queue *q);
void enqueue(Queue *q, int index);
int dequeue(Queue *q);

// Stack implementation for non recursive traversals
typedef struct Stack
{
  int size;
  int top;
  int *indices;
} Stack;

void init_stack(Stack *s, int size);
int isstackEmpty(Stack *s);
int isstackFull(Stack *s);
void push(Stack *s, int index);
int pop(Stack *s);
