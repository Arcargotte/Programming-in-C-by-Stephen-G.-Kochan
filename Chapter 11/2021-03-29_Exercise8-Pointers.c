/*
 * Write a function called sort3 to sort three integers into ascending order. (This
 * function is not to be implemented with arrays.)
 */

#include <stdio.h>

void sort3 (int *a, int *b, int *c)
{
    void swamp (int *x, int *y);

    if (*a < *b)
        swamp(a, b);
    else if (*a < *c)
        swamp (a, c);

    if (*b < *c)
        swamp(b, c);
}

void swamp (int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main (void)
{
    int max = 3, mean = 546, min = 455;

    printf("max: %i, mean: %i, min: %i\n", max, mean, min);

    sort3(&max, &mean, &min);

    printf("max: %i, mean: %i, min: %i\n", max, mean, min);

    return 0;
}