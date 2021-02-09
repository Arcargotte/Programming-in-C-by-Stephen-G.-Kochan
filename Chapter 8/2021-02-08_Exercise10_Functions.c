#include <stdio.h>

int isPrime (int n)
{
	int primes[n] = {0};
	int i, j;
	
	for (i = 2; i <= n; i++){	
		if (primes[i] == 0)
		for (j = 2; i * j <= n; j++){
			primes[i * j] = 1;
		}
	}
	
	
	if (primes[n] == 0){
		return 1;
	}
	else {
		return 0;		
	}

}

int main (void)
{
	int n = 6;
	
	isPrime(n);
	
	return 0;
}
