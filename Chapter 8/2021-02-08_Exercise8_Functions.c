#include <stdio.h>

int main (void)
{
	long int x_to_the_n(int x, int n);
	double absoluteValue (double x);
	double squareRoot (double x);
	void quadraticSolver(int a, int b, int c);

	int a, b, c;
	
	printf("a?: ");
	scanf("%i", &a);
	printf("b?: ");
	scanf("%i", &b);
	printf("c?: ");
	scanf("%i", &c);

	quadraticSolver(a, b, c);
	
	return 0;
}

// Function to calculate x to the n

long int x_to_the_n(int x, int n)
{
	if ( n == 1 )
		return x;
	else
		return x * x_to_the_n(x, n - 1);
}

// Function to calculate the absolute value of a number

double absoluteValue (double x)
{
	if ( x < 0 )
		x = -x;
		
	return (x);
}

// Function to compute the square root of a number

double squareRoot (double x)
{
	const double epsilon = 1.00001;
	double guess = 1.0;
	
	do {
		guess = (x / guess + guess) / 2.0;
	} while (absoluteValue(guess * guess / x) >= epsilon); 

	return guess;	
}

// Function to calculate the roots of a quadratic equation

void quadraticSolver(int a, int b, int c)
{
	double x1, x2;
	
	if ((x_to_the_n(b, 2) - 4*a*c) < 0 )
		printf("No real roots\n");
	else{
		x1 = (-b + squareRoot((x_to_the_n(b, 2) - 4*a*c))) / (2 * a);
		x2 = (-b - squareRoot((x_to_the_n(b, 2) - 4*a*c))) / (2 * a);
		
		printf("x1: %.3lf, x2: %.3lf", x1, x2);
	}
}

