/*
 * Write a pointer version of the sort function from Chapter 8,“Working with
 * Functions.” Be certain that pointers are exclusively used by the function, including
 * index variables in the loops.
 */

#include <stdio.h>

void sort (int *a, int n)
{
    int *const arrayEnd = a + n;
    int temp, *i = a, *j;

    for (; i < arrayEnd; ++i)
        for (j = a; j < arrayEnd; ++j)
            if ( *i > *j ) {
                temp = *j;
                *j = *i;
                *i = temp;
            }
}

int main (void)
{
    int i;
    int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 };
    void sort (int a[], int n);

    printf ("The array before the sort:\n");
    
    for ( i = 0; i < 16; ++i )
        printf ("%i ", array[i]);

    sort (array, 16);

    printf ("\n\nThe array after the sort:\n");

    for ( i = 0; i < 16; ++i )
        printf ("%i ", array[i]);

    printf ("\n");

    return 0;
}