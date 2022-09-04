#include "dlinkedList.h"

Node* createNode(List* list, int value) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void insert(List *list, int value, int insertAtStart){
  Node *node = createNode(list, value);

  //Testa se a lista está vazia
  if(!list->first) {
    list->first = node;
    list->last = node;
  } 

  //Procedimento pra uma lista não vazia
  else {
    if(insertAtStart) {
      list->first->prev = node;
      node->next = list->first;
      list->first = node;
    } else {
      list->last->next = node;
      node->prev = list->last;
      list->last = node;
    }
  }

  list->size++;
}


void removeNode(List *list, Node* nodeToRemove) {
  if(!nodeToRemove)
    return;
  
  if(nodeToRemove->prev) nodeToRemove->prev->next = nodeToRemove->next;
  if(nodeToRemove->next) nodeToRemove->next->prev = nodeToRemove->prev;

  if(nodeToRemove == list->first) list->first = nodeToRemove->next;
  if(nodeToRemove == list->last) list->last = nodeToRemove->prev;

  free(nodeToRemove);
  list->size--;
} 

void print(List *list) {
  printf(":: Size: %d ", list->size);
  if(list->first)
    printf("| First: %d ", list->first->value);
  if(list->last)
    printf("| Last: %d ", list->last->value);
  printf("::\n");

  Node *node;

  node = list->first;
  while(node) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
  node = list->last;
  while(node) {
    printf("%d ", node->value);
    node = node->prev;
  }

  printf("\n\n");
}