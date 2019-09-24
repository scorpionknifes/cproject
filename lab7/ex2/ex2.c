/* ENGGEN131 (2019) - Lab 7 (17th - 20th September, 2019)
   EXERCISE TWO
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	//setup variables
	int large, small, items, numLarge, numSmall, numScrap;

	//get user input
	printf("Enter capacity of large container: ");
	scanf("%d", &large);
	printf("Enter capacity of small container: ");
	scanf("%d", &small);
	printf("Enter number of items: ");
	scanf("%d", &items);

	//calculate num
	numLarge = items/large;
	numSmall = (items-numLarge*large)/small;
	numScrap = items-large*numLarge-small*numSmall;

	//print results
	printf("Allocated:\n - Large: %d\n - Small: %d\n - Scrap: %d\n", numLarge, numSmall, numScrap);










	return 0;
}
