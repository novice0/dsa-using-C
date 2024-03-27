#include "bst-avl.h"

int nodeHeight(Node *p)
{
  int hl, hr;
  hl = (p && p->lchild) ? p->lchild->height : 0;
  hr = (p && p->rchild) ? p->rchild->height : 0;
  return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(Node *p)
{
  int hl, hr;
  hl = (p && p->lchild) ? p->lchild->height : 0;
  hr = (p && p->rchild) ? p->rchild->height : 0;
  return hl - hr;
}

Node *LLRotation(Node *p)
{
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = p;
  p->lchild = plr;
  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);

  if (AVL == p)
  {
    AVL = pl;
  }

  return pl;
}

Node *LRRotation(Node *p)
{
  Node *pl = p->lchild;
  Node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;
  plr->lchild = pl;
  plr->rchild = p;

  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);
  plr->height = nodeHeight(plr);

  if (AVL == p)
    AVL = plr;
  return plr;
}

Node *RRRotation(Node *p)
{
  Node *pr = p->rchild;
  Node *prl = pr->lchild;

  pr->lchild = p;
  p->rchild = prl;
  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);

  if (AVL == p)
  {
    AVL = pr;
  }

  return pr;
}

Node *RLRotation(Node *p)
{
  Node *pr = p->rchild;
  Node *prl = pr->lchild;

  pr->lchild = prl->rchild;
  p->rchild = prl->lchild;
  prl->lchild = p;
  prl->rchild = pr;

  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);
  prl->height = nodeHeight(prl);

  if (AVL == p)
  {
    AVL = prl;
  }
  return prl;
}

// Functions given in the assignment
Node *insertNode(Node *p, char *expr)
{
  Node *t = NULL;
  if (!p)
  {
    t = (Node *)malloc(sizeof(Node));
    if (t)
    {
      t->height = 1; // Height of leaf is considered to be 1 in this code.
      t->lchild = t->rchild = NULL;
      t->name = (char *)malloc(50 * sizeof(char));
      t->name = expr;
      return t;
    }
  }
  if (strcmp(expr, p->name) > 0)
  {
    p->rchild = insertNode(p->rchild, expr);
  }
  else
    p->lchild = insertNode(p->lchild, expr);

  p->height = nodeHeight(p);

  if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) // LL Rotation case
    return LLRotation(p);
  else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1) // LR Rotation case
    return LRRotation(p);
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1) // RR Rotation case
    return RRRotation(p);
  else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1) // RL Rotation case
    return RLRotation(p);

  return p;
}

Node *removeNode(Node *p, char *expr)
{
  Node *temp, *q;
  temp = p;
  while (temp)
  {
    if (expr > temp->name)
    {
      q = temp;
      temp = temp->rchild;
    }
    else if (expr < temp->name)
    {
      q = temp;
      temp = temp->lchild;
    }
    else
    {
      if (q->lchild == temp) // R-Rotations for deletion
        q->lchild = NULL;
      if (balanceFactor(q) == -2 && balanceFactor(q->rchild) == -1)
        return RRRotation(q);
      else if (balanceFactor(q) == -2 && balanceFactor(q->rchild) == 1)
        return RLRotation(q);
      else if (balanceFactor(q) == -2 && balanceFactor(q->rchild) == 0)
      {
        if (nodeHeight(q->rchild->lchild) > nodeHeight(q->rchild->rchild))
          return RRRotation(q);
        else
          return RLRotation(q);
      }
      else // L-Rotations for deletion
      {
        q->rchild = NULL;
        if (balanceFactor(q) == 2 && balanceFactor(q->lchild) == 1)
          return LLRotation(q);
        else if (balanceFactor(q) == 2 && balanceFactor(q->lchild) == -1)
          return LRRotation(q);
        else if (balanceFactor(q) == 2 && balanceFactor(q->lchild) == 0)
        {
          if (nodeHeight(q->lchild->rchild) > nodeHeight(q->lchild->lchild))
            return LLRotation(q);
          else
            return LRRotation(q);
        }
      }
    }
  }
  return NULL;
}

void preorder(Node *p)
{
  if (!p)
    return;
  printf("--%s--\n", p->name);
  preorder(p->lchild);
  preorder(p->rchild);
}

void destroyTree(Node *p)
{
  if (!p)
    return;
  destroyTree(p->lchild);
  destroyTree(p->rchild);
  free(p);
}

//---MENU---
/*void menu()
{
  int mode;
  char *iname;
  char *dname;
  char opt;
  iname = (char *)malloc(50 * sizeof(char));
  dname = (char *)malloc(50 * sizeof(char));
  printf("1: Insert a Node\n");
  printf("2: Remove a node\n");
  printf("3: Preorder Traversal of the BST AVL Tree\n");
  printf("4: Destroy the whole tree!\n");
  printf("5: Exit program!\n");
  printf("Select one of the above given modes: ");
  scanf("%d", &mode);
  switch (mode)
  {
  case 1:
    printf("You are about to insert a node\n");
    printf("Enter the name of the student: ");
    scanf("%s", iname);
    AVL = insertNode(AVL, iname);
    menu();
    break;
  case 2:
    printf("You are about to delete a node\n");
    printf("Enter the name of the student: ");
    scanf("%s", dname);
    AVL = removeNode(AVL, dname);
    menu();
    break;
  case 3:
    printf("Display the AVL Tree in Preorder Traversal\n");
    preorder(AVL);
    menu();
    break;
  case 4:
    printf("Are you sure you want to destroy the whole tree!! [Press 'Y' for yes, any other key for no]:\n ");
    scanf("%c", &opt);
    if (opt == 'Y' || opt == 'y')
      destroyTree(AVL);
    menu();
    break;
  case 5:
    printf("Exiting program\n");
    break;
  default:
    printf("Pls enter a valid mode\n");
    menu();
    break;
  }
}*/