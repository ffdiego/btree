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

int findMin(btree* tree);
int findMax(btree* tree);

void print(btree *tree);
void printNode(bnode *node);

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