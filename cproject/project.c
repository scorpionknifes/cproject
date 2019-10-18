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
	int i, j, result = -1;
	// Nested loop to find all prime number less than maximum.
	for (i = 2; i < maximum; i++)
	{
		for (j = 2; j <= i; j++)
		{
			if (i % j == 0)
			{
				// Break loop if number is not prime
				break;
			}
		}
		// If number is a prime number set as result.
		if (i == j)
		{
			result = i;
		}
	}
	return result;
}

/* Advertise - Scrolling Ads
	Rotate Character array one position to the left and the left most 
	character wrap-arount and join end of string.

    Args:
        words: a char array (pointer) of letters to rotate

	Examples:
		Advertise("Discount today only!") = "iscount today only!D" 
		Advertise("Hurry, hurry, hurry...") = "urry, hurry, hurry...H" 
		Advertise("Good luck!") = "ood luck!G"

*/
void Advertise(char *words)
{
	int i, n = strlen(words);

	// Setup temporary variable = the first value of char.
	char temp = words[0];

	// Loop through every char in array and move index of everything char back one
	for (i = 0; i < n - 1; i++)
	{
		words[i] = words[i + 1];
	}
	// Set value of last char value in array as temp value.
	words[n - 1] = temp;
}

/* Unique Bid Auction
	Calculate the winning bid in a unique bid auction. The Lowest unique bids that have been made 
	is the winning bid

	Args:
		values: a int array (pointer) of values
		length: length of the array values

	Return: 
		int - Lowest winning bid or -1 if no bid is found

	Examples:
		WinningBid({3, 7, 5, 6, 3, 4, 8, 4, 5, 8, 12, 11}, 12) = 6
		WinningBid({6, 17, 6, 6, 6, 6, 12, 12, 17, 10000}, 10) = 10000
		WinningBid({5, 4, 3, 2, 1}, 5) = 1
*/
int WinningBid(int *values, int length)
{
	int i, j, k, repeated, value = 0;

	// Loop through every element in the array.
	for (i = 0; i < length; i++)
	{
		// Set boolean repeat to false.
		repeated = 0;
		// If the element in array is not equal to zero loop through all the values after the element.
		if (values[i] != 0)
		{
			for (j = i + 1; j < length; j++)
			{
				// If element is repeated set the element repeated to 0 and make the boolean repeated to true.
				if (values[i] == values[j])
				{
					values[j] = 0;
					repeated = 1;
				}
			}
			// If boolean repeated is true set element checked to 0.
			if (repeated)
			{
				values[i] = 0;
			}
		}
	}

	// Find the lowest value inside the unique bids array
	for (k = 0; k < length; k++)
	{
		if ((values[k] < value && values[k] != 0) || value == 0)
		{
			value = values[k];
		}
	}

	// If the no lowest unique bid is found return -1 or else return lowest unique bid.
	return value == 0 ? -1 : value;
}

