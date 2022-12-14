#include "linkedList.h"
//fazer lista duplamente encadeada
//refatorar criação de nó

Node* createNode(List* list, int value) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
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

  printf("removing node: %d\n", nodeToRemove->value);
  free(nodeToRemove);
  list->size--;
}

void removeList(List *list) {
  Node *node, *next;
  node = list->first;
  while(node) {
    next = node->next;
    removeNode(list, node);
    node = next;
  }
}

void print(List *list) {
  printf(":: Size: %d ", list->size);
  if(list->first)
    printf("| First: %d ", list->first->value);
  if(list->last)
    printf("| Last: %d ", list->last->value);
  printf("::\n");

  Node *node = list->first;
  while(node) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n\n");
}

//Stack specific
int pop(List *list) {
  if(!list->last)
    return 0;
  int item = list->last->value;
  removeNode(list, list->last);
  return item;
}

void push(List *list, int value) {
  insert(list, value, 0);
}

//Queue specific
int dequeue(List *list) {
  if(!list->first)
    return 0;
  int item = list->first->value;
  removeNode(list, list->first);
  return item;
}

void enqueue(List *list, int value) {
  insert(list, value, 1);
}