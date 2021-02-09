#include <stdio.h>

int main ( void ) {
	
	float list[10], x, aveg = 0.0;
	int i;
	
	printf("Type 10 floating points you'd like to average out\n");
	
	for (i = 0; i < 10; ++i){
		scanf( "%f", &x);
		list[i] = x;
	}
	
	for (i = 0; i < 10; ++i){
		aveg += list[i];
	}
	
	aveg /= 10.0;

	printf("%f", aveg);
	
	return 0;
}
