/*
 * Write a function called removeEntry to remove an entry from a linked list.The
 * sole argument to the procedure should be a pointer to the list. Have the function
 * remove the entry after the one pointed to by the argument. (Why can’t you
 * remove the entry pointed to by the argument?) You need to use the special structure 
 * you set up in exercise 3 to handle the special case of removing the first element from 
 * the list
 */

#include <stdio.h>

struct entry 
{
    int value;
    struct entry *next;
};

void removeEntry (struct entry *entry)
{
    /*
     * Remove entry after given entry. i.e.: removeEntry(n1) removes n2
     */

    entry->next = entry->next->next; 
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
    struct entry head, n1, n2, n3, n4;
    
    head.next = &n1;

    n1.value = 100;
    n1.next = &n2;
    
    n2.value = 200;
    n2.next = &n3;

    n3.value = 300;
    n3.next = &n4;

    n4.value = 400;
    n4.next = NULL;

    printLinkedList(&head);
    printf("\n");
    
    removeEntry(&head);

    printLinkedList(&head);

    return 0;
}

