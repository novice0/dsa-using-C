#include "bst-avl.c"

int main()
{
  printf("Welcome to the program of BST AVL Trees\n");
  AVL = insertNode(AVL, "Chinmay");
  AVL = insertNode(AVL, "Munot");
  AVL = insertNode(AVL, "Ishan");
  AVL = insertNode(AVL, "Soham");

  preorder(AVL);
  printf("\n");

  AVL = removeNode(AVL, "Chinmay");

  preorder(AVL);
  printf("\n");

  destroyTree(AVL);

  preorder(AVL);

  // menu();
  return 0;
}

// To incorporate Menu() Function for the given program
// All other functions are implemented correctly!