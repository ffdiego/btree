#pragma once
#include <stdlib.h>
#include <stdio.h>


typedef struct Node {
  int value;
  struct Node *next;
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

//Stack specific
int pop(List *list);
void push(List *list, int value);

//Queue specific
int dequeue(List *list);
void enqueue(List *list, int value);