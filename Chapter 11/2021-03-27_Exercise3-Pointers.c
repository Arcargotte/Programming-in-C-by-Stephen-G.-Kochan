/* 
 * The function developed in exercise 2 only inserts an element after an existing element in the 
 * list, thereby preventing you from inserting a new entry at the front of
 * the list. How can you use this same function and yet overcome this problem?
 * (Hint: Think about setting up a special structure to point to the beginning of the list.)
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
    for (int i = 0; firstEntry != NULL; i++) {
        if (i != 0) {
            printf("n%i: %i\n", i, firstEntry->value);
            firstEntry = firstEntry->next;            
        }   
        else 
            firstEntry = firstEntry->next;                
    }
}


int main (void)
{
    struct entry n1, n2, n3, nm;
    struct entry head = {0, &n1}; // <- Special structure that is the head of the linked list

    n1.value = 100;
    n1.next = &n2;

    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = NULL;

    nm.value = 150;
    nm.next = NULL;

    insertEntry (&nm, &head); // <- If you insert an entry to swamp it for the head, it becomes the new head
    printLinkedList(&head);

    return 0;
}