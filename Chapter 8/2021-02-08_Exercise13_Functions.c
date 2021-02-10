#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int i, myArray[10] = {3, 4654, 765, 2, 21, -3, 534, 3, 1, 0};
    void sort (bool flag, int n, int array[]);

    // Before sorting
    for (i = 0; i < 10; ++i){
        printf("%i ", myArray[i]);
    }
    printf("\n");

    sort(0, 10, myArray);

    // After sorting
    for (i = 0; i < 10; ++i){
        printf("%i ", myArray[i]);
    }
    printf("\n");    

    return 0;
}

void sort (bool flag, int n, int array[])
{
    int temp, i, j;

    if (flag){
        for (i = 0; i < n - 1; ++i){
            for (j = i + 1; j < n; ++j){
                if (array[i] > array[j]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    else {
        for (i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                 if (array[i] < array[j]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }               
            }
        }
    }
}