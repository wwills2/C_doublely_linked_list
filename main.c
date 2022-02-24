#include <stdio.h>
#include <string.h>
#include "linkedList.h"

int main() {
    printf("Hello, World!\n");
    printf("Zan Wills' C Linked List\n\n");

    printf("testing linked list initializer: linkedList *linkedListInit()\n");
    {
        linkedList *myLinkedList = linkedListInit();

        if (myLinkedList->head->data != HEAD_MARKER || myLinkedList->tail->prev != myLinkedList->head) {
            printf("\tlinked list init failed\n");
        } else {
            printf("\tpass\n");
        }

        linkedListFree(myLinkedList);
    }

    printf("testing appending a node to the end of the linked list: void appendNode(...)\n");
    {
        linkedList *myLinkedList = linkedListInit();
        appendNode(myLinkedList, 'A');

        if (myLinkedList->head->next->data != 'A') {
            printf("\tfail\n");
        } else {
            printf("\tpass\n");
        }

        linkedListFree(myLinkedList);
    }

    printf("testing appending 5 nodes to the end of the linked list: void appendNode(...)\n");
    {
        linkedList *myLinkedList = linkedListInit();
        appendNode(myLinkedList, 'A');
        appendNode(myLinkedList, 'B');
        appendNode(myLinkedList, 'C');
        appendNode(myLinkedList, 'D');
        appendNode(myLinkedList, 'E');

        node *curr = myLinkedList->head;

        char LLdata[5];
        for (int ii = 0; ii < 5; ii++) {
            curr = curr->next;
            LLdata[ii] = curr->data;
        }

        char correctData[5] = "ABCDE";

        if (strcmp(LLdata, correctData)) {
            printf("\tpass\n");
        } else {
            printf("\tfail\n");
        }

        linkedListFree(myLinkedList);
    }

    printf("testing void *getNode(linkedList *listPtr, int index)\n");
    {
        linkedList *myLinkedList = linkedListInit();
        appendNode(myLinkedList, 'A');
        appendNode(myLinkedList, 'B');
        appendNode(myLinkedList, 'C');
        appendNode(myLinkedList, 'D');
        appendNode(myLinkedList, 'E');

        if (getNode(myLinkedList, 0)->data != 'A'){
            printf("\tfailed to get first node data, returned %c\n", getNode(myLinkedList, 0)->data);
        } else if (getNode(myLinkedList, 2)->data != 'C'){
            printf("\tfailed to get middle node data, returned %c\n", getNode(myLinkedList, 2)->data);
        } else if (getNode(myLinkedList, 4)->data != 'E'){
            printf("\tfailed to get middle node data, returned %c\n", getNode(myLinkedList, 4)->data);
        } else {
            printf("\tpass\n");
        }
    }

    printf("testing void listPrint(linkedList *listPtr)");
    {
        linkedList *myLinkedList = linkedListInit();
        appendNode(myLinkedList, 'A');
        appendNode(myLinkedList, 'B');
        appendNode(myLinkedList, 'C');
        appendNode(myLinkedList, 'D');
        appendNode(myLinkedList, 'E');

        listPrint(myLinkedList);

        linkedListFree(myLinkedList);
    }

    printf("testing void listReversePrint(linkedList *listPtr)");
    {
        linkedList *myLinkedList = linkedListInit();
        appendNode(myLinkedList, 'A');
        appendNode(myLinkedList, 'B');
        appendNode(myLinkedList, 'C');
        appendNode(myLinkedList, 'D');
        appendNode(myLinkedList, 'E');

        listReversePrint(myLinkedList);

        linkedListFree(myLinkedList);
    }

    return 0;
}

