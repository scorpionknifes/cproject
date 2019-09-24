/* ENGGEN131 (2019) - Lab 7 (17th - 20th September, 2019)
   EXERCISE ONE
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	//setup variables
	char currencySymbol;
	int numberOfWinners;
	int totalCashPrize;
	double sharedPrize;

	//get input from user
	printf("Enter currency symbol:   ");
	scanf("%c", &currencySymbol);
	printf("Enter cash total (in %c): ", currencySymbol);
	scanf("%d", &totalCashPrize);
	printf("Enter number of winners: ");
	scanf("%d", &numberOfWinners);

	//calculate shared prize
	sharedPrize = (double)totalCashPrize/numberOfWinners;

	//print results
	printf("Total prize per winner:  %c%.2f\n", currencySymbol, sharedPrize);
	return 0;
}
