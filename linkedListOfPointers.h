#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"


typedef struct Node {
  bnode *value;
  struct Node *next;
} Node;

typedef struct List {
  Node *first, *last;
  int size;
} List;

List* createList() {
  List* list = (List*)malloc(sizeof(List));
  list->first=NULL;
  list->last=NULL;
  list->size=0;
  return list;
}

Node* createListNode(List* list, bnode* value) {
  Node *node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

void listInsert(List *list, bnode* value, int insertAtStart){
  Node *node = createListNode(list, value);

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


void listRemoveNode(List *list, Node* nodeToRemove) {
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

void removeList(List *list) {
  Node *node, *next;
  node = list->first;
  while(node) {
    next = node->next;
    listRemoveNode(list, node);
    node = next;
  }
}

//Queue specific
bnode* dequeue(List *list) {
  if(!list->first)
    return 0;
  bnode* item = list->first->value;
  //printf("dequeued: %d\n", item->data);
  listRemoveNode(list, list->first);
  return item;
}

void enqueue(List *list, bnode* value) {
  //printf("enqueued: %d\n", value->data);
  listInsert(list, value, 0);
}