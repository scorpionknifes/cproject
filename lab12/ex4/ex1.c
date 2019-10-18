#include <stdio.h>
#include "LibBMP.h"

void DrawSquare(double x, double y, double size)
{
	StartAt((int)(x - size/2), (int)(y - size/2));

	TurnRight(90);
	Forward(size);
	TurnRight(90);
	Forward(size);
	TurnRight(90);
	Forward(size);
	TurnRight(90);
	Forward(size);
}

int main(void)
{
	int width, height;

	LoadBMPFile("blank.bmp", &width, &height);

	DrawSquare(300, 300, 200);

	SaveBMPFile("output.bmp", width, height);

	return 0;
}




