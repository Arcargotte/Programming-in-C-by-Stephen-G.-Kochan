// Program to generate the first 15 Fibonacci numbers

#include <stdio.h>

int main (void)
{
	int fib_0 = 0, fib_1 = 1, current = 0, i;
	
	//printf("%i\n%i\n", fib_0, fib_1);
	
	for ( i = 0; i < 15; ++i){
		printf("%i\n", current);
		
		fib_0 = fib_1;
		fib_1 = current;
		current = fib_0 + fib_1;
	}

		
	return 0;
}
