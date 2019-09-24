/* ENGGEN131 (2019) - Lab 8 (24th - 27th September, 2019)
   EXERCISE TWO
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
	int bits[MAX_SIZE];
	int numBits;
	int number;
	// You should complete the program by adding code here.
	// You may like to start by defining some additional variables.
	printf("Enter a number: ");
	scanf("%d", &number);

	while (number > 0){
		bits[numBits] = number%2;
		numBits++;
		number = number/2;
	}

	for (int i = numBits-1; i >= 0; i--){
		printf("%d", bits[i]);
	}
	printf("\n");
	return 0;
}

