#include "binaryTree.h"
#include "linkedListOfPointers.h"

int max(int a, int b) {
  if(a>=b) return a;
  return b;
}

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

bnode* insertNode(bnode* parent, int data) {
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

bool searchNode(bnode* node, int data) {
  if(!node) return false;
  else if(node->data == data) return true;
  else if(data <= node->data) return searchNode(node->left, data);
  else return searchNode(node->right, data);
}

bnode* createNode(int data) {
  bnode *node = malloc(sizeof(node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

int findMin(btree* tree) {
  bnode* node = tree->root;
  if(!node) return -1;

  while(node && node->left) {
    node = node->left;
  }

  return node->data;
}

int findMax(btree* tree) {
  bnode* node = tree->root;
  if(!node) return -1;
  while(node && node->right) {
    node = node->right;
  }

  return node->data;
}

void print(btree *tree) {
  if(tree->root)
    printNode(tree->root);
}

void printNode(bnode *node) {
  if(node) {
    printNode(node->left);
    printf("%d \n", node->data);
    printNode(node->right);
  }
}

int getHeight(btree *tree) {
  if(!tree->root) return 0;
  return getHeightNode(tree->root);
}

int getHeightNode(bnode *node) {
  if(!node) return -1;

  int leftHeight, rightHeight;
  leftHeight = getHeightNode(node->left);
  rightHeight = getHeightNode(node->right);
  return max(leftHeight, rightHeight) + 1;
}

void traverseTree(btree *tree) {
  if(!tree->root) return;
  printf("\nPre-Order:\n");
  preOrder(tree->root);
  printf("\nIn-Order:\n");
  inOrder(tree->root);
  printf("\nPost-Order:\n");
  postOrder(tree->root);
  printf("\n");
}

void preOrder(bnode *node) {
  if(!node) return;
  printf("%d ", node->data);
  preOrder(node->left);
  preOrder(node->right);
}

void inOrder(bnode *node) {
  if(!node) return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}

void postOrder(bnode *node) {
  if(!node) return;
  postOrder(node->left);
  postOrder(node->right);
  printf("%d ", node->data);
}

void traverseTreeByLevel(btree *tree) {

}

void levelOrder(bnode *node) {
  if(!node) return;
  List *q = createList();
  enqueue(q, node);
  while(q->size > 0) {
    bnode *current = q->first;
    printf("%d ", current->data);
    if(current->left) enqueue(q, current->left);
    if(current->right) enqueue(q, current->right);
    dequeue(q); 
  }
}