/* ENGGEN131 (2019) - Lab 9 (1st - 4th October, 2019)
   EXERCISE THREE - Sequence Generator
*/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

#define MAX_SEQUENCE_LENGTH 50

/* Function prototype declarations */
void InitSequence(int *seq, int sequenceLength);
int MoreSequences(int *seq, int valueRange);
void NextSequence(int *seq, int sequenceLength, int valueRange);
void PrintSequence(int *seq, int sequenceLength);

/* The main() function has been defined for you */
/* You must complete the four functions at the end of this source file */
int main(void)
{
	/* Array "sequence" stores the elements of the sequence */
	int sequence[MAX_SEQUENCE_LENGTH];
	int sequenceLength, valueRange;
	int count = 0;

	printf("Lab 9 - Exercise 3\n\n");
	printf("Enter sequence length: ");
	scanf("%d", &sequenceLength);
	printf("Enter value range: ");
	scanf("%d", &valueRange);

	/* Initialise the sequence */
	InitSequence(sequence, sequenceLength);

	/* Generate and print all sequences */
	while (MoreSequences(sequence, valueRange)) {
		PrintSequence(sequence, sequenceLength);
		NextSequence(sequence, sequenceLength, valueRange);
		count++;
	}

	printf("\nCompleted.  %d sequences generated.\n", count);

	return 0;
}

/*************************************************************
YOU MUST COMPLETE THE FUNCTION DEFINITIONS BELOW
*************************************************************/

void InitSequence(int *seq, int sequenceLength)
{
	// Define this function
}

int MoreSequences(int *seq, int valueRange)
{
	// Define this function
}

void NextSequence(int *seq, int sequenceLength, int valueRange)
{
	// Define this function
}

void PrintSequence(int *seq, int sequenceLength)
{
	// Define this function
}

