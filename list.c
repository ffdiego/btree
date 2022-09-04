#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main() {
  List __list;
  List *list = &__list;
  enqueue(list, 1);
  enqueue(list, 2);
  enqueue(list, 3);
  enqueue(list, 4);

  print(list);
  printf("%d\n", dequeue(list));
  print(list);
  removeList(list);

  return 0;
}
