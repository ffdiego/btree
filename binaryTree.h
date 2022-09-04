#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef enum { false, true } bool;

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

typedef struct btree {
  struct node *root;
} btree;

btree* createTree();

void insert(btree *root, int data);
node* insertNode(node* parent, int data);

node* createNode(int data);

bool search(btree* root, int data);
bool searchNode(node* node, int data);

int findMin(btree* tree);
int findMax(btree* tree);