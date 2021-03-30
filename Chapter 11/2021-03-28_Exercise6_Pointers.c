/*
 * Develop insertEntry and removeEntry functions for a doubly linked list that are
 * similar in function to those developed in previous exercises for a singly linked list.
 * Why can your removeEntry function now take as its argument a direct pointer to
 * the entry to be removed from the list?
 */

#include <stdio.h>

struct entry
{
    int value;
    struct entry *prev;
    struct entry *next;
};

void insertEntry (struct entry *newEntry, struct entry *prevEntry)
{
    newEntry->next = prevEntry->next;    
    newEntry->prev = prevEntry;
    prevEntry->next = newEntry;
}

void removeEntry (struct entry *entry)
{
    if (!entry->next) {
        entry->prev->next = NULL;
    } else {
        entry->prev->next = entry->next;
        entry->next->prev = entry->prev;       
    }
}

void printLinkedList (struct entry *node)
{
    for (int i = 1; node; i++) {
        printf("n%i: %i\n", i, node->value);
        node = node->next;
    }
}

int main (void)
{
    struct entry n1, n2, n3, n4, n5;
    struct entry firstEntry = {NULL, (struct entry *) 0, &n1};
    struct entry *head = &n1;

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

    n5.value = 500;

    insertEntry(&n5, &n4);
    printLinkedList(head);
    removeEntry(&n5);
    printLinkedList(head);

    return 0;
}