/*
 * A doubly linked list is a list in which each entry contains a pointer to the preceding
 * entry in the list as well as a pointer to the next entry in the list. Define the appropriate 
 * structure definition for a doubly linked list entry and then write a small program that 
 * implements a small doubly linked list and prints out the elements of the list.
 */

#include <stdio.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

void printLinkedList (struct Node *entry)
{
    for (int i = 1; entry; i++) {
        printf("n%i: %i\n", i, entry->value);
        //printf("next: %i, prior: %i\n", entry->next->value, entry->prev->value);
        entry = entry->next;
    }
}

int main (void)
{
    struct Node n1, n2, n3, n4;
    struct Node head = {NULL, &n1, NULL};

    n1.value = 100;
    n1.next = &n2;
    n1.prev = NULL;

    n2.value = 200;
    n2.next = &n3;
    n2.prev = &n1;

    n3.value = 300;
    n3.next = &n4;
    n3.prev = &n2;

    n4.value = 400;
    n4.next = NULL;
    n4.prev = &n3;

    printLinkedList(&n1);

    return 0;
}