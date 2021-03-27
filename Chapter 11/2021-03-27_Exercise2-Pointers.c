/*
 * Write a function called insertEntry to insert a new entry into a linked list. Have
 * the procedure take as arguments a pointer to the list entry to be inserted (of type
 * struct entry as defined in this chapter), and a pointer to an element in the list
 * after which the new entry is to be inserted.
 */

#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

void insertEntry (struct entry *newEntry, struct entry *priorEntry)
{
    newEntry->next = priorEntry->next;
    priorEntry->next = newEntry;
}

void printLinkedList (struct entry *firstEntry)
{
    for (int i = 1; firstEntry != NULL; i++) {
        printf("n%i: %i\n", i, firstEntry->value);
        firstEntry = firstEntry->next;
    }
}

int main (void)
{
    struct entry n1, n2, n3, nm;

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = NULL;

    nm.value = 150;
    nm.next = NULL;

    insertEntry (&nm, &n1);
    printLinkedList(&n1);

    return 0;
}