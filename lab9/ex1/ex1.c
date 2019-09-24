/* ENGGEN131 (2019) - Lab 9 (1st - 4th October, 2019)
   EXERCISE ONE - Da Vinci Code

   Draw something spectacular!
*/
#include <stdio.h>
#include <stdlib.h>
#include "LibBMP.h"

int r() {
	return rand() % 255;
}

int main(void)
{
	int width, height, i;
	int border = 5;
	int filled = 1;

	LoadBMPFile("blank.bmp", &width, &height);

	//DrawCircle(int row, int col, int radius, int red, int green, int blue)
	for (int j = width/2; j > 0; j=j-5){
		if (filled){
			DrawCircle(height/2, width/2, j, r(), r(), r());
		}else{
			FillCircle(height/2, width/2, j, r(), r(), r());
		}
		filled = !filled;
		
	}
	
	// Draw the border
	for (border = width/2; border > 5 ; border=border-5){
		for (i = border; i < width - border; i++){
			DrawPixel(border, i, r(), r(), r());
			DrawPixel(height - border, i, r(), r(), r());
		}
		for (i = border; i < height - border; i++){
			DrawPixel(i, border,r(), r(), r());
			DrawPixel(i, width - border,r(), r(), r());
		}
	}
	

	SaveBMPFile("output.bmp", width, height);

	return 0;
}

