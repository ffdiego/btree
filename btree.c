#include <stdio.h>
#include "binaryTree.h"

int main() {
  btree *tree = createTree();

  insert(tree, 20);
  insert(tree, 7);
  insert(tree, 52);
  insert(tree, 99);
  insert(tree, 12);
  insert(tree, 32);
  insert(tree, 40);
  int min = findMin(tree);
  int max = findMax(tree);
  
  printf("%d and %d\n", min, max);

  print(tree);
  return 0;
}