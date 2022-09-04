#include <stdio.h>
#include <stdlib.h>
#include "dlinkedList.h"

int main() {
  List __list;
  List *list = &__list;
  list->first = NULL;
  list->last = NULL;

  print(list);
  insert(list, 1, 0);
  insert(list, 2, 0);
  insert(list, 3, 0);
  insert(list, 4, 0);
  print(list);
  removeNode(list, list->first);
  print(list);

  return 0;
}
