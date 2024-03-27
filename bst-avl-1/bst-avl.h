#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---To create an AVL---
//---The BST is created on the basis of the dictionary order of names

//---What functions are required in AVL?---
//---1.To insert a new node
//---2.To check the balance factor after inserting for an imbalance
//---3.To calculate the balance factor we require the height of the node which are inturn updated during the insert function.
//---4.Finally we require the functions to perform rotations and balance the BST.

//---Note: My code does not use a pointer to the parent node for each of the nodes of the tree.

typedef struct Node
{
  struct Node *lchild;
  char *name;
  int height; // To generate the balance factor
  struct Node *rchild;
} Node;

Node *AVL = NULL; // Root is already initialised in this code. While using menu driven programs, it is advisable to use a variable with global scope.

// Additional helper functions
int nodeHeight(Node *p);
int balanceFactor(Node *p);
Node *LLRotation(Node *p);
Node *LRRotation(Node *p);
Node *RRRotation(Node *p);
Node *RLRotation(Node *p);

// Functions given in the assignment
Node *insertNode(Node *p, char *expr); // Recursive function to insert names.
Node *removeNode(Node *p, char *expr); // Function to delete a name.
void preorder(Node *p);                // Recursive Preorder to display the name, Balance Factor of each node.
void destroyTree(Node *p);             // Destroy the whole of AVL Tree

//---MENU---
void menu();