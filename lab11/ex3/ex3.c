/*
ENGGEN131 Lab 11 - Exercise Three
Generate an ASCII histogram using data of exam scores read from file.

As described in the lab document, you may find it useful to define a function
called PrintXs() which takes one input and simply prints that many 'X' characters
in a single line.  The prototype declaration for this function is provided
below, just in case you decide to implement it!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Prototype declaration for PrintXs function - this will be useful to define!
void PrintXs(int howMany);

int main(void)
{
	FILE *fp;
	int buckets[11] = {0};

	printf("\nWelcome to Lab 11 - Exercise Two\n\n");

	// Open the input file for reading
	fp = fopen("small_input.txt", "r");















	// Close the input file
	fclose(fp);

	return 0;
}

