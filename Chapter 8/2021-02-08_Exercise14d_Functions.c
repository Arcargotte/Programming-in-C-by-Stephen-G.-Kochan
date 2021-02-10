#include <stdio.h>

int flag;
int myArray[];
int n;

int main (void)
{
    int i;
    void sort (int flag, int n, int array[]);

    printf("Number of elements in the array: ");
    scanf("%i", &n);
    for (i = 0; i < n; i++){
        scanf("%i", &myArray[i]);
    }
    
    printf("Press any botton for ascending order. Press 0 for descending order: ");
    scanf("%i", &flag);

    // Before sorting
    for (i = 0; i < n; ++i){
        printf("%3i ", myArray[i]);
    }
    printf("\n");

    sort(flag, n, myArray);

    // After sorting
    for (i = 0; i < n; ++i){
        printf("%3i ", myArray[i]);
    }
    printf("\n");    

    return 0;
}

void sort (int flag, int n, int array[])
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