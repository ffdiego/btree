#pragma once
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct btree {
  int data;
  struct btree *left;
  struct btree *right;
} btree;

btree* insert(btree *root, int data);

bool search(btree* root, int data);

btree* createNode(int data);