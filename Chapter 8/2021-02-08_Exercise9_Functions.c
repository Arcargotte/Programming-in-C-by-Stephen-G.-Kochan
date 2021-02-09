#include <stdio.h>

/* 
a function declaration must be in the global scope for
other to use it
*/

int gcd (int u, int v);
int lcm (int u, int v);

int lcm (int u, int v)
{
	int ans;
	
	ans = (u * v) / gcd(u, v);
	
	return ans;	
}

int gcd (int u, int v)
{
	int temp;
	
	while (v != 0) {
		
		temp = u % v;
		u = v;
		v = temp;
		
	}
	
	return u;
}

int main (void)
{
	int u, v;
	
	printf("u: ");
	scanf("%i", &u);
	printf("v: ");
	scanf("%i", &v);
	
	printf("The least common multiple of %i and %i is %i",
			u, v, lcm(u, v));
	
	return 0;
}
