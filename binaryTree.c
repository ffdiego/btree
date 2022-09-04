#include "binaryTree.h"

//definir estrutura de arvore pai dos nós

btree* createTree() {
  btree* tree = malloc(sizeof(tree));
  return tree;
}

void insert(btree *tree, int data) {
  if(!tree->root) {
    tree->root = createNode(data);
  } else {
    insertNode(tree->root, data);
  }
}

node* insertNode(node* parent, int data) {
  if(!parent) {
    return createNode(data);
  } else if (data <= parent->data) {
    parent->left = insertNode(parent->left, data);
  } else {
    parent->right = insertNode(parent->right, data);
  }
  return parent;
}

bool search(btree* tree, int data) {
  return searchNode(tree->root, data);
}

bool searchNode(node* node, int data) {
  if(!node) return false;
  else if(node->data == data) return true;
  else if(data <= node->data) return searchNode(node->left, data);
  else return searchNode(node->right, data);
}

node* createNode(int data) {
  node *node = malloc(sizeof(node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

int findMin(btree* tree) {
  node* node = tree->root;
  if(!node) return -1;

  while(node && node->left) {
    node = node->left;
  }

  return node->data;
}

int findMax(btree* tree) {
  node* node = tree->root;
  if(!node) return -1;
  while(node && node->right) {
    node = node->right;
  }

  return node->data;
}