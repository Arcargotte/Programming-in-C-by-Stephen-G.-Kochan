#include <stdio.h>

int main (void) 
{
	long int x_to_the_n(int x, int n);
	
	printf("%li", x_to_the_n(2,6));
	
	return 0;	
}

long int x_to_the_n(int x, int n)
{
	if ( n == 1 )
		return x;
	else
		return x * x_to_the_n(x, n - 1);
}
