/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << Include your information here - name, user name, ID number >> */

#include "project.h"

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int result = (minuteB - minuteA)*60+secondB-secondA;
	return result > 0? result : (result*-1);
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WarehouseAddress(int maximum)
{
	int i, j, result;
	for (i=2; i<maximum; i++){
		for (j=2; j<=i; j++){
			if (i%j==0){
				break;
			}
		}
		if (i==j){
			result = i;
		}
	}
	return result;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void Advertise(char *words)
{
	int i,n=strlen(words);
	char temp = words[0];
    for(i=0;i<n-1;i++){
        words[i]=words[i+1];
    }
    words[n-1]=temp;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WinningBid(int *values, int length)
{
	for (int i = 1; i < n; i++) { 
		if (arr[i] == arr[i - 1]) {             
			int j = i; 
			while (j < n && arr[j] <= arr[j - 1]) {           
				arr[j] = arr[j] + 1; 
				j++; 
			} 
		}
	}

}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height)
{
	width = height;
	design[0] = '-';
	design[1] = '9';
	design[2] = '9';
	design[3] = '9';
	design[4] = '9';
	design[5] = '\0';
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void WorkerRoute(int warehouse[10][10])
{
	warehouse[0][0] = -9999;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int MakeMove(int warehouse[10][10], char move)
{
	move = '0';
	warehouse[0][0] = warehouse[0][0];
	return 0;
}

