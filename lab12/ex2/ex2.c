#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ENGGEN131 - 2019 - Lab 12 */
/* Exercise 2 */
/* You need to complete the definition of the ConvertToBinary() function */
void ConvertToBinary(int n)
{
	if (n != 0){
		ConvertToBinary(n/2);
		printf("%d", n%2);
	}
	return;
}

int main(void)
{
	int input;

	printf("Lab 12 - Recursive decimal to binary\n");

	printf("Enter the decimal number to convert: ");
	scanf("%d", &input);

	printf("%d in binary is: ", input);
	ConvertToBinary(input);

	printf("\n");

	return 0;
}