/* Box Designer
	Produce an ASCII mock-up of what the boxes will look like. The boxes will be rectangular,
	with the given width and height. A box will simply be represented as a rectangle where the 
	asterisk character (‘*’) is used to denote the edges. In addition, the exact center of the 
	box must be denoted using the character ‘X’.

	Args:
		design: char array for ASCII mock-up of box (pointer)
		width: width of the box
		height: height of the box

	Examples:
		BoxDesign(box1, 12, 5) =
			************
			*          *
			*    XX    *
			*          *
			************
		BoxDesign(box2, 15, 15) =
			***************
			*             *
			*             *
			*             *
			*             *
			*             *
			*             *
			*      X      *
			*             *
			*             *
			*             *
			*             *
			*             *
			*             *
			***************
		BoxDesign(box3, 4, 4) =
			****
			*XX*
			*XX*
			**** 
*/
void BoxDesign(char *design, int width, int height)
{
	int j, i = 0, temp;

	// Check if height is 0 is height is 0 draw nothing.
	if (height > 0)
	{
		// Draw first line of the box.
		for (i = 0; i < width; i++)
		{
			design[i] = '*';
		}
	}
	// If height is creater than 1
	if (height > 1)
	{
		// Draw Box using two '*' to indicate the sides of the boxes
		for (j = 0; j < height - 2; j++)
		{
			// Add a new line and draw first '*'.
			design[i++] = '\n';
			design[i++] = '*';
			// Use loop to add spaces between 2 '*'.
			temp = i;
			for (; i < temp + width - 2; i++)
			{
				design[i] = ' ';
			}
			// Draw ending '*' on the line if width is greater than 1.
			if (width > 1)
			{
				design[i++] = '*';
			}
		}
	}
	// Add newline and Draw bottom line of the box using a loop.
	temp = i;
	design[i++] = '\n';
	if (height > 1)
	{
		for (; i <= temp + width; i++)
		{
			design[i] = '*';
		}
	}
	// If the width and height is greater than 2 draw X into the center of the box.
	if (width > 2 && height > 2)
	{
		// Draw one X if width and height is an odd number in the center
		if (width % 2 == 1 && height % 2 == 1)
		{
			design[(width * height) / 2 + height / 2] = 'X';
		}
		// Draw two Xs if height is an odd number and width is even in the center
		else if (height % 2 == 1)
		{
			design[(width * height) / 2 + height / 2 - 1] = 'X';
			design[(width * height) / 2 + height / 2] = 'X';
		}
		// Draw two Xs if width is an odd number and height is even in the center
		else if (width % 2 == 1)
		{
			design[(width * height) / 2 + height / 2 - width / 2 - 2] = 'X';
			design[(width * height) / 2 + height / 2 + width / 2] = 'X';
		}
		// Draw four Xs if width and height is even in the center
		else
		{
			design[(width * height) / 2 + height / 2 + width / 2] = 'X';
			design[(width * height) / 2 + height / 2 + width / 2 - 1] = 'X';
			design[(width * height) / 2 + height / 2 - width / 2 - 1] = 'X';
			design[(width * height) / 2 + height / 2 - width / 2 - 2] = 'X';
		}
	}
	// Add Space to the end of the char array to perfect the number of character in char array.
	design[i++] = '\n';
}

/* Worker Routes
	function takes just one input, a 2D array of integers (10 rows and 10 columns) which represents 
	the layout of the warehouse floor. Every element in the 2D array will be equal to 0. The value 1 
	will appear exactly once and represents the location of the worker. The value 2 will appear exactly 
	once and represents the location of the box. move the worker horizontally then move the worker 
	vertically until reach box. The route that calculated is indicated by setting all array 
	elements on the route to the value 3.

	Args:
		warehouse: 2D array of the warehouse 
			with 1 representing worker
			with 2 representing box

	Examples:
		0000000000
		0000000000
		0000000000
		0000000000
		0013333000
		0000003000
		0000002000
		0000000000
		0000000000
		0000000000 

*/
void WorkerRoute(int warehouse[10][10])
{
	// ox, oy is worker original position
	// x1, y1 is position of worker
	// x2, y2 is position of box
	int i, j, ox = 0, oy = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	// Nested loop to find the location of worker and box
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (warehouse[i][j] == 1)
			{
				x1 = i;
				y1 = j;
				ox = i;
				oy = j;
			}
			if (warehouse[i][j] == 2)
			{
				x2 = i;
				y2 = j;
			}
		}
	}
	// Loop and move toward the horizontal postion and set route to 3
	for (; y1 != y2; y1 < y2 ? y1++ : y1--)
	{
		warehouse[x1][y1] = 3;
	}
	// Loop and move toward the vertical postion and set route to 3
	for (; x1 != x2; x1 < x2 ? x1++ : x1--)
	{
		warehouse[x1][y1] = 3;
	}
	// Set original position back to 1 as it was replaced by loop.
	warehouse[ox][oy] = 1;
}

