#include <stdio.h>

int n, myArray[];
int arraySum (int n, int array[]);

int main (void)
{	
    printf("Number of elements: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++){
        scanf("%i", &myArray[i]);
    }
    printf("%i", arraySum(n, myArray));
	
	return 0;
}

int arraySum (int n, int array[])
{
	int index, total = 0;
	
	for (index = 0; index < n; ++index){
		total += array[index];
	}
	
	return total;
}