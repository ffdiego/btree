#include "binaryTree.h"

//definir estrutura de arvore pai dos nós

btree* insert(btree *root, int data) {
  if(!root) {
    root = createNode(data);
    return root;
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;  
}

bool search(btree* root, int data) {
  if(!root) return false;
  else if(root->data == data) return true;
  else if(data <= root->data) return search(root->left, data);
  else return search(root->right, data);
}

btree* createNode(int data) {
  btree *node = (btree*)malloc(sizeof(btree));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}