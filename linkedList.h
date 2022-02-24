//
// Created by zan on 2/6/22.
//

#ifndef C_LINKED_LIST_LINKEDLIST_H
#define C_LINKED_LIST_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

#define HEAD_MARKER '@' //! Question: why did const char HEAD_MARKER = '@'; not work? gave a duplicate symbol error

//define node type for use in linked list
typedef struct node{
    char data;
    struct node *next;
    struct node *prev;
} node;

//define linkedList type
typedef struct linkedList{

    node *head;
    node *tail;
    int size;
} linkedList;

//node initializer function, creates and allocates a new node
node *nodeInit(char data);

//overloaded node initializer function, creates and allocates a new node
node *nodeInit_loaded(char data, node *next, node *prev);

//linked list type initializer function, creates and allocates a linked list
linkedList *linkedListInit();

//appends a node with the given data to the specified list
void appendNode(linkedList *currList, char data);

//adds a node to the linked list after the specified index
void addNode(linkedList *currList, int index, char data);

void removeNode(linkedList *listPtr, int index);
void setData (linkedList *listPtr, int index, char newData);
char getData (linkedList *listPtr, int index);

//returns the node at the given index of the list (the first user defined node is 0)
node *getNode(linkedList *listPtr, int index);

//frees all memory associated with the linked list
void linkedListFree(linkedList *listToFree);

//prints the contents of the list
void listPrint(linkedList *listPtr);

//prints the contents of the list in reverse
void listReversePrint(linkedList *listPtr);



#endif //C_LINKED_LIST_LINKEDLIST_H
