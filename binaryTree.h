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

int max(int, int);

void insert(btree *root, int data);
node* insertNode(node* parent, int data);

node* createNode(int data);

bool search(btree* root, int data);
bool searchNode(node* node, int data);

int findMin(btree* tree);
int findMax(btree* tree);

void print(btree *tree);
void printNode(node *node);

int getHeight(btree *tree);
int getHeightNode(node *node);

// Travessias por profundidade:
// Pre-Ordem (PLR)
// Em Ordem  (LPR)
// Pos Ordem (LRP)

void preOrder(node *parent);
void inOrder(node *parent);
void postOrder(node *parent);
