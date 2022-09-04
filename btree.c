#include <stdio.h>
#include "binaryTree.h"

int main() {
  btree *tree = createTree();

  insert(tree, 15);
  insert(tree, 10);
  insert(tree, 20);

  search(tree, 15);
  search(tree, 20);
  search(tree, 17);

  return 0;
}