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
  insert(tree, 42);

  print(tree);
  printf("Altura:%d\n", getHeight(tree));
  traverseTree(tree);
  printf("\nby level now:\n");
  traverseTreeByLevel(tree);
  removeNode(tree->root, 20);
  traverseTree(tree);
  return 0;
}