/* One worker, many boxes and targets
	Use wasd to move worker. There are multiple boxes and targets in the warehouse. The objective is to move all boxes onto the 
	target and the worker on a target to complete the game (return 1). For the worker to move a box the direction of the movement 
	must have a space. For the worker to move the direction also must be a space. When a box goes on target or player goes on a 
	target they change to Box_on_target or Worker_on_target.

	Variables that define numbers to corresponding item.
		#define SPACE 0
		#define WALL 1
		#define TARGET 2
		#define BOX 3
		#define BOX_ON_TARGET 4
		#define WORKER 5
		#define WORKER_ON_TARGET 6

	Args:
		warehouse: 2D array of the warehouse 

	Return: 
		int: 0 if objective is not meet, 1 if objective meet (complete game)

	Examples:
		##########
		###   ####
		#*XO  ####
		### O*####
		#*##O ####
		# # * ####
		#O OOO*###
		#*  *  ###
		##########
		########## 

*/
int MakeMove(int warehouse[10][10], char move)
{
	int i, j, wx = 0, wy = 0, mx = 0, my = 0, finish = 0, t = 0;
	// Nested loop to find position of Worker or Worker_on_target
	// also find the number of Boxes defined as t
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (warehouse[i][j] == WORKER || warehouse[i][j] == WORKER_ON_TARGET)
			{
				wx = i;
				wy = j;
			}
			// Find number of Boxes
			if (warehouse[i][j] == BOX)
			{
				t++;
			}
		}
	}

	// Switch to set multipler of worker movement direction based on wasd
	switch (move)
	{
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

	// Check if the place at the direction of the worker is a space
	if (warehouse[wx + mx][wy + my] == SPACE)
	{
		// Move Player to that space and set the original position of player back to a space or a target if worker was on a target.
		warehouse[wx + mx][wy + my] = WORKER;
		warehouse[wx][wy] = (warehouse[wx][wy] == WORKER_ON_TARGET) ? TARGET : SPACE;
	}
	// Check if a box is at the direction of the worker is moving
	else if (warehouse[wx + mx][wy + my] == BOX || warehouse[wx + mx][wy + my] == BOX_ON_TARGET)
	{
		// Check if there is space or target for the box to be moved
		if (warehouse[wx + mx * 2][wy + my * 2] == TARGET || warehouse[wx + mx * 2][wy + my * 2] == SPACE)
		{
			// If the box is moving to a Target and the box was already on the target check for finishing condition
			if (warehouse[wx + mx * 2][wy + my * 2] == TARGET && warehouse[wx + mx][wy + my] == BOX_ON_TARGET)
			{
				// if the number of boxes is equal to 1 or less the object is met.
				finish = (t <= 1);
			}
			// Move the Box by
			// Set Box position to worker or if the box was on target to worker to on target
			warehouse[wx + mx][wy + my] = (warehouse[wx + mx][wy + my] == BOX_ON_TARGET) ? WORKER_ON_TARGET : WORKER;
			// Move Box to the direction pushed if it was pushed onto a target set box onto target
			warehouse[wx + mx * 2][wy + my * 2] = (warehouse[wx + mx * 2][wy + my * 2] == TARGET) ? BOX_ON_TARGET : BOX;
			// set the original position of player back to a space or a target if worker was on a target.
			warehouse[wx][wy] = (warehouse[wx][wy] == WORKER_ON_TARGET) ? TARGET : SPACE;
		}
	}
	// Check if the player is moving onto a Target
	else if (warehouse[wx + mx][wy + my] == TARGET)
	{
		// Set worker as on target
		warehouse[wx + mx][wy + my] = WORKER_ON_TARGET;
		// If number of boxes are zero set objective as complete (finish = true)
		finish = (t == 0);
		// Set original postion of worker back to a space or a target.
		warehouse[wx][wy] = (warehouse[wx][wy] == WORKER_ON_TARGET) ? TARGET : SPACE;
	}
	return finish;
}
