/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* Copyright (c) 2019 ZHENK
   Written by Cheng-Zhen Yang */
/*
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
   OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "project.h"

/* TimeWorked - Clocking In, Clocking Out
	Calculates the length of the worker's shift by inputing two times.
	Each time (A & B) requires an input for minute and second.

    Args:
        minuteA: The minutes for time A.
        secondA: The seconds for time A.
		minuteB: The minutes for time B.
        secondB: The seconds for time B.

    Returns:
		int - length of a worker's shift in seconds.
        
	Examples:
		TimeWorked(1, 0, 2, 0) = 60.
		TimeWorked(55, 11, 42, 12) = 799.
		TimeWorked(33, 33, 33, 33) = 0.
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	// Calculate the time difference between time A & B in seconds.
	int result = (minuteB - minuteA) * 60 + secondB - secondA;

	// If results is negative convert to positive by multipling -1.
	return result > 0 ? result : (result * -1);
}

/* WarehouseAddress - Lucky Address
	Find the largest prime number less than the upper bound.

    Args:
        maximum: The upper bound.

    Returns:
		int - The largest prime number less than upper bound.
        
	Examples:
		WarehouseAddress(1000) = 997.
		WarehouseAddress(50) = 47.
		WarehouseAddress(104393) = 104383
*/
int WarehouseAddress(int maximum)
{
	int i, j, result;
	// Nested loop to find all prime number less than maximum.
	for (i = 2; i < maximum; i++){
		for (j = 2; j <= i; j++){
			if (i % j == 0){
				// Break loop if number is not prime
				break;
			}
		}
		// If number is a prime number set as result.
		if (i == j){
			result = i;
		}
	}
	return result;
}

/* Advertise - Scrolling Ads
	Find the largest prime number less than the upper bound.

    Args:
        args:

	Examples:

*/
void Advertise(char *words)
{
	int i, n = strlen(words);
	char temp = words[0];
	for (i = 0; i < n - 1; i++)
	{
		words[i] = words[i + 1];
	}
	words[n - 1] = temp;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WinningBid(int *values, int length)
{
	int freq[MAX_ARRAY_SIZE] = {[0 ... MAX_ARRAY_SIZE - 1] = -1};
	int i, j, count, winner = -1;
	for (i = 0; i < length; i++){
		count = 1;
		for (j = i + 1; j < length; j++){
			if (values[i] == values[j]){
				count++;
				freq[j] = 0;
			}
		}
		if (freq[i] != 0){
			freq[i] = count;
		}
	}
	for (i = 0; i < length; i++){
		if (freq[i] == 1 && (winner == -1 || values[i] < winner)){
			winner = values[i];
		}
	}
	return winner;
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height)
{
	int j,i=0, temp;
  if (height > 0){
    for (i = 0; i < width; i++){
      design[i] = '*';
    }
  }
  if (height > 1){
    for (j =0;  j < height-2; j++){
      design[i++] = '\n';
      design[i++] = '*';
      temp = i;
      for (; i< temp+width-2; i++){
        design[i] = ' ';
      }
      if (width > 1){
      design[i++] = '*';
      }
    }
  }
	temp = i;
	design[i++] = '\n';
  if (height > 1){
    for (; i <= temp+width; i++){
      design[i] = '*';
    }
  }
	
  if (width >2 && height >2){
    if (width%2==1 && height%2==1){
      design[(width*height)/2+ height/2] = 'X';
    }else if (height%2==1){
      design[(width*height)/2+ height/2-1] = 'X';
      design[(width*height)/2+ height/2] = 'X';
    }else if (width%2==1){
      design[(width*height)/2+ height/2-width/2-2] = 'X';
      design[(width*height)/2+ height/2+width/2] = 'X';
      
    }else{
      design[(width*height)/2+ height/2 +width/2] = 'X';
      design[(width*height)/2+ height/2+width/2-1] = 'X';
      design[(width*height)/2+ height/2-width/2-1] = 'X';
      design[(width*height)/2+ height/2-width/2-2] = 'X';
    }
  }
	design[i++] = '\n';
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void WorkerRoute(int warehouse[10][10])
{
	int i,j,ox,oy,x1,y1,x2,y2;
	for (i=0; i < 10; i++){
		for (j=0; j < 10; j++){
			if (warehouse[i][j]==1){
				x1 = i;
				y1 = j;
				ox = i;
				oy = j;
			}
			if (warehouse[i][j]==2){
				x2 = i;
				y2 = j;
			}
		}
	}
	for (; y1 != y2; y1<y2? y1++:y1--){
		warehouse[x1][y1] = 3;
	}
	for (;x1 != x2; x1<x2? x1++:x1--){
		warehouse[x1][y1] = 3;
	}
	warehouse[ox][oy] = 1;
	
}

/*
Your comment should go here � it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int MakeMove(int warehouse[10][10], char move)
{
	int i, j ,wx,wy, mx=0,my=0, finish=0, t=0;
	for (i=0; i < 10; i++){
		for (j=0; j < 10; j++){
			if (warehouse[i][j]==WORKER || warehouse[i][j]==WORKER_ON_TARGET){
				wx = i;
				wy = j;
			}
			if (warehouse[i][j]==BOX){
				t++;
			}
		}
	}
	switch (move){
		case 'w': 
		mx--;
		break;
		case 'a': 
		my--;
		break;
		case 's': 
		mx++;
		break;
		case 'd': 
		my++;
		break;
	}
	if (warehouse[wx+mx][wy+my] == SPACE){
		warehouse[wx+mx][wy+my] = WORKER;
		warehouse[wx][wy] = (warehouse[wx][wy]==WORKER_ON_TARGET)? TARGET:SPACE;
	}else if (warehouse[wx+mx][wy+my] == BOX || warehouse[wx+mx][wy+my] == BOX_ON_TARGET){
		if (warehouse[wx+mx*2][wy+my*2] == TARGET || warehouse[wx+mx*2][wy+my*2] == SPACE){
			if(warehouse[wx+mx*2][wy+my*2] == TARGET && warehouse[wx+mx][wy+my]==BOX_ON_TARGET){
				finish = (t<=1);
			}
			warehouse[wx+mx][wy+my] = (warehouse[wx+mx][wy+my]==BOX_ON_TARGET)? WORKER_ON_TARGET:WORKER;
			warehouse[wx+mx*2][wy+my*2] = (warehouse[wx+mx*2][wy+my*2] == TARGET)? BOX_ON_TARGET:BOX;
			warehouse[wx][wy] = (warehouse[wx][wy]==WORKER_ON_TARGET)? TARGET:SPACE;
		}
	}else if (warehouse[wx+mx][wy+my] == TARGET){
		warehouse[wx+mx][wy+my] = WORKER_ON_TARGET;
		finish = (t==0);
		warehouse[wx][wy] = SPACE;
	}
	return finish;
}
