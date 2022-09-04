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
      node->next = list->first;
      list->first = node;
    } else {
      list->last->next = node;
      list->last = node;
    }
  }

  list->size++;
}


void removeNode(List *list, Node* nodeToRemove) {
  if(!nodeToRemove)
    return;

  Node* prevNode = NULL;
  Node* node = list->first;
  
  if(nodeToRemove != node) {
    //rotina para encontrar o nó que antecede o nó a ser removido
    while(node->next) {
      if(node->next == nodeToRemove){
        prevNode = node;
        break;
      }
      node = node->next;
    }

    if(nodeToRemove->next) {
      prevNode->next = nodeToRemove->next;
    } else {
      prevNode->next = NULL;
      list->last = prevNode;
    } 
  } else {
    if(nodeToRemove->next) {
      list->first = nodeToRemove->next;
    } else {
      list->first = NULL;
      list->last = NULL;
    }
  }

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