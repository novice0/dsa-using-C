#include "bst-bintree-2.c"

int main()
{
  bst t;
  init_bst(&t);

  insert_bst(&t, 100);
  insert_bst(&t, 20);
  insert_bst(&t, 300);
  insert_bst(&t, 40);
  insert_bst(&t, 10);
  insert_bst(&t, 60);
  insert_bst(&t, 50);
  insert_bst(&t, 70);
  insert_bst(&t, 30);

  non_rec_inorder(&t);
  non_rec_preorder(&t);
  non_rec_postorder(&t);

  level_wise(&t);

  if (isComplete(&t) == 1)
    printf("Our Tree is Complete\n");
  else
    printf("Our Tree is Incomplete\n");
  return 0;
}
