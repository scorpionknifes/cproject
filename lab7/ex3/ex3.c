/* ENGGEN131 (2019) - Lab 7 (17th - 20th September, 2019)
   EXERCISE THREE
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>   // This is needed for using sqrt() and pow()

int main(void)
{
    //get user input
    int n;
    printf("Which fibonacci number? ");
    scanf("%d", &n);

    //calculate and print result
    printf("Fibonacci number %d is: %.0f\n", n, (pow(1+sqrt(5),n)-pow(1-sqrt(5),n))/(pow(2,n)*sqrt(5)));
	return 0;
}
