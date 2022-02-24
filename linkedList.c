//
// Created by William Wills on 2/16/22.
//

#include "linkedList.h"

//node initializer function, creates and allocates a new node
node *nodeInit(char data){

    //allocate a new node
    node *newNode = malloc(sizeof(node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

//overloaded node initializer function, creates and allocates a new node
node *nodeInit_loaded(char data, node *next, node *prev){

    //allocate a new node
    node *newNode = malloc(sizeof(node));

    newNode->data = data;
    newNode->next = next;
    newNode->prev = prev;

    return newNode;
}

//linked list type initializer function, creates and allocates a linked list
linkedList *linkedListInit(){

    linkedList *newLL = malloc(sizeof(linkedList));

    newLL->size = 0;
    newLL->head = nodeInit(HEAD_MARKER);

    //create tail node and point it at the head node
    newLL->tail = nodeInit_loaded('T', NULL, newLL->head);

    return newLL;
}

void appendNode(linkedList *currList, char data){

    currList->size++;
    node *newNode = nodeInit(data);

    if (currList->head->next == NULL){

        //append a new node to an empty linked list
        currList->head->next = newNode;
        currList->tail->prev = newNode;
        newNode->prev = currList->head;
    }else{

        //append a new node to a linked list append with at least one node
        node *currNode = currList->head;
        while (currNode->next != NULL){
            currNode = currNode->next;
        }

        currNode->next = newNode;
        newNode->prev = currNode;
        currList->tail->prev = newNode;
    }
}

void addNode(linkedList *currList, int index, char data){

    if (index > currList->size || index < 0){

        printf("ERROR: out_of_range\n");
    }else{

        currList->size++;

        if (index == 0){

            // adding a new node to the beginning of the list
            node *newNode = nodeInit_loaded(data, currList->head->next, NULL);
            currList->head->next->prev = newNode;
            currList->head->next = newNode;
        }else if (index == currList->size){

            // adding a new node to the end of the list
            node *newNode = nodeInit_loaded(data, NULL, currList->tail->prev);
            currList->tail->prev = newNode;
        }else{
            node *currNode = currList->head->next;

            for (int ii = 0; ii < index; ii++){
                currNode = currNode->next;
            }

            node *newNode = nodeInit_loaded(data, currNode->next, currNode);
            currNode->next->prev = newNode;
            currNode->next = newNode;
        }
    }
}

//returns the node at the given index
node *getNode(linkedList *listPtr, int index){

    node *currNode = listPtr->head->next;

    for (int ii = 0; ii < index; ii++){
        currNode = currNode->next;
    }

    return currNode;
}

//frees all memory associated with the linked list
void linkedListFree(linkedList *listToFree){

    //deallocate all nodes
    free(listToFree->tail);
    node *currNode = listToFree->head;
    node *nextNode = NULL;

    while (currNode != NULL){
        nextNode = currNode->next;
        free(currNode);
        currNode = nextNode;
    }

    //deallocate linkedList struct
    free(listToFree);
}

void listPrint(linkedList *listPtr){

    printf("the contents of the list are: ");

    node *currNode = listPtr->head;
    for (int ii = 0; ii < 5; ii++){
        currNode = currNode->next;
        printf("%c, ", currNode->data);
    }

    printf("end_of_list\n");
}

void listReversePrint(linkedList *listPtr){

    printf("the contents of the list in reverse are: ");

    node *currNode = listPtr->tail;
    for (int ii = 0; ii < 5; ii++){
        currNode = currNode->prev;
        printf("%c, ", currNode->data);
    }

    printf("start_of_list\n");
}