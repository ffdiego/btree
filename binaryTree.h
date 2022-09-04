#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef enum { false, true } bool;

typedef struct bnode {
  int data;
  struct bnode *left;
  struct bnode *right;
} bnode;

typedef struct btree {
  struct bnode *root;
} btree;

btree* createTree();

int max(int, int);

void insert(btree *root, int data);
bnode* insertNode(bnode* parent, int data);

bnode* createNode(int data);

bool search(btree* root, int data);
bool searchNode(bnode* node, int data);


bnode* findMin(bnode* node);
bnode* findMax(bnode* node);


void print(btree *tree);
void printNode(bnode *node);
bnode* removeNode(bnode *node, int value);
void removeTree(btree *tree);

int getHeight(btree *tree);
int getHeightNode(bnode *node);

// Travessias por profundidade:
// Pre-Ordem (PLR)
// Em Ordem  (LPR)
// Pos Ordem (LRP)
void traverseTree(btree *tree);

void preOrder(bnode *parent);
void inOrder(bnode *parent);
void postOrder(bnode *parent);

void traverseTreeByLevel(btree *tree);
void levelOrder(bnode *node);