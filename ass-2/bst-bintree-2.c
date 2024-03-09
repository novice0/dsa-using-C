#include "bst-bintree-2.h"

void init_bst(bst *t)
{
  *t = (Node *)malloc(MAX * sizeof(Node));
  Node *p;
  p = *t;
  for (int i = 0; i < MAX; i++)
  {
    p[i].data = 0;
    (p[i]).lchild = -1;
    (p[i]).rchild = -1;
  }
  return;
}

void insert_bst(bst *t, int data)
{
  Node *p = *t;
  int i = 0;
  while (p[i].data != 0 || p[i].rchild != -1 || p[i].lchild != -1)
  {
    if (p[i].data > data)
    {
      p[i].lchild = (2 * i) + 1;
      i = (2 * i) + 1;
    }
    else if (p[i].data < data)
    {
      p[i].rchild = (2 * i) + 2;
      i = (2 * i) + 2;
    }
    else
    {
      printf("Duplications Not Allowed\n");
      return;
    }
  }
  p[i].data = data;
  return;
}

void non_rec_inorder(bst *t)
{
  Stack s;
  init_stack(&s, 50);
  int i = 0;
  Node *p = *t;
  printf("\nNon-Recursive Inorder Traversal\n");
  while (p[i].data != 0 || p[i].lchild != -1 || p[i].rchild != -1 || !isstackEmpty(&s))
  {
    if (p[i].data != 0 || p[i].lchild != -1 || p[i].rchild != -1)
    {
      push(&s, i);
      i = (2 * i) + 1;
    }
    else
    {
      i = pop(&s);
      printf("%d\n", p[i].data);
      i = (2 * i) + 2;
    }
  }
}

void non_rec_preorder(bst *t)
{
  Stack s;
  init_stack(&s, 50);
  int i = 0;
  Node *p = *t;
  printf("\nNon-Recursive Preorder Traversal\n");
  while (p[i].data != 0 || p[i].lchild != -1 || p[i].rchild != -1 || !isstackEmpty(&s))
  {
    if (p[i].data != 0 || p[i].lchild != -1 || p[i].rchild != -1)
    {
      printf("%d\n", p[i].data);
      push(&s, i);
      i = (2 * i) + 1;
    }
    else
    {
      i = pop(&s);
      i = (2 * i) + 2;
    }
  }
}

void non_rec_postorder(bst *t)
{
  Stack s;
  init_stack(&s, 50);
  int temp;
  int count0 = 0;
  int i = 0;
  Node *p = *t;
  printf("\nNon-Recursive Postorder Traversal\n");
  while (p[i].data != 0 || p[i].lchild != -1 || p[i].rchild != -1 || !isstackEmpty(&s))
  {
    if (p[i].data != 0 || p[i].lchild != -1 || p[i].rchild != -1)
    {
      push(&s, i);
      i = (2 * i) + 1;
    }
    else
    {
      temp = pop(&s);
      if (temp > 0)
      {
        push(&s, -temp);
        i = (2 * temp) + 2;
      }
      else
      {
        if (temp == 0 && count0 == 0)
        {
          push(&s, temp);
          i = 2;
          count0++;
        }
        else
        {
          printf("%d\n", p[-temp].data);
        }
      }
    }
  }
}

void level_wise(bst *t)
{
  Node *p = *t;
  Queue q;
  init_q(&q, 50);
  int i = 0;
  int li, ri;
  printf("\nLevel Order Traversal\n");
  printf("%d\n", p[i].data);
  enqueue(&q, i);
  while (!isqEmpty(&q))
  {
    i = dequeue(&q);
    li = (2 * i) + 1;
    ri = (2 * i) + 2;
    if (p[li].data != 0 || p[li].lchild != -1 || p[li].rchild != -1)
    {
      printf("%d\n", p[li].data);
      enqueue(&q, li);
    }
    if (p[ri].data != 0 || p[ri].lchild != -1 || p[ri].rchild != -1)
    {
      printf("%d\n", p[ri].data);
      enqueue(&q, ri);
    }
  }
}

int isComplete(bst *t)
{
  Node *p = *t;
  for (int i = 0; i < MAX; i++)
  {
    if (p[i].data != 0 && ((p[i].lchild != -1 && p[i].rchild == -1) || (p[i].rchild != -1 && p[i].lchild == -1)))
    {
      return 0;
    }
  }
  return 1;
}

int farthestLeaf(bst *t)
{
  int i = 0;
  int x, y;
  if ((*t)[i].data != -1)
  {
    x = farthestLeaf((*t)[i].lchild);
    y = farthestLeaf((*t)[i].rchild);
  }
} // to complete this function later

void init_q(Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->indices = (int *)malloc(q->size * sizeof(int));
}

int isqFull(Queue *q)
{
  return (q->rear == q->size - 1);
}

int isqEmpty(Queue *q)
{
  return (q->front == q->rear);
}

void enqueue(Queue *q, int index)
{
  if (isqFull(q))
    return;
  q->indices[q->rear++] = index;
  return;
}

int dequeue(Queue *q)
{
  if (isqEmpty(q))
    return -1;
  int temp = q->indices[q->front];
  q->front++;
  return temp;
}

void init_stack(Stack *s, int size)
{
  s->size = size;
  s->top = -1;
  s->indices = (int *)malloc(s->size * sizeof(int));
}

int isstackEmpty(Stack *s)
{
  return (s->top == -1);
}

int isstackFull(Stack *s)
{
  return (s->top == s->size - 1);
}

void push(Stack *s, int index)
{
  if (isstackFull(s))
  {
    printf("Stack Overflow\n");
    return;
  }
  s->top++;
  s->indices[s->top] = index;
  return;
}

int pop(Stack *s)
{
  if (isstackEmpty(s))
  {
    printf("Stack Underflow\n");
    return -1;
  }
  int temp = s->indices[s->top--];
  return temp;
}