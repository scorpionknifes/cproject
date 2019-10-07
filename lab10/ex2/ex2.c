#define _CRT_SECURE_NO_WARNINGS

/* ENGGEN131 (2019) - Lab 10 (8th - 11th October, 2019)
   EXERCISE TWO - Triangles
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LibBMP.h"

typedef struct {
	double x;
	double y;
} Point;

// You must implement Steps 4 and 5 of the algorithm below
int main(void)
{
	Point a, b, c, d;
	int i, numPoints, pick;
	int width, height;

	srand((unsigned int)time(NULL));

	LoadBMPFile("blank.bmp", &width, &height);

	/* STEP 1: Initialise the positions of points A, B and C and plot these points */
	a.x = 1;
	a.y = width / 2;
	b.x = height - 2;
	b.y = 1;
	c.x = height - 2;
	c.y = width - 2;
	// Plot points A, B and C:
	DrawPixel((int)a.x, (int)a.y, 255, 0, 0);
	DrawPixel((int)b.x, (int)b.y, 255, 0, 0);
	DrawPixel((int)c.x, (int)c.y, 255, 0, 0);

	/* STEP 2: Initialise point D at some random location and plot this point */
	d.x = (double)(rand() % height);
	d.y = (double)(rand() % width);
	// Plot point D:
	DrawPixel((int)d.x, (int)d.y, 0, 255, 0);

	/* STEP 3: Read the number of points to plot */
	printf("Enter number of points: ");
	scanf("%d", &numPoints);



	/*********************************************************/
	/* STEP 4 and STEP 5: YOU MUST COMPLETE THESE TWO STEPS */
	/*********************************************************/

	/* Pick one of points A, B or C at random */

	/* Calculate the mid-point between the last point plotted and this random point */

	/* Repeat as many times as specified by the user */

	for (i = 0; i<numPoints; i++){
		Point e;
		//select random point
		switch (rand() % 3){
			case 0: e=a; break;
			case 1: e=b; break;
			case 2: e=c; break;
		}
		d.x = (e.x +d.x)/2;
		d.y = (e.y +d.y)/2;
		DrawPixel((int)d.x, (int)d.y, 255, 0, 0);
	}

	SaveBMPFile("output.bmp", width, height);

	return 0;
}

