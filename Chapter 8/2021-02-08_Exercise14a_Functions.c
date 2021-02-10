#include <stdio.h>

int n = 12;

int isPrime (int n)
{
    int k = n + 1;
	int primes[k];
	int i, j;
	
    for (i = 0; i < k; i++){
        primes[i] = 0;
    }

	for (i = 2; i < k; i++){	
		if (primes[i] == 0){
             for (j = 2; i * j < k; j++){
                primes[i * j] = 1;           
            }
		}
	}
	
	if (primes[n] == 0){
        printf("True");
		return 1;
	}
	else {
        printf("False");
		return 0;		
	}
}

int main (void)
{	
	isPrime(n);
	
	return 0;
}