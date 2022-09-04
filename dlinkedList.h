#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
} Node;

typedef struct List {
  Node *first, *last;
  int size;
} List;


Node* createNode(List* list, int value);
void insert(List *list, int value, int insertAtStart);
void removeNode(List *list, Node *node);
void removeList(List *list);
void print(List *list);
