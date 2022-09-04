CC = gcc
ARGS = -g

all: list btree

list: linkedList.c list.c
	$(CC) $(ARGS) linkedList.c list.c -o list.out
	./list.out

dlist: dlinkedList.c dlist.c
	$(CC) $(ARGS) dlinkedList.c dlist.c -o dlist.out
	./dlist.out

btree: binaryTree.c binaryTree.h btree.c
	$(CC) $(ARGS) binaryTree.c btree.c -o btree.out
	./btree.out