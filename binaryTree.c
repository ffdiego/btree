#include "binaryTree.h"

//definir estrutura de arvore pai dos nós

btree* createTree() {
  btree* tree = malloc(sizeof(tree));
  return tree;
}

void insert(btree *tree, int data) {
  if(!tree->root) {
    tree->root = createNode(data);
  } else if (data <= tree->root->data) {
    tree->root->left = insertNode(tree->root->left, data, false);
  } else {
    tree->root->right = insertNode(tree->root->right, data, true);
  }
}

node* insertNode(node* parent, int data, bool right) {
  if(!parent) {
    parent = createNode(data);
  } else if (data <= parent->data) {
    parent->left = createNode(data);
  } else {
    parent->right = createNode(data);
  }
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