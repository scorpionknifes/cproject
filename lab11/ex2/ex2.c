#define _CRT_SECURE_NO_WARNINGS

/* ENGGEN131 - 2019 - Lab 11 */
/* Decreasing values */

#include <stdio.h>

#define MAX_VALUES 1000

// This program prompts the user to enter a series of integer values, terminated by the
// value -1.  It then generates an output file which contains all entered values, space
// separated, sorted in decreasing order
int main(void)
{
	// Some variables (that you might find useful) have been declared for you:
	int values[MAX_VALUES] = {0};
	int numValues = 0;
	int value = 0;
	FILE *fp;

	// Open the output file for writing
	fp = fopen("output.txt", "w");

	// Read all input values from the user, until the terminating -1
	printf("Enter positive integers (-1 to end): ");
	scanf("%d", &value);
	while (value != -1)
	{
		values[numValues] = value;
		scanf("%d", &value);
		numValues++;
	}

	// Sort the values into decreasing order (see the Lab Preparation exercises)
	int a;
	for (int i = 0; i < numValues; i++)
	{
		for (int j = i + 1; j < numValues; j++)
		{
			if (values[i] < values[j])
			{
				a = values[i];
				values[i] = values[j];
				values[j] = a;
			}
		}
	}

	// Write the values to file (and close the file using fclose(fp))
	for (int i = 0; i < numValues; i++)
	{
		fprintf(fp, "%d ", values[i]);
	}
	fclose(fp);

	return 0;
}
