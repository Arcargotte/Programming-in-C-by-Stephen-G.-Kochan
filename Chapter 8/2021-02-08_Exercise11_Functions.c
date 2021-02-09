#include <stdio.h>

int arraySum (int n, int array[])
{
	int index, total = 0;
	
	for (index = 0; index < n; ++index){
		total += array[index];
	}
	
	return total;
}

int main (void)
{	
	int n;
	
	printf("Array length: ");
	scanf("%i", &n);
	
	int myArray[n];
	int i;
	
	printf("Numbers: ");
	for (i = 0; i < n; ++i){
		scanf("%i", &myArray[i]);
	}
	
	//Print elements in the array
//	
//	for (i = 0; i < n; ++i){
//		printf("%i ", myArray[i]);
//	}
//	
	//
	
	int arraySum (int n, int array[]);
	
	printf("%i", arraySum(n, myArray));
	
	return 0;
}